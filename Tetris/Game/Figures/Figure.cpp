#include <cstdlib>
#include "Figure.hpp"

Object::Figure::Figure()
{
    int typeNumber = rand() % Settings::types.size();
    Position position;

    for (int i = 0; i < Settings::types[typeNumber].size(); i++)
    {
        blocks[i] = new Block;
        position.x = Settings::types[typeNumber][i][0];
        position.y = Settings::types[typeNumber][i][1];
        blocks[i]->setPos(position);
    }

    isRotatable = true;
}

Object::Figure::~Figure() {}

bool Object::Figure::isOwnBlock(int x, int y)
{
    for (auto &block : blocks)
    {
        if (!block)
            continue;

        Position blockPos = block->getPos();

        if (blockPos.x + position.x == x && blockPos.y + position.y == y)
            return true;
    }
    return false;
}

void Object::Figure::setPos(Position position)
{
    this->position = position;
}

Position Object::Figure::getPos()
{
    return position;
}