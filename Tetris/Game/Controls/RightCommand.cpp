#include "RightCommand.hpp"

bool Action::RightCommand::isAvailable(map_t map)
{
    for (auto &block : figure->blocks)
    {
        if (!block)
            continue;

        Position blockPos = block->getPos();
        Position figurePos = figure->getPos();

        int PosX = figurePos.x + blockPos.x;
        int PosY = figurePos.y + blockPos.y + 1;

        if (figure->isOwnBlock(PosX, PosY))
            continue;

        if (map[PosX][PosY] == '#' || PosY == Settings::weidth)
            return false;
    }
    return true;
}

bool Action::RightCommand::execute()
{
    Position newPos = figure->getPos();
    newPos.y++;
    figure->setPos(newPos);

    return true;
}