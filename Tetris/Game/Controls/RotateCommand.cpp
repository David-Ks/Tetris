#include "RotateCommand.hpp"

#include <iostream>

bool Action::RotateCommand::isAvailable()
{
    map_t map = Map::board().map;
    Object::Figure *figure = Map::board().figures.back();
    
    if (!figure->isRotatable)
        return false;

    for (auto &block : figure->blocks)
    {
        if (!block)
            continue;

        Position blockPos = block->getPos();
        Position figurePos = figure->getPos();

        int rotateX = blockPos.y;
        int rotateY = getNewPos(blockPos.x);

        if (figure->isOwnBlock(rotateX + figurePos.x, rotateY + figurePos.y))
            continue;

        if (rotateX + figurePos.x < 0 ||
            rotateY + figurePos.y < 0 ||
            rotateY + figurePos.y >= Settings::weidth ||
            map[rotateX + figurePos.x][rotateY + figurePos.y])
            return false;
    }

    return true;
}

bool Action::RotateCommand::execute()
{
    Object::Figure *figure = Map::board().figures.back();
    
    for (auto &block : figure->blocks)
    {
        if (!block)
            continue;

        Position blockPos = block->getPos();
        Position figurePos = figure->getPos();
        Position newPos;

        newPos.x = blockPos.y;
        newPos.y = getNewPos(blockPos.x);

        block->setPos(newPos);
    }
    return true;
}

int Action::RotateCommand::getNewPos(int x)
{
    switch (x)
    {
    case 0:
        return 3;
    case 1:
        return 2;
    case 2:
        return 1;
    }
    return 0;
}