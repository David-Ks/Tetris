#include "Loop.hpp"

Loop::Loop(Player *player)
{
    this->player = player;
}

Loop::~Loop() {}

void Loop::menu(Draw::Window *window, Listen::Event *event)
{
    unsigned choice = 0;

    while (true)
    {
        window->winClear();
        window->menu(choice);
        event->handler(choice);

        if (choice == 666) // exit code
            break;
        else if (choice == 777) // Play code
        {
            Listen::Event *gameEvent = new Listen::GameEvent(window);
            game(window, gameEvent);
        }
    }
}

void Loop::game(Draw::Window *window, Listen::Event *event)
{
    unsigned choice = 0;
    unsigned autoDropDown = 661;

    map = new Settings::CustomBoard(player);
    map->addFigure();
    map->setGameOver(false);
    window->winClear();

    while (!map->getGameOver())
    {
        window->winClear();
        window->game(map);
        event->handler(choice, map);
        map->update();

        if (map->getGameOver())
            break;

        event->handler(autoDropDown, map);
        map->update();

        if (choice == 666) // exit code
            break;
    }

    // player->saveScoreIfRecord() and set 0
}