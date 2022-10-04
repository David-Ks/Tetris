#include "GameLoop/Loop.cpp"
#include "Map/Board.cpp"
#include "Graphics/NcursesWindow.cpp"

class Tetris
{
public:
    Tetris() 
    {
        Draw::window(); // init
    }
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