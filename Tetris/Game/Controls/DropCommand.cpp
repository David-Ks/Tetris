#include "DropCommand.hpp"

bool Action::DropCommand::isAvailable(map_t map)
{
    for (auto &block : figure->blocks)
    {
        if (!block)
            continue;

        Position blockPos = block->getPos();
        Position figurePos = figure->getPos();

        int PosX = figurePos.x + blockPos.x + 1;
        int PosY = figurePos.y + blockPos.y;

        if (figure->isOwnBlock(PosX, PosY))
            continue;

        if (map[PosX][PosY] == '#' || ((PosX) >= Settings::height - 1))
            return false;
    }
    return true;
}

bool Action::DropCommand::execute()
{
    Position newPos = figure->getPos();
    newPos.x++;
    figure->setPos(newPos);

    return true;
}