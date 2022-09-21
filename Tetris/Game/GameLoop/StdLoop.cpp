#include "StdLoop.hpp"

StdLoop::StdLoop(Player *player) : Loop(player) {}

StdLoop::~StdLoop() {}

void StdLoop::menu(Draw::Window *win, Listen::Event *event)
{
    unsigned choice = 0;

    while (true)
    {
        win->winClear();
        win->menu(choice);
        event->handler(choice);

        if (choice == 666) // exit code
            break;
        else if (choice == 777) // Play code
        {
            Listen::Event *gameEvent = new Listen::GameEvent(win);
            game(win, gameEvent);
        }
    }
}

void StdLoop::game(Draw::Window *win, Listen::Event *event)
{
    unsigned choice = 0;
    unsigned autoDropDown = 661;

    map = new Settings::CustomBoard(player);
    map->addFigure();
    map->setGameOver(false);
    win->winClear();

    while (!map->getGameOver())
    {
        win->winClear();
        win->game(map);
        event->handler(choice, map);

        map->update();

        event->handler(autoDropDown, map);
        map->update();

        if (choice == 666) // exit code
            break;
    }
}