#include "RotateCommand.hpp"

#include <iostream>

bool Action::Game::RotateCommand::isAvailable() const
{
    const MapMatrix map = Map::board().map;
    const Object::Figure *figure = Map::board().figures.back();

    if (!figure->isRotatable)
        return false;

    for (const auto &block : figure->blocks)
    {
        if (!block)
            continue;

        const Position figurePos = figure->getPos();
        const int rotateX = block->getPos().y;
        const int rotateY = getNewPos(block->getPos().x);

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

bool Action::Game::RotateCommand::execute()
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

int Action::Game::RotateCommand::getNewPos(int x) const
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