#include "src/GameLoop/Loop.cpp"
#include "src/Graphics/NcursesWindow.cpp"

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