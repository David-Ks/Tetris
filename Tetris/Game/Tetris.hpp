#ifndef TETRIS_HPP
#define TETRIS_HPP


#include "Settings.hpp"
#include "src/EventSystem/EventSystem.hpp"
#include "src/Window/Output/NcursesWindow.hpp"
#include "src/Menu/Menu.hpp"

class Tetris
{
private:
    Settings::GameState state;
    Window *window;
    EventSystem eventSystem;
    Menu menu;

public:
    Tetris();
    ~Tetris();
    
public:
    void run();
};

#endif // TETRIS_HPP