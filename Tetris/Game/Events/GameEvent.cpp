#include "GameEvent.hpp"
#include "../Controls/DropCommand.cpp"
#include "../Controls/LeftCommand.cpp"
#include "../Controls/RightCommand.cpp"
#include "../Controls/RotateCommand.cpp"

void Listen::GameEvent::handler(unsigned &choice, Map::Board *map)
{
    Action::Command *action;

    Object::Figure *activeFigure = map->figures[map->figures.size() - 1];

    int x;
    if (choice == 661) // auto down
        x = 2;
    else
        x = this->get();

    switch (x)
    {
    case 3: // Up
        action = new Action::RotateCommand(activeFigure);
        if (action->isAvailable(map->map))
            action->execute();
        break;

    case 2: // Down
        action = new Action::DropCommand(activeFigure);
        if (action->isAvailable(map->map))
            action->execute();
        else
        {
            map->addFigure();
            map->lineCheck();
        }
        break;

    case 4: // Left
        action = new Action::LeftCommand(activeFigure);
        if (action->isAvailable(map->map))
            action->execute();
        break;

    case 5: // Right
        action = new Action::RightCommand(activeFigure);
        if (action->isAvailable(map->map))
            action->execute();
        break;

    case 10:          // Enter
        choice = 666; // exit code
    }
}