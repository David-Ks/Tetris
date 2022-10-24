#include "Figure.hpp"
#include "../Settings.cpp"

Object::Figure::Figure()
{
    int typeNumber = rand() % Settings::types.size();
    Position position;

    for (int i = 0; i < Settings::types[typeNumber].size(); ++i)
    {
        blocks.push_back(new Block);
        position.x = Settings::types[typeNumber][i][0];
        position.y = Settings::types[typeNumber][i][1];
        blocks[i]->setPos(position);
    }

    isRotatable = true;
}

bool Object::Figure::isOwnBlock(int x, int y) const
{
    for (auto &block : blocks)
    {
        if (!block)
            continue;

        const Position blockPos = block->getPos();

        if (blockPos.x + position.x == x && blockPos.y + position.y == y)
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

bool Object::Figure::operator==(const Figure& that) const
{
    const Position thisPos = this->getPos();
    const Position thatPos = that.getPos();

    if (thisPos.x == thatPos.x && thisPos.y == thatPos.y)
        return true;
    return false;
}