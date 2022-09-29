#include "RightCommand.hpp"

bool Action::Game::RightCommand::isAvailable()
{
    MapMatrix map = Map::board().map;
    Object::Figure *figure = Map::board().figures.back();

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

bool Action::Game::RightCommand::execute()
{
    Object::Figure *figure = Map::board().figures.back();

    Position newPos = figure->getPos();
    newPos.y++;
    figure->setPos(newPos);

    return true;
}