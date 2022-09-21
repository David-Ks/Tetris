#ifndef BLOCK_H
#define BLOCK_H

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
    Block() {}
    ~Block() {}

public:
    Position getPos();
    void setPos(Position pos);
};

#endif