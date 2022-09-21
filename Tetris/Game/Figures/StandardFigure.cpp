#include "StandardFigure.hpp"
#include <cstdlib>

void StandardFigure::init()
{
    int typeNumber = rand() % FigureStandardTypes::typesCount;
    Position pos;

    for (int i = 0; i < FigureStandardTypes::typesBlocksCount; i++)
    {
        blocks[i] = new Block;
        pos.x = FigureStandardTypes::types[typeNumber][i][0];
        pos.y = FigureStandardTypes::types[typeNumber][i][1];
        blocks[i]->setPos(pos);
    }

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