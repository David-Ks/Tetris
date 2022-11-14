#include "LeftCommand.hpp"
#include "../../Board/Board.hpp"
#include "../../../Utils/Objects/Tools.hpp"

bool Action::Game::LeftCommand::isAvailable() const
{
    const BoardMatrix boardMatrix = board.matrix;
    const Object::Figure *figure = Utils::Objects::getLastItem(board.figures);

    if (!figure)
        return false;

    for (const auto &block : figure->blocks)
    {
        if (!block)
            continue;

        const int PosX = figure->getPos().x + block->getPos().x;
        const int PosY = figure->getPos().y + block->getPos().y - 1;

        if (figure->isOwnBlock(PosX, PosY))
            continue;

        if (boardMatrix[PosX][PosY] == '#' || PosY < 0)
            return false;
    }
    return true;
}

bool Action::Game::LeftCommand::execute()
{
    Object::Figure *figure = Utils::Objects::getLastItem(board.figures);

    Position newPos = figure->getPos();
    newPos.y--;
    figure->setPos(newPos);
    
    return true;
}