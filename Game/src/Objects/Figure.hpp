#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "Object.hpp"
#include "../../Settings.hpp"

class Figure : public Object
{
public:
    Figure();

public:
    char getSymbol() const;
    void removeBlocksPosition(Position localPosition);
    bool isOwnBlock(const Position &localPosition) const;

private:
    void addBlocksPosition(Position localPosition);
    int generateType() const;
};

#endif // FIGURE_HPP