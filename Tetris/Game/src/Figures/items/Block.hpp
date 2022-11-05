#ifndef BLOCK_HPP
#define BLOCK_HPP

struct Position
{
    int x;
    int y;
};

class Block
{
private:
    Position pos;

public:
    Position getPos() const;
    void setPos(Position pos);
};

#endif