#include "Loop.hpp"
#include <memory>

void Loop::menu()
{
    std::unique_ptr<Listen::Event>event(new Listen::MenuEvent);
    unsigned choice = 0;

    while (true)
    {
        Game::window()->clean();
        Game::window()->drawMenu(choice);
        event->handler(choice);

        if (choice == 666) // exit code
            break;
        else if (choice == 777) // Play code
            game();
    }
}

void Loop::game()
{
    std::unique_ptr<Listen::Event>event(new Listen::GameEvent);

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