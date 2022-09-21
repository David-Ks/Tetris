#include "StandardBoard.hpp"
#include <algorithm>

Map::StandardBoard::StandardBoard(Player *player) : Board(player)
{
    map = map_t(Settings::height, std::vector<char>(Settings::weidth, 0));
    linesScore = new int[Settings::height];
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
    if (linesScore[0] + linesScore[1] != 0)
    {
        gameOver = true;
    }
    else
    {
        std::vector<int> fullLines;

        for (int i = 0; i < Settings::height; i++)
        {
            if (linesScore[i] == Settings::weidth)
            {
                fullLines.push_back(i);
                linesScore[i] = -1;
            }
        }
        specialQueueForIndexes(linesScore, Settings::height);

        player->setScore(fullLines.size()); // Add score

        if (fullLines.size() != 0)
            lineClean(fullLines);
    }
}

void Map::StandardBoard::lineClean(std::vector<int> fullLines)
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
            // int x = figure->getPos().x + block->getPos().x; Wrong answer!!!

            if (std::find(fullLines.begin(), fullLines.end(),
                          figure->getPos().x + block->getPos().x) != fullLines.end())
            {
                delete block;
                block = 0;
            }
        }

        for (auto &block : figure->blocks)
        {
            if (!block)
                continue;

            if (figure->getPos().x + block->getPos().x < min)
            {
                Position newPos = figure->getPos();
                newPos.x += fullLines.size();
                figure->setPos(newPos);
                break;
            }
        }
    }
}

void Map::StandardBoard::specialQueueForIndexes(int *arr, int size)
{
    bool flag = true;
    int j;

    for (int i = size; i >= 0; i--)
    {
        if (arr[i] != -1)
            continue;

        if (flag)
        {
            flag = false; // More speed
            j = i;
        }

        while (j >= 0 && arr[j] == -1)
            j--;

        if (j == -1)
            break;

        arr[i] = arr[j];
        arr[j] = -1;
    }

    for (int i = 0; arr[i] == -1; i++)
        arr[i] = 0;
}