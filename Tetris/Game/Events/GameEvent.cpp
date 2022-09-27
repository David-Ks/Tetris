#include "GameEvent.hpp"
#include "../Controls/DropCommand.cpp"
#include "../Controls/LeftCommand.cpp"
#include "../Controls/RightCommand.cpp"
#include "../Controls/RotateCommand.cpp"

void Listen::GameEvent::handler(unsigned &choice)
{
    Action::Command *action;

    Object::Figure *activeFigure = Map::board().figures.back();

    int actionCode;
    if (choice == 661) // auto down
        actionCode = 2;
    else
        actionCode = this->getKey();

    switch (actionCode)
    {
    case 3: // Up
        action = new Action::RotateCommand(activeFigure);
        if (action->isAvailable(Map::board().map))
            action->execute();
        break;

    case 2: // Down
        action = new Action::DropCommand(activeFigure);
        if (action->isAvailable(Map::board().map))
            action->execute();
        else
        {
            Map::board().addFigure();
            Map::board().lineCheck();
        }
        break;

    case 4: // Left
        action = new Action::LeftCommand(activeFigure);
        if (action->isAvailable(Map::board().map))
            action->execute();
        break;

    case 5: // Right
        action = new Action::RightCommand(activeFigure);
        if (action->isAvailable(Map::board().map))
            action->execute();
        break;

    case 10:         // Enter // exit code
        Map::board().theEndOfGame();
    }
}