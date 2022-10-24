#include "BoardScript.hpp"

#include "../Settings.cpp"
#include "../Players/Player.hpp"
#include "../Figures/Figure.hpp"

#include <algorithm>
#include <vector>
#include <set>

using IndexList = std::vector<int>;

void Scenario::BoardScript::start()
{
    Map::board().addFigure();
    Map::board().setGameOver(false);
}

void Scenario::BoardScript::update()
{
    Map::board().addFigure();

    IndexList fullLines = getFullLines();
    if (!fullLines.empty())
        cleanLines(fullLines);
}

IndexList Scenario::BoardScript::getFullLines()
{
    const static std::vector<char> fullLineExample(Settings::weidth, '#');

    IndexList fullLines;
    std::set<int> blockPoses;

    const auto &figures = Map::board().figures;

    for (auto &block : figures[figures.size() - 2]->blocks)
    {
        const Position blockPos = block->getPos();
        const Position figurePos = figures[figures.size() - 2]->getPos();
        blockPoses.insert(figurePos.x + blockPos.x);
    }

    if (!Map::board().getGameOver())
    {
        for (const auto &position : blockPoses)
        {
            if (Map::board().map[position] == fullLineExample)
            {
                fullLines.push_back(position);
            }
        }
    }
    else
    {
        Map::board().theEndOfGame();
    }

    return fullLines;
}

void Scenario::BoardScript::cleanLines(const IndexList &fullLines)
{
    auto &figures = Map::board().figures;
    for (auto &figure : figures)
    {
        if (!figure)
            continue;

        int deletedBlockcount = 0;
        for (auto &block : figure->blocks)
        {
            if (!block)
            {
                ++deletedBlockcount;
                continue;
            }

            if (std::find(fullLines.begin(), fullLines.end(),
                          figure->getPos().x + block->getPos().x) != fullLines.end())
            {
                delete block;
                block = 0;
            }
        }

        if (deletedBlockcount == figure->blocks.size())
        {
            delete figure;
            figure = 0;
        }
    }

    Map::board().dropNotActiveFigures(fullLines);
    User::player().addScore(fullLines.size());
}