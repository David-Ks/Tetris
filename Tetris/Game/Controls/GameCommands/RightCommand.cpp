#include "RightCommand.hpp"

bool Action::Game::RightCommand::isAvailable() const
{
    const MapMatrix map = Map::board().map;
    const Object::Figure *figure = Map::board().figures.back();

    for (const auto &block : figure->blocks)
    {
        if (!block)
            continue;

        const int PosX = figure->getPos().x + block->getPos().x;
        const int PosY = figure->getPos().y + block->getPos().y + 1;

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