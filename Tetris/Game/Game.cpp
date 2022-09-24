#include "Players/StandardPlayer.hpp"
#include "Map/StandardBoard.hpp"
#include "Graphics/NcursesWindow.hpp"
#include "Graphics/IostreamWindow.hpp"

namespace Game
{
    Draw::Window *window()
    {
        static Draw::Window *win = new Draw::NcursesWindow;
        return win;
    }

    Map::Board *map()
    {
        static Map::Board *board = new Map::StandardBoard;
        return board;
    }

    Player *player()
    {
        static Player *plyr = new StandardPlayer;
        return plyr;
    }
} // namespace Game