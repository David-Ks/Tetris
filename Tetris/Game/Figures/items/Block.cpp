#include "Block.hpp"

Position Block::getPos() const
{
    return pos;
}

void Block::setPos(Position pos)
{
    this->pos = pos;
}