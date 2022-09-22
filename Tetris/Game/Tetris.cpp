#include "Settings.hpp"

#include "Players/StandardPlayer.cpp"

// Undefined reference Error
#include "Figures/Figure.cpp"
#include "Map/StandardBoard.cpp"
#include "Graphics/NcursesWindow.cpp"
#include "Graphics/IostreamWindow.cpp"
#include "GameLoop/Loop.cpp"
#include "Events/MenuEvent.cpp"
#include "Events/GameEvent.cpp"

class Tetris
{
private:
    Draw::Window *window;
    Player *player;
    Loop *loop;

public:
    Tetris()
    {
        window = new Settings::CustomWindow;
        player = new Settings::CustomPlayer;
        loop = new Loop(player);
    }
    ~Tetris()
    {
        delete window;
        delete loop;
        delete player;
    }

public:
    void run()
    {
        Listen::MenuEvent *event = new Listen::MenuEvent(window);
        loop->menu(window, event);

        delete event;
    }
};