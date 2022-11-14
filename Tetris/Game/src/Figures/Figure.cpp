#include "Figure.hpp"
#include "../Settings.hpp"

Object::Figure::Figure()
{
    const int typeNumber = rand() % Settings::types.size();
    Settings::FigureType figureType = Settings::types[typeNumber];

    for(const auto &position : figureType)
    {
        auto *block = new Block;
        const Position blockPosition {position[0], position[1]};
        block->setPos(blockPosition);
        blocks.push_back(block);
    }
}

bool Object::Figure::isOwnBlock(int x, int y) const
{
    for (const auto &block : blocks)
    {
        if (!block)
            continue;

        const Position blockPosition = block->getPos();
        if (blockPosition.x + position.x == x && blockPosition.y + position.y == y)
            return true;
    }
    return false;
}

void Object::Figure::setPos(Position position)
{
    this->position = position;
}

Position Object::Figure::getPos() const
{
    return position;
}