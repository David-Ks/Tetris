#include "DropCommand.hpp"
#include "../../Board/Board.hpp"
#include "../../../Utils/Objects/Tools.hpp"
#include "../../Settings.hpp"


bool Action::Game::DropCommand::isAvailable() const
{
    constexpr int minHeightForGameOver = 4;
    const Object::Figure *figure = Utils::Objects::getLastItem(board.figures);

    if (!figure)
        return false;

    for (const auto &block : figure->blocks)
    {
        if (!block)
            continue;

        const Position absPosition {figure->getPos().x + block->getPos().x + 1,
                                    figure->getPos().y + block->getPos().y};

        if (figure->isOwnBlock(absPosition))
            continue;

        if (!board.isFreePosition(absPosition) || absPosition.x >= Settings::height - 1)
        {
            if (absPosition.x <= minHeightForGameOver)
                board.setGameOver(true);

            return false;
        }
    }
    return true;
}

bool Action::Game::DropCommand::execute()
{
    Object::Figure *figure = Utils::Objects::getLastItem(board.figures);

    board.removeFigure(figure);
    
    Position newPos = figure->getPos();
    newPos.x++;
    figure->setPos(newPos);

    board.insertFigure(figure);
    
    return true;
}