#include "Settings.cpp"
#include "Game.cpp"
#include <memory>

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
public:
    Tetris() {}
    ~Tetris()
    {
        delete Game::window();
        delete Game::player();
        delete Game::map();
    }

public:
    void run()
    {
        std::unique_ptr<Loop>loop(new Loop);
        loop->menu();
    }
};