#include "StandardFigure.hpp"
#include <cstdlib>

void StandardFigure::init()
{
    int typeNumber = rand() % 5;
    Position pos;

    for (int i = 0; i < 4; i++)
    {
        blocks[i] = new Block;
        pos.x = FigureStandardTypes::types[typeNumber][i][0];
        pos.y = FigureStandardTypes::types[typeNumber][i][1];
        blocks[i]->setPos(pos);
    }

    if (typeNumber == 3)
        isRotatable = false;
    else
        isRotatable = true;
}

void StandardFigure::setPos(Position pos)
{
    this->pos = pos;
}

Position StandardFigure::getPos()
{
    return pos;
}