#include "GameEvent.hpp"
#include "../Controls/DropCommand.cpp"
#include "../Controls/LeftCommand.cpp"
#include "../Controls/RightCommand.cpp"
#include "../Controls/RotateCommand.cpp"

void Listen::GameEvent::handler(unsigned &choice)
{
    Action::Command *action;

    Object::Figure *activeFigure = Game::map()->figures[Game::map()->figures.size() - 1];

    int x;
    if (choice == 661) // auto down
        x = 2;
    else
        x = this->getKey();

    switch (x)
    {
    case 3: // Up
        action = new Action::RotateCommand(activeFigure);
        if (action->isAvailable(Game::map()->map))
            action->execute();
        break;

    case 2: // Down
        action = new Action::DropCommand(activeFigure);
        if (action->isAvailable(Game::map()->map))
            action->execute();
        else
        {
            Game::map()->addFigure();
            Game::map()->lineCheck();
        }
        break;

    case 4: // Left
        action = new Action::LeftCommand(activeFigure);
        if (action->isAvailable(Game::map()->map))
            action->execute();
        break;

    case 5: // Right
        action = new Action::RightCommand(activeFigure);
        if (action->isAvailable(Game::map()->map))
            action->execute();
        break;

    case 10:          // Enter
        choice = 666; // exit code
    }
}