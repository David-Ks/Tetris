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
        Position position;
        bool isRotatable;

    public:
        Figure();
        ~Figure();

    public:
        bool isOwnBlock(int x, int y);
        void setPos(Position position);
        Position getPos();
    };

} // namespace Object

#endif