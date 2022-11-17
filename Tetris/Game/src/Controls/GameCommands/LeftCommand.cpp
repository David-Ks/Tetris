#include "LeftCommand.hpp"
#include "../../Board/Board.hpp"
#include "../../../Utils/Objects/Tools.hpp"

bool Action::Game::LeftCommand::isAvailable() const
{
    const Object::Figure *figure = Utils::Objects::getLastItem(board.figures);

    if (!figure)
        return false;

    for (const auto &block : figure->blocks)
    {
        if (!block)
            continue;

        const Position absPosition {figure->getPos().x + block->getPos().x,
                                    figure->getPos().y + block->getPos().y - 1};


        if (figure->isOwnBlock(absPosition))
            continue;

        if (!board.isFreePosition(absPosition) || absPosition.y < 0)
            return false;
    }
    return true;
}

bool Action::Game::LeftCommand::execute()
{
    Object::Figure *figure = Utils::Objects::getLastItem(board.figures);

    board.removeFigure(figure);

    Position newPos = figure->getPos();
    newPos.y--;
    figure->setPos(newPos);
    
    board.insertFigure(figure);

    return true;
}