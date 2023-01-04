#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <vector>

struct Position
{
    int x;
    int y;
};

class Object
{
protected:
    using Positions = std::vector<Position>;

    Position position;
    Positions blocksPositions;
    int type;

public:
    Object() {}
    virtual ~Object() {}

public:
    virtual bool isOwnBlock(const Position &localPosition) const = 0;
    virtual char getSymbol() const = 0;

    Position getPosition() const
    {
        return position;
    }
    Positions getBlocksPositions() const
    {
        return blocksPositions;
    }
    void setBlocksPositions(Positions blocksPositions)
    {
        this->blocksPositions = blocksPositions;
    }
    void setPosition(Position pos)
    {
        position = pos;
    }
};

#endif // OBJECT_HPP