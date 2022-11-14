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
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
        {{1, 1}, {2, 1}, {3, 1}, {1, 2}},
        {{1, 1}, {1, 2}, {2, 2}, {3, 2}},
        {{1, 2}, {2, 1}, {2, 2}, {1, 3}},
        {{1, 1}, {2, 3}, {2, 2}, {1, 2}},
        {{1, 1}, {1, 2}, {2, 2}, {2, 1}},
        {{1, 2}, {2, 1}, {2, 2}, {2, 3}}};

} // namespace Settings

#endif