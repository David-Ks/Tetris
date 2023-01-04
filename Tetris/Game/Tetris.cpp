#include "Tetris.hpp"

Tetris::Tetris() : state(Settings::GameState::Menu),
                   window(new NcursesWindow(state)),
                   eventSystem(state),
                   menu(state, eventSystem, window)
{
}

Tetris::~Tetris()
{
    delete window;
}

void Tetris::run()
{
    eventSystem.runEventLoop();
}