#ifndef FIGURE_H
#define FIGURE_H

#include "items/Block.cpp"
#include "../Settings.cpp"

using BlockList = std::vector<Block *>;

namespace Object
{
    class Figure
    {
    private:
        Position position;

    public:
        BlockList blocks;
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