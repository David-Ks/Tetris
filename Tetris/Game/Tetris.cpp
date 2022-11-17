#include "Tetris.hpp"

// ---------- Menu_------------------
#include "src/Events/KeyBoardEvent.hpp"
#include "src/Controls/MenuCommands/DownCommand.hpp"
#include "src/Controls/MenuCommands/UpCommand.hpp"
#include "src/Controls/MenuCommands/SelectCommand.hpp"

// ---------- Game ------------------
#include "src/Scripts/BoardScript.hpp"
#include "src/Controls/GameCommands/RotateCommand.hpp"
#include "src/Controls/GameCommands/DropCommand.hpp"
#include "src/Controls/GameCommands/LeftCommand.hpp"
#include "src/Controls/GameCommands/RightCommand.hpp"

#include <memory>

bool Tetris::exit = false;

User::Player Tetris::player;
Board Tetris::board;

void Tetris::menu()
{
    std::unique_ptr<Draw::Window> window(new Draw::NcursesWindow(board, player));
    std::unique_ptr<EventSystem::KeyBoardEvent> event(new EventSystem::KeyBoardEvent);

    event->addListener(EventSystem::KEY::UP,    new Action::Menu::UpCommand(window.get(), board));
    event->addListener(EventSystem::KEY::DOWN,  new Action::Menu::DownCommand(window.get(), board));
    event->addListener(EventSystem::KEY::ENTER, new Action::Menu::SelectCommand(window.get(), board));

    while (isRunned())
    {
        window->clean();
        window->drawMenu();

        event->invoke(static_cast<EventSystem::KEY>(window->input()));
    }

    event->delAllListeners();
}

void Tetris::game(const Draw::Window *window)
{
    std::unique_ptr<EventSystem::Event> event(new EventSystem::KeyBoardEvent);
    std::unique_ptr<Script> boardScript(new BoardScript(board, player));

    event->addListener(EventSystem::KEY::UP,    new Action::Game::RotateCommand(board));
    event->addListener(EventSystem::KEY::DOWN,  new Action::Game::DropCommand(board));
    event->addListener(EventSystem::KEY::LEFT,  new Action::Game::LeftCommand(board));
    event->addListener(EventSystem::KEY::RIGHT, new Action::Game::RightCommand(board));

    boardScript->start();
    while (!board.isGameOver())
    {
        window->clean();
        window->drawGame();

        event->invoke(static_cast<EventSystem::KEY>(window->input()));

        if (board.isGameOver())
            break;

        // Auto drop down and check If can't do it
        if (!event->invoke(EventSystem::KEY::DOWN))
            boardScript->update();
    }

    player.saveScore();
    board.theEndOfGame();

    event->delAllListeners();
}

void Tetris::records(const Draw::Window *window)
{
    std::unique_ptr<EventSystem::Event> event(new EventSystem::KeyBoardEvent);

    event->addListener(EventSystem::KEY::UP,    new Action::Menu::UpCommand(window, board));
    event->addListener(EventSystem::KEY::DOWN,  new Action::Menu::DownCommand(window, board));
    event->addListener(EventSystem::KEY::ENTER, new Action::Menu::SelectCommand(window, board));

    while (isRunned())
    {
        window->clean();
        window->drawRecrodList();

        event->invoke(static_cast<EventSystem::KEY>(window->input()));
    }

    event->delAllListeners();
}

bool Tetris::isRunned()
{
    if (exit)
    {
        return false;
    }
    return true;
}

void Tetris::quit()
{
    exit = true;
}