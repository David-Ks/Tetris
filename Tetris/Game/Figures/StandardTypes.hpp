#ifndef STANDARD_TYPES_H
#define STANDARD_TYPES_H

namespace FigureStandardTypes
{
    const int typesCount = 7;
    const int typesBlocksCount = 4;
    
    int types[7][4][2] = {
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
        {{1, 1}, {2, 1}, {2, 2}, {2, 3}},
        {{2, 1}, {2, 2}, {2, 3}, {1, 3}},
        {{1, 1}, {2, 1}, {2, 2}, {3, 2}},
        {{3, 1}, {2, 1}, {2, 2}, {1, 2}},
        {{1, 1}, {1, 2}, {2, 2}, {2, 1}},
        {{1, 2}, {2, 1}, {2, 2}, {2, 3}}};
} // namespace FigureStandardTypes

#endif