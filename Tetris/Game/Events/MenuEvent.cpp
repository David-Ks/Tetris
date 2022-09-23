#include "MenuEvent.hpp"

void Listen::MenuEvent::handler(unsigned &choice)
{
    switch (this->getKey())
    {
    case 3: // Up
        if (choice)
            choice--;
        break;
    case 2: // Down
        choice++;
        break;
    case 10:              // Enter
        if (choice == 0)
            choice = 777; // Play code
        else if (choice == 1)
            choice = 778; // Records code
        else
            choice = 666; // exit code
    }
}