#include <memory>

#include "Loop.hpp"
#include "../Controls/MenuCommands/SelectCommand.cpp"

void GameLoop::Loop::menu()
{
    std::unique_ptr<EventSystem::KeyBoardEvent> event(new EventSystem::KeyBoardEvent);

    event->addListener(EventSystem::KEY::UP, new Action::Menu::UpCommand);
    event->addListener(EventSystem::KEY::DOWN, new Action::Menu::DownCommand);
    event->addListener(EventSystem::KEY::ENTER, new Action::Menu::SelectCommand);

    while (!exit)
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

    event->addListener(EventSystem::KEY::UP, new Action::Game::RotateCommand);
    event->addListener(EventSystem::KEY::DOWN, new Action::Game::DropCommand);
    event->addListener(EventSystem::KEY::LEFT, new Action::Game::LeftCommand);
    event->addListener(EventSystem::KEY::RIGHT, new Action::Game::RightCommand);

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

        // Auto drop down and check If can't do it
        if (!event->invoke(EventSystem::KEY::DOWN))
        {
            Map::board().addFigure();
            Map::board().lineCheck();
        }

        Map::board().update();
    }

    event->delAllListeners();

    // player->saveScore() and set 0
}

void GameLoop::Loop::quite() 
{ 
    exit = true; 
}

GameLoop::Loop &GameLoop::loop()
{
    static GameLoop::Loop lp;
    return lp;
}