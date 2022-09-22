#include "../Settings.hpp"
#include "Loop.hpp"

Loop::Loop(Player *player)
{
    this->player = player;
}

Loop::~Loop() {}

void Loop::menu(Draw::Window *win, Listen::Event *event)
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

void Loop::game(Draw::Window *win, Listen::Event *event)
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

        if (map->getGameOver())
            break;

        event->handler(autoDropDown, map);
        map->update();

        if (choice == 666) // exit code
            break;
    }
}