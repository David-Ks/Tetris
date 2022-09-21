#ifndef SETTINGS_H
#define SETTINGS_H

// Player lib
#include "Players/StandardPlayer.hpp"

// Figures lib
#include "Figures/StandardFigure.hpp"

// Map lib
#include "Map/StandardBoard.hpp"

// Graphics lib
#include "Graphics/NcursesWindow.hpp"
#include "Graphics/StdWindow.hpp"

// Loop lib
#include "GameLoop/StdLoop.hpp"

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
    const int height = 30;
    const int weidth = 12;

    // Set your cutsom classes
    using CustomFigure = StandardFigure;
    using CustomPlayer = StandardPlayer;
    using CustomBoard = Map::StandardBoard;
    using CustomWindow = Draw::NcursesWindow;
    using CustomLoop = StdLoop;
} // namespace Settings

#endif