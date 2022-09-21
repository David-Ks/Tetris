#include "StandardBoard.hpp"
#include <algorithm>
#include <set>
#include <iostream>

Map::StandardBoard::StandardBoard(Player *player) : Board(player)
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

            // Crush defender
            if (blockPos.x + figurePos.x >= Settings::height)
            {
                delete block;
                block = 0;
            }

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

void Map::StandardBoard::addFigure()
{
    Figure *newFigure = new Settings::CustomFigure;

    Position pos;
    pos.x = 0;
    pos.y = (Settings::weidth - 3) / 2; // Center

    newFigure->init();
    newFigure->setPos(pos);

    if (figures.size() != 0)
    {
        Figure *lastFigure = figures[figures.size() - 1];

        for (auto &block : lastFigure->blocks)
        {
            linesScore[block->getPos().x + lastFigure->getPos().x]++;
        }
    }

    figures.push_back(newFigure);
}

void Map::StandardBoard::lineCheck()
{
    std::vector<int> fullLines;
    std::set<int> blck; // blockListOptimaizer
    std::vector<char> vec(Settings::weidth, '#');

    for (auto &block : figures[figures.size() - 2]->blocks)
    {
        Position blockPos = block->getPos();
        Position figurePos = figures[figures.size() - 2]->getPos();

        blck.insert(figurePos.x + blockPos.x);

        if (figurePos.x + blockPos.x <= 4)
            setGameOver(true);
    }

    if (!gameOver)
    {
        for (auto &pos : blck)
        {
            if (map[pos] == vec)
            {
                fullLines.push_back(pos);
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

    player->setScore(fullLines.size());
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