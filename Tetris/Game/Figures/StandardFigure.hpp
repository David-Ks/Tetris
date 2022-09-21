#ifndef STANDARDFIGURE_H
#define STANDARDFIGURE_H

#include "Figure.hpp"
#include "StandardTypes.hpp"

class StandardFigure : public Figure
{
public:
    StandardFigure() {}
    ~StandardFigure() {}

public:
    void init();
    void setPos(Position pos);
    Position getPos();
};

#endif