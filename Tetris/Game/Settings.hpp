#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>

// Player lib
#include "Players/StandardPlayer.hpp"

// Figures lib
#include "Figures/Figure.hpp"

// Map lib
#include "Map/StandardBoard.hpp"

// Graphics lib
#include "Graphics/NcursesWindow.hpp"
#include "Graphics/IostreamWindow.hpp"

// Loop lib
#include "GameLoop/StandardLoop.hpp"

// Events lib
#include "Events/MenuEvent.hpp"
#include "Events/GameEvent.hpp"


// Must be like this
// #include "Figures/StandardFigure.cpp"
// #include "Map/StandardBoard.cpp"
// #include "Graphics/NcursesWindow.cpp"
// #include "Graphics/StdWindow.cpp"
// #include "GameLoop/StdLoop.cpp"
// #include "Players/StandardPlayer.cpp"
// #include "Events/GameEvent.cpp"
// #include "Events/MenuEvent.cpp"

namespace Settings
{
    typedef std::vector<std::vector<std::vector<int>>> typeList; // 3D

    const static int height = 30;
    const static int weidth = 12;

    const static typeList types = {
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
        {{1, 1}, {2, 1}, {2, 2}, {2, 3}},
        {{2, 1}, {2, 2}, {2, 3}, {1, 3}},
        {{1, 1}, {2, 1}, {2, 2}, {3, 2}},
        {{3, 1}, {2, 1}, {2, 2}, {1, 2}},
        {{1, 1}, {1, 2}, {2, 2}, {2, 1}},
        {{1, 2}, {2, 1}, {2, 2}, {2, 3}}};

    // Set your cutsom classes
    using CustomPlayer = StandardPlayer;
    using CustomBoard = Map::StandardBoard;
    using CustomWindow = Draw::NcursesWindow;
    using CustomLoop = StandardLoop;
} // namespace Settings

#endif