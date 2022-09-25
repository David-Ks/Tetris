#ifndef FIGURE_H
#define FIGURE_H

#include "items/Block.cpp"


namespace Object
{
    class Figure
    {
    public:
        std::vector<Block*>blocks;
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