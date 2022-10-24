#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "items/Block.cpp"

#include <vector>

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
        bool operator==(const Figure& that) const;

    public:
        bool isOwnBlock(int x, int y) const;
        void setPos(Position position);
        Position getPos() const;
    };

} // namespace Object

#endif