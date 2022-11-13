#include "DropCommand.hpp"
#include "../../Board/Board.hpp"
#include "../../../Utils/Objects/Tools.hpp"
#include "../../Settings.hpp"


bool Action::Game::DropCommand::isAvailable() const
{
    const BoardMatrix &map = board.map;
    constexpr int minHeightForGameOver = 4;
    const Object::Figure *figure = Utils::Objects::getlastItem(board.figures);

    if (!figure)
        return false;

    for (const auto &block : figure->blocks)
    {
        if (!block)
            continue;

        const int PosX = figure->getPos().x + block->getPos().x + 1;
        const int PosY = figure->getPos().y + block->getPos().y;

        if (figure->isOwnBlock(PosX, PosY))
            continue;

        if (map[PosX][PosY] == '#' || PosX >= Settings::height - 1)
        {
            if (PosX <= minHeightForGameOver)
                board.setGameOver(true);

            return false;
        }
    }
    return true;
}

bool Action::Game::DropCommand::execute()
{
    Object::Figure *figure = Utils::Objects::getlastItem(board.figures);
    
    Position newPos = figure->getPos();
    newPos.x++;
    figure->setPos(newPos);

    return true;
}