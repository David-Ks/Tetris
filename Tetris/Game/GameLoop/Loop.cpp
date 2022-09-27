#include "Loop.hpp"
#include <memory>

void Loop::menu()
{
    std::unique_ptr<Listen::Event>event(new Listen::MenuEvent);
    unsigned choice = 0;

    while (true)
    {
        Draw::window()->clean();
        Draw::window()->drawMenu(choice);
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

    Map::board().addFigure();
    Map::board().setGameOver(false);

    while (!Map::board().getGameOver())
    {
        Draw::window()->clean();
        Draw::window()->drawGame();
        event->handler(choice);
        
        Map::board().update();
        if (Map::board().getGameOver())
            break;

        event->handler(autoDropDown);
        Map::board().update();
    }

    // player->saveScoreIfRecord() and set 0
}