#include <algorithm>
#include <set>
#include <vector>

#include "Board.hpp"
#include "../Figures/Figure.hpp"
#include "../Players/Player.hpp"
#include "../../Utils/Objects/Tools.hpp"
#include "../Settings.hpp"

Board::Board() : gameOver(false), nextFigure(0)
{
    map = BoardMatrix(Settings::height, std::vector<char>(Settings::width, ' '));
    generateNextFigure();
}

void Board::update()
{
    clean();

    for (const auto &figure : figures)
    {
        if (!figure)
            continue;

        for (const auto &block : figure->blocks)
        {
            if (!block)
                continue;

            const Position blockPos = block->getPos();
            const Position figurePos = figure->getPos();

            map[blockPos.x + figurePos.x][blockPos.y + figurePos.y] = '#';
        }
    }
}

void Board::clean()
{
    for (auto &row : map)
    {
        std::fill(row.begin(), row.end(), ' ');
    }
}

void Board::dropNotActiveFigures(const IndexList &fullLines)
{
    const int start = *std::min_element(fullLines.begin(), fullLines.end());
    const int count = fullLines.size();

    for (const auto &figure : figures)
    {
        if (!figure)
            continue;

        for (const auto &block : figure->blocks)
        {
            if (!block)
                continue;

            Position blockPos = block->getPos();
            if (figure->getPos().x + blockPos.x <= start)
            {
                blockPos.x += count;
                block->setPos(blockPos);
            }
        }
    }
}

void Board::theEndOfGame()
{
    Utils::Objects::clear(figures);
    delete nextFigure;
    nextFigure = 0;
}

void Board::addFigure()
{
    if (!hasNextFigure())
    {
        generateNextFigure();
    }

    constexpr int centerY = (Settings::width - 3) / 2;
    constexpr Position figureStartPos {0, centerY};

    Utils::Objects::push(figures, getNextFigure(), figureStartPos);
    generateNextFigure();
}

Object::Figure *Board::getNextFigure() const
{
    return nextFigure;
}

bool Board::hasNextFigure() const
{
    if (nextFigure)
    {
        return true;
    }
    return false;
}

void Board::generateNextFigure()
{
    nextFigure = new Object::Figure;
}

bool Board::isGameOver() const
{
    return gameOver;
}

void Board::setGameOver(bool gameOver)
{
    this->gameOver = gameOver;
}

