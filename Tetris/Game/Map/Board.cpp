#include <algorithm>
#include <set>
#include <vector>

#include "Board.hpp"
#include "../Figures/Figure.hpp"
#include "../Players/Player.cpp"
#include "../Utils/Objects/Tools.cpp"

Map::Board &Map::board()
{
    static Map::Board brd;
    return brd;
}

Map::Board::Board() : gameOver(false)
{
    map = MapMatrix(Settings::height, std::vector<char>(Settings::weidth, 0));
}

void Map::Board::update()
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

void Map::Board::clean()
{
    for (auto &row : map)
    {
        std::fill(row.begin(), row.end(), 0);
    }
}

void Map::Board::dropNotActiveFigures(const IndexList &fullLines)
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

void Map::Board::theEndOfGame()
{
    Utils::Objects::clear(figures);
    delete nextFigure;
    nextFigure = 0;
}

void Map::Board::addFigure()
{
    if (!getNextFigure())
        generateNextFigure();

    constexpr int centerY = (Settings::weidth - 3) / 2;
    constexpr Position figureStartPos {0, centerY};

    Utils::Objects::push(figures, getNextFigure(), figureStartPos);
    generateNextFigure();
}

Object::Figure *Map::Board::getNextFigure() const
{
    return nextFigure;
}

void Map::Board::generateNextFigure()
{
    nextFigure = new Object::Figure;
}

bool Map::Board::getGameOver() const
{
    return gameOver;
}

void Map::Board::setGameOver(bool gameOver)
{
    this->gameOver = gameOver;
}

