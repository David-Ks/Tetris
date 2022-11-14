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
        const Position absFigurePos{newRotatedBlockPos.x + figurePos.x, newRotatedBlockPos.y + figurePos.y};

        if (figure->isOwnBlock(absFigurePos.x, absFigurePos.y))
            continue;

        if (!isFreePosition(absFigurePos.x, absFigurePos.y))
            return false;
    }

    return true;
}

bool Action::Game::RotateCommand::execute()
{
    Object::Figure *figure = Utils::Objects::getLastItem(board.figures);

    for (auto &block : figure->blocks)
    {
        if (!block)
            continue;

        block->setPos(getNewRotatedPos(block->getPos()));
    }
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

bool Action::Game::RotateCommand::isFreePosition(const int x, const int y) const
{
    if (x < 0 || y < 0 || y >= Settings::width || board.matrix[x][y] != ' ')
    {
        return false;
    }
    return true;
}