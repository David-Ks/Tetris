#include <algorithm>
#include <set>
#include <vector>

#include "Board.hpp"
#include "../Figures/Figure.hpp"
#include "../Players/Player.cpp"

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

    for (auto &figure : figures)
    {
        if (!figure)
            continue;

        for (auto &block : figure->blocks)
        {
            if (!block)
                continue;

            Position blockPos = block->getPos();
            Position figurePos = figure->getPos();

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

    for (auto &figure : figures)
    {
        if (!figure)
            continue;

        for (auto &block : figure->blocks)
        {
            if (!block)
                continue;

            if (figure->getPos().x + block->getPos().x <= start)
            {
                Position newPos = block->getPos();
                newPos.x += count;
                block->setPos(newPos);
            }
        }
    }
}

void Map::Board::theEndOfGame()
{
    setGameOver(true);
    for (auto &figure : figures)
    {
        if (!figure)
            continue;
        for (auto &block : figure->blocks)
        {
            if (!block)
                continue;
            delete block;
            block = 0;
        }
        delete figure;
        figure = 0;
    }
    figures.clear();

    delete nextFigure;
    nextFigure = 0;
}

void Map::Board::addFigure()
{
    if (!getNextFigure())
        generateNextFigure();

    Object::Figure *newFigure = getNextFigure();
    
    Position newPosition;
    newPosition.x = 0;
    newPosition.y = (Settings::weidth - 3) / 2; // Center

    newFigure->setPos(newPosition);
    figures.push_back(newFigure);
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

