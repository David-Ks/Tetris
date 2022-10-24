#include "DropCommand.hpp"

bool Action::Game::DropCommand::isAvailable() const
{
    const MapMatrix map = Map::board().map;
    const Object::Figure *figure = Map::board().figures.back();

    for (const auto &block : figure->blocks)
    {
        if (!block)
            continue;

        const int PosX = figure->getPos().x + block->getPos().x + 1;
        const int PosY = figure->getPos().y + block->getPos().y;

        if (figure->isOwnBlock(PosX, PosY))
            continue;

        if (map[PosX][PosY] == '#' || ((PosX) >= Settings::height - 1))
            return false;
    }
    return true;
}

bool Action::Game::DropCommand::execute()
{
    constexpr static int minHightForGameOver = 4;
    constexpr static int gameMatrixHight = 4;
    Object::Figure *figure = Map::board().figures.back();
    
    Position newPos = figure->getPos();
    newPos.x++;

    if (newPos.x + gameMatrixHight <= minHightForGameOver)
        Map::board().theEndOfGame();

    figure->setPos(newPos);

    return true;
}