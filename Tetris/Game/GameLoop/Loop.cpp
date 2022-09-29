#include <memory>

#include "Loop.hpp"
#include "../Controls/MenuCommands/SelectCommand.cpp"

void GameLoop::Loop::menu()
{
    std::unique_ptr<EventSystem::KeyBoardEvent> event(new EventSystem::KeyBoardEvent);

    event->addListener(EventSystem::KEY::UP, new Action::Menu::UpCommand);
    event->addListener(EventSystem::KEY::DOWN, new Action::Menu::DownCommand);
    event->addListener(EventSystem::KEY::ENTER, new Action::Menu::SelectCommand);


    while (true)
    {
        Draw::window()->clean();
        Draw::window()->drawMenu();
        
        event->invoke(static_cast<EventSystem::KEY>(Draw::window()->input()));
    }

    event->delAllListeners();
}

void GameLoop::Loop::game()
{
    std::unique_ptr<EventSystem::KeyBoardEvent> event(new EventSystem::KeyBoardEvent);

    event->addListener(EventSystem::KEY::UP, new Action::RotateCommand);
    event->addListener(EventSystem::KEY::DOWN, new Action::DropCommand);
    event->addListener(EventSystem::KEY::LEFT, new Action::LeftCommand);
    event->addListener(EventSystem::KEY::RIGHT, new Action::RightCommand);

    Map::board().addFigure();
    Map::board().setGameOver(false);

    while (!Map::board().getGameOver())
    {
        Draw::window()->clean();
        Draw::window()->drawGame();

        event->invoke(static_cast<EventSystem::KEY>(Draw::window()->input()));

        Map::board().update();
        if (Map::board().getGameOver())
            break;

        // If can't Auto drop down
        if (!event->invoke(EventSystem::KEY::DOWN))
        {
            Map::board().addFigure();
            Map::board().lineCheck();
        }

        Map::board().update();
    }

    event->delAllListeners();

    // player->saveScoreIfRecord() and set 0
}

GameLoop::Loop &GameLoop::loop()
{
    static GameLoop::Loop lp;
    return lp;
}