#include "StandardBoard.hpp"
#include <algorithm>
#include <set>
#include <iostream>

Map::StandardBoard::StandardBoard()
{
    map = map_t(Settings::height, std::vector<char>(Settings::weidth, 0));
    linesScore = new int[Settings::height - 3];
}

Map::StandardBoard::~StandardBoard() {}

void Map::StandardBoard::update()
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

void Map::StandardBoard::clean()
{
    for (auto &row : map)
    {
        std::fill(row.begin(), row.end(), 0);
    }
}

void Map::StandardBoard::lineCheck()
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

void Map::StandardBoard::lineClean(std::vector<int> fullLines)
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

    Game::player()->addScore(fullLines.size());
    dropNotActiveFigures(fullLines);
}

void Map::StandardBoard::dropNotActiveFigures(std::vector<int> fullLines)
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

void Map::StandardBoard::theEndOfGame()
{
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

void Map::StandardBoard::addFigure()
{
    if (!getNextFigure())
    {
        generateNextFigure();
    }

    Object::Figure *newFigure = getNextFigure();

    Position pos;
    pos.x = 0;
    pos.y = (Settings::weidth - 3) / 2; // Center

    newFigure->setPos(pos);

    if (figures.size() != 0)
    {
        Object::Figure *lastFigure = figures.back();

        for (auto &block : lastFigure->blocks)
        {
            linesScore[block->getPos().x + lastFigure->getPos().x]++;
        }
    }

    figures.push_back(newFigure);
    generateNextFigure();
}

Object::Figure *Map::StandardBoard::getNextFigure()
{
    return nextFigure;
}

void Map::StandardBoard::generateNextFigure()
{
    nextFigure = new Object::Figure;
}