#ifndef FIGURE_H
#define FIGURE_H

#include "../Settings.hpp"
#include "items/Block.cpp"


namespace Object
{
    class Figure
    {
    public:
        Block *blocks[4];
        Position pos;
        bool isRotatable;

    public:
        Figure();
        ~Figure();

    public:
        bool isOwnBlock(int posX, int poxY);
        void setPos(Position pos);
        Position getPos();
    };

} // namespace Object

#endif