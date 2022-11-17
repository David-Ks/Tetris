#include "RotateCommand.hpp"
#include "../../Board/Board.hpp"
#include "../../../Utils/Objects/Tools.hpp"
#include "../../Settings.hpp"

#include <iostream>

bool Action::Game::RotateCommand::isAvailable() const
{
    const Object::Figure *figure = Utils::Objects::getLastItem(board.figures);

    for (const auto &block : figure->blocks)
    {
        if (!block)
            continue;

        const Position figurePos = figure->getPos();
        const Position newRotatedBlockPos = getNewRotatedPos(block->getPos());
        const Position absPosition{newRotatedBlockPos.x + figurePos.x, newRotatedBlockPos.y + figurePos.y};

        if (figure->isOwnBlock(absPosition))
            continue;

        if (!isFreePosition(absPosition))
            return false;
    }

    return true;
}

bool Action::Game::RotateCommand::execute()
{
    Object::Figure *figure = Utils::Objects::getLastItem(board.figures);

    board.removeFigure(figure);

    for (auto &block : figure->blocks)
    {
        if (!block)
            continue;

        block->setPos(getNewRotatedPos(block->getPos()));
    }

    board.insertFigure(figure);

    return true;
}

Position Action::Game::RotateCommand::getNewRotatedPos(const Position blockPosition)
{
    Position newPos{blockPosition.y, blockPosition.x}; // x=y, y=x;

    switch (newPos.y)
    {
    case 0:
        newPos.y = 3;
        break;
    case 1:
        newPos.y = 2;
        break;
    case 2:
        newPos.y = 1;
        break;
    case 3:
    case 4:
        newPos.y = 0;
        break;
    }

    return newPos;
}

bool Action::Game::RotateCommand::isFreePosition(const Position &position) const
{
    if (position.x < 0 || position.y < 0 || position.y >= Settings::width || !board.isFreePosition(position))
    {
        return false;
    }
    return true;
}