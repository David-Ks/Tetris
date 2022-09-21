#include "Settings.hpp"

#include "Figures/StandardFigure.cpp"
#include "Map/StandardBoard.cpp"
#include "Graphics/NcursesWindow.cpp"
#include "Graphics/IostreamWindow.cpp"
#include "GameLoop/StandardLoop.cpp"
#include "Players/StandardPlayer.cpp"
#include "Events/GameEvent.cpp"
#include "Events/MenuEvent.cpp"

class Tetris
{
private:
    Draw::Window *window;
    Map::Board *map;
    Player *player;
    Loop *loop;

public:
    Tetris()
    {
        window = new Settings::CustomWindow;
        player = new Settings::CustomPlayer;
        loop = new Settings::CustomLoop(player);
    }
    ~Tetris()
    {
        delete window;
        delete loop;
        delete map;
    }

public:
    void run()
    {
        Listen::MenuEvent *event = new Listen::MenuEvent(window);
        loop->menu(window, event);

        delete event;
    }
};