#include "Loop.hpp"

void Loop::menu(Listen::Event *event)
{
    unsigned choice = 0;

    while (true)
    {
        Game::window()->clean();
        Game::window()->drawMenu(choice);
        event->handler(choice);

        if (choice == 666) // exit code
            break;
        else if (choice == 777) // Play code
        {
            Listen::Event *gameEvent = new Listen::GameEvent();
            game(gameEvent);
        }
    }
}

void Loop::game(Listen::Event *event)
{
    unsigned choice = 0;
    unsigned autoDropDown = 661;

    Game::map()->addFigure();
    Game::map()->setGameOver(false);

    while (!Game::map()->getGameOver())
    {
        Game::window()->clean();
        Game::window()->drawGame();
        event->handler(choice);
        Game::map()->update();

        if (Game::map()->getGameOver())
            break;

        event->handler(autoDropDown);
        Game::map()->update();

        if (choice == 666) // exit code
            break;
    }

    // player->saveScoreIfRecord() and set 0
}