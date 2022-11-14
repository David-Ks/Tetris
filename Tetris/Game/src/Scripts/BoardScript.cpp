#include "BoardScript.hpp"

#include "../Settings.hpp"
#include "../Players/Player.hpp"
#include "../Figures/Figure.hpp"
#include "../../Utils/Objects/Tools.hpp"

#include <algorithm>
#include <vector>
#include <set>

void BoardScript::start()
{
    board.addFigure();
    board.setGameOver(false);
}

void BoardScript::update()
{
    if (board.isGameOver())
        return;

    IndexList fullLines = getFullLines();
    if (!fullLines.empty())
    {
        cleanLines(fullLines);
        board.dropNotActiveFigures(fullLines);
        player.addScore(fullLines.size());
    }

    board.addFigure();
}

BoardScript::NoRepitList BoardScript::getChangedLines(const Object::Figure *lastDropedFigure)
{
    const Position lastDropedFigurePos = lastDropedFigure->getPos();
    
    NoRepitList changedLines;
    for (const auto &block : lastDropedFigure->blocks)
    {
        if (!block)
            continue;

        changedLines.insert(lastDropedFigurePos.x + block->getPos().x);
    }

    return changedLines;
}

BoardScript::IndexList BoardScript::getFullLines()
{
    const static std::vector<char> fullLineExample(Settings::width, '#');
    IndexList fullLines;

    const auto lastDropedFigure = Utils::Objects::getLastItem(board.figures);
    if (!lastDropedFigure)
        return fullLines;

   const NoRepitList changedLines = getChangedLines(lastDropedFigure);

    for (const auto &position : changedLines)
    {
        if (board.matrix[position] == fullLineExample)
        {
            fullLines.push_back(position);
        }
    }

    return fullLines;
}

void BoardScript::cleanLines(const IndexList &fullLines)
{
    for (auto &figure : board.figures)
    {
        if (!figure)
            continue;

        int deletedBlocksCount = 0;
        for (auto &block : figure->blocks)
        {
            if (!block)
            {
                ++deletedBlocksCount;
                continue;
            }

            if (isOnTheList(figure->getPos().x + block->getPos().x, fullLines))
            {
                delete block;
                block = 0;
            }
        }

        deleteFigureIfEmpty(deletedBlocksCount, figure);
    }
}

bool BoardScript::isOnTheList(int index, const IndexList &fullLines)
{
    if (std::find(fullLines.begin(), fullLines.end(), index) != fullLines.end())
    {
        return true;
    }
    return false;
}

void BoardScript::deleteFigureIfEmpty(int blocksCount, Object::Figure *&figure)
{
    if (blocksCount == figure->blocks.size())
    {
        Utils::Objects::del(figure);
    }
}