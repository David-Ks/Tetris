#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <vector>

namespace Settings
{
    using FigureBlocksPositions = std::vector<std::vector<int>>;
    using Figures = std::vector<FigureBlocksPositions>; // 3D

    // Must fit in a 4x4 matrix
    const Figures figureTypes = {
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}}, // I
        {{1, 1}, {2, 1}, {3, 1}, {1, 2}}, // L
        {{1, 1}, {1, 2}, {2, 2}, {3, 2}}, // J
        {{1, 2}, {2, 1}, {2, 2}, {1, 3}}, // S
        {{1, 1}, {2, 3}, {2, 2}, {1, 2}}, // Z
        {{1, 1}, {1, 2}, {2, 2}, {2, 1}}, // O
        {{1, 2}, {2, 1}, {2, 2}, {2, 3}}}; // T


    inline const int width = 14;
    inline const int height = 20;
    
    inline int loopSpeed = 7;

    enum GameState
    {
        SelectPayer,

        Menu,
        Play,
        PlayerVsCPU,
        Options,
        Records,
        Exit,

        inAnyMenu,
        inGame,

        Any
    };

    inline bool isAnyMenu(GameState state)
    {
        if (state == Menu || state == Options || state == Records)
        {
            return true;
        }
        return false;
    }
} // namespace Settings


#endif // SETTINGS_HPP