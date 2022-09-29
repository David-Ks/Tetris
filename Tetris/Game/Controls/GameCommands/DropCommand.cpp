#include "DropCommand.hpp"

bool Action::Game::DropCommand::isAvailable()
{
    MapMatrix map = Map::board().map;
    Object::Figure *figure = Map::board().figures.back();

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

bool Action::Game::DropCommand::execute()
{
    Object::Figure *figure = Map::board().figures.back();
    
    Position newPos = figure->getPos();
    newPos.x++;
    figure->setPos(newPos);

    return true;
}