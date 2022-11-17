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
Draw::Window *Tetris::window = new Draw::NcursesWindow(board, player);

void Tetris::menu()
{
    std::unique_ptr<EventSystem::KeyBoardEvent> event(new EventSystem::KeyBoardEvent);

    event->addListener(EventSystem::KEY::UP,    new Action::Menu::UpCommand(window, board));
    event->addListener(EventSystem::KEY::DOWN,  new Action::Menu::DownCommand(window, board));
    event->addListener(EventSystem::KEY::ENTER, new Action::Menu::SelectCommand(window, board));

    while (isRunned())
    {
        window->clean();
        window->drawMenu();

        event->invoke(static_cast<EventSystem::KEY>(window->input()));
    }

    event->delAllListeners();
    delete window;
}

void Tetris::game()
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
        board.update();

        if (board.isGameOver())
            break;

        // Auto drop down and check If can't do it
        if (!event->invoke(EventSystem::KEY::DOWN))
            boardScript->update();
        board.update();
    }

    board.theEndOfGame();
    board.update();

    event->delAllListeners();
    player.saveScore();
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