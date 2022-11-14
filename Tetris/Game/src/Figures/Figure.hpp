#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "items/Block.hpp"

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

    public:
        Figure();

    public:
        bool isOwnBlock(int x, int y) const;
        void setPos(Position position);
        Position getPos() const;
    };

} // namespace Object

#endif