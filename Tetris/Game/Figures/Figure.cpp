#include <cstdlib>
#include "Figure.hpp"

Object::Figure::Figure()
{
    int typeNumber = rand() % Settings::types.size();
    Position pos;

    for (int i = 0; i < Settings::types[typeNumber].size(); i++)
    {
        blocks[i] = new Block;
        pos.x = Settings::types[typeNumber][i][0];
        pos.y = Settings::types[typeNumber][i][1];
        blocks[i]->setPos(pos);
    }

    isRotatable = true;
}

Object::Figure::~Figure() {}

bool Object::Figure::isOwnBlock(int posX, int poxY)
{
    for (auto &block : blocks)
    {
        if (!block)
            continue;

        Position blockPos = block->getPos();

        if (blockPos.x + pos.x == posX && blockPos.y + pos.y == poxY)
            return true;
    }
    return false;
}

void Object::Figure::setPos(Position pos)
{
    this->pos = pos;
}

Position Object::Figure::getPos()
{
    return pos;
}