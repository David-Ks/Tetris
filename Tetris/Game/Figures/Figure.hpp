#ifndef FIGURE_H
#define FIGURE_H

#include "items/Block.cpp"

class Figure
{
public:
    Block *blocks[4];
    Position pos;

public:
    Figure() {}
    virtual ~Figure() {}

public:
    virtual void init() = 0;
    virtual void setPos(Position pos) = 0;
    virtual Position getPos() = 0;

public:
    bool isRotatable;

    bool isOwnBlock(int posX, int poxY)
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
};

#endif