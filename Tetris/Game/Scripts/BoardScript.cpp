#include "BoardScript.hpp"

#include "../Settings.cpp"
#include "../Players/Player.hpp"
#include "../Figures/Figure.hpp"
#include "../Utils/Objects/Tools.cpp"

#include <algorithm>
#include <vector>
#include <set>


void Scenario::BoardScript::start()
{
    Map::board().addFigure();
    Map::board().setGameOver(false);
}

void Scenario::BoardScript::update()
{
    if (Map::board().getGameOver())
        return;

    IndexList fullLines = getFullLines();
    if (!fullLines.empty())
    {
        cleanLines(fullLines);
        Map::board().dropNotActiveFigures(fullLines);
        User::player().addScore(fullLines.size());
    }

    Map::board().addFigure();
}

Scenario::BoardScript::ChangedLines Scenario::BoardScript::getChangedLines(const Object::Figure *lastDropedFigure)
{
    const Position lastDropedFigurePos = lastDropedFigure->getPos();

    Scenario::BoardScript::ChangedLines changedLines;
    for (auto &block : lastDropedFigure->blocks)
    {
        if (!block)
            continue;

        const Position blockPos = block->getPos();
        changedLines.insert(lastDropedFigurePos.x + blockPos.x);
    }

    return changedLines;
}

Scenario::BoardScript::IndexList Scenario::BoardScript::getFullLines()
{
    const static std::vector<char> fullLineExample(Settings::weidth, '#');
    IndexList fullLines;

    const auto lastDropedFigure = Utils::Objects::getlastItem(Map::board().figures);
    if (!lastDropedFigure)
        return fullLines;

    ChangedLines changedLines = getChangedLines(lastDropedFigure);

    for (const auto &position : changedLines)
    {
        if (Map::board().map[position] == fullLineExample)
        {
            fullLines.push_back(position);
        }
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
            Utils::Objects::del(figure);
        }
    }
}