#include "Settings.cpp"
#include <memory>

#include "Players/Player.cpp"

// Undefined reference Error
#include "Figures/Figure.cpp"
#include "Map/Board.cpp"
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
        delete Draw::window();
    }

public:
    void run()
    {
        std::unique_ptr<Loop>loop(new Loop);
        loop->menu();
    }
};