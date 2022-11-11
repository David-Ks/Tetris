#include "BoardScript.hpp"

#include "../Settings.cpp"
#include "../Players/Player.hpp"
#include "../Figures/Figure.hpp"
#include "../../Utils/Objects/Tools.cpp"

#include <algorithm>
#include <vector>
#include <set>


void Scenario::BoardScript::start()
{
    board().addFigure();
    board().setGameOver(false);
}

void Scenario::BoardScript::update()
{
    if (board().getGameOver())
        return;

    IndexList fullLines = getFullLines();
    if (!fullLines.empty())
    {
        cleanLines(fullLines);
        board().dropNotActiveFigures(fullLines);
        User::player().addScore(fullLines.size());
    }

    board().addFigure();
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
    const static std::vector<char> fullLineExample(Settings::width, '#');
    IndexList fullLines;

    const auto lastDropedFigure = Utils::Objects::getlastItem(board().figures);
    if (!lastDropedFigure)
        return fullLines;

    ChangedLines changedLines = getChangedLines(lastDropedFigure);

    for (const auto &position : changedLines)
    {
        if (board().map[position] == fullLineExample)
        {
            fullLines.push_back(position);
        }
    }

    return fullLines;
}

void Scenario::BoardScript::cleanLines(const IndexList &fullLines)
{
    auto &figures = board().figures;
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