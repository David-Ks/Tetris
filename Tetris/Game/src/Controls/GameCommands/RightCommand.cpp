#include "RightCommand.hpp"
#include "../../Board/Board.hpp"
#include "../../../Utils/Objects/Tools.hpp"
#include "../../Settings.hpp"

bool Action::Game::RightCommand::isAvailable() const
{
    const BoardMatrix map = board.map;
    const Object::Figure *figure = Utils::Objects::getlastItem(board.figures);

    if (!figure)
        return false;

    for (const auto &block : figure->blocks)
    {
        if (!block)
            continue;

        const int PosX = figure->getPos().x + block->getPos().x;
        const int PosY = figure->getPos().y + block->getPos().y + 1;

        if (figure->isOwnBlock(PosX, PosY))
            continue;

        if (map[PosX][PosY] == '#' || PosY == Settings::width)
            return false;
    }
    return true;
}

bool Action::Game::RightCommand::execute()
{
    Object::Figure *figure = Utils::Objects::getlastItem(board.figures);

    Position newPos = figure->getPos();
    newPos.y++;
    figure->setPos(newPos);

    return true;
}