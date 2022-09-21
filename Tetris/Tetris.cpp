#include "Tetris.hpp"

Tetris::Tetris()
{
    window = new Settings::CustomWindow;
    player = new Settings::CustomPlayer;
    loop = new Settings::CustomLoop(player);
}

Tetris::~Tetris()
{
    delete window;
    delete loop;
    delete map;
}

void Tetris::run()
{
    Listen::MenuEvent *event = new Listen::MenuEvent(window);
    loop->menu(window, event);

    delete event;
}