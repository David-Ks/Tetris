#include "Settings.cpp"
#include <memory>

#include "Players/Player.cpp"

// Undefined reference Error
#include "GameLoop/Loop.cpp"

#include "Figures/Figure.cpp"
#include "Map/Board.cpp"
#include "Graphics/NcursesWindow.cpp"
#include "Graphics/IostreamWindow.cpp"

#include "Events/KeyBoardEvent.cpp"

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
        GameLoop::loop().menu();
    }
};