#ifndef GAME_SETTINGS
#define GAME_SETTINGS

#include "Graphics/NcursesWindow.hpp"
#include "Map/Board.hpp"

#include <vector>

namespace Settings
{
    typedef std::vector<std::vector<std::vector<int>>> typeList_t; // 3D

    const static int height = 30;
    const static int weidth = 12;

    // Must fit in a 4x4 matrix
    const static typeList_t types = {
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
        {{1, 1}, {2, 1}, {3, 1}, {1, 2}},
        {{1, 1}, {1, 2}, {2, 2}, {3, 2}},
        {{1, 2}, {2, 1}, {2, 2}, {1, 3}},
        {{1, 1}, {2, 3}, {2, 2}, {1, 2}},
        {{1, 1}, {1, 2}, {2, 2}, {2, 1}},
        {{1, 2}, {2, 1}, {2, 2}, {2, 3}}};

} // namespace Settings

Draw::Window *Draw::window()
{
    static Draw::Window *win = new Draw::NcursesWindow;
    return win;
}

#endif