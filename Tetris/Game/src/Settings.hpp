#ifndef GAME_SETTINGS
#define GAME_SETTINGS

#include "Board/Board.hpp"

#include <vector>

namespace Settings
{
    using FigureType = std::vector<std::vector<int>>;
    using TypeList = std::vector<FigureType>; // 3D

    constexpr static int height = 20;
    constexpr static int width = 12;

    // Must fit in a 4x4 matrix
    const static TypeList types = {
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}}, // I
        {{1, 1}, {2, 1}, {3, 1}, {1, 2}}, // L
        {{1, 1}, {1, 2}, {2, 2}, {3, 2}}, // J
        {{1, 2}, {2, 1}, {2, 2}, {1, 3}}, // S
        {{1, 1}, {2, 3}, {2, 2}, {1, 2}}, // Z
        {{1, 1}, {1, 2}, {2, 2}, {2, 1}}, // O
        {{1, 2}, {2, 1}, {2, 2}, {2, 3}}}; // T

} // namespace Settings

#endif