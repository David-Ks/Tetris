#include "Board.hpp"
#include "../Settings.cpp"
#include <algorithm>
#include <set>

Map::Board &Map::board()
{
    static Map::Board brd;
    return brd;
}

Map::Board::Board() : gameOver(false)
{
    map = map_t(Settings::height, std::vector<char>(Settings::weidth, 0));
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

void Map::Board::lineCheck()
{
    std::vector<int> fullLines;
    std::set<int> setBlocks;
    std::vector<char> vec(Settings::weidth, '#');

    for (auto &block : figures[figures.size() - 2]->blocks)
    {
        Position blockPos = block->getPos();
        Position figurePos = figures[figures.size() - 2]->getPos();

        setBlocks.insert(figurePos.x + blockPos.x);

        if (figurePos.x + blockPos.x <= 4)
            setGameOver(true);
    }

    if (!gameOver)
    {
        for (auto &position : setBlocks)
        {
            if (map[position] == vec)
            {
                fullLines.push_back(position);
            }
        }

        if (fullLines.size() != 0)
            lineClean(fullLines);
    }
    else
    {
        theEndOfGame();
    }
}

void Map::Board::lineClean(std::vector<int> fullLines)
{
    for (auto &figure : figures)
    {
        if (!figure)
            continue;

        int count = 0;
        for (auto &block : figure->blocks)
        {
            if (!block)
            {
                count++;
                continue;
            }

            if (std::find(fullLines.begin(), fullLines.end(),
                          figure->getPos().x + block->getPos().x) != fullLines.end())
            {
                delete block;
                block = 0;
            }
        }

        if (count == 4)
        {
            delete figure;
            figure = 0;
            continue;
        }
    }

    User::player().addScore(fullLines.size());
    dropNotActiveFigures(fullLines);
}

void Map::Board::dropNotActiveFigures(std::vector<int> fullLines)
{
    int min = *std::min_element(fullLines.begin(), fullLines.end());

    for (auto &figure : figures)
    {
        if (!figure)
            continue;

        for (auto &block : figure->blocks)
        {
            if (!block)
                continue;

            if (figure->getPos().x + block->getPos().x <= min)
            {
                Position newPos = block->getPos();
                newPos.x += fullLines.size();
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

Object::Figure *Map::Board::getNextFigure()
{
    return nextFigure;
}

void Map::Board::generateNextFigure()
{
    nextFigure = new Object::Figure;
}