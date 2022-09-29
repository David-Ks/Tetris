#include "SelectCommand.hpp"
#include "../../GameLoop/Loop.hpp"

bool Action::Menu::SelectCommand::isAvailable()
{
    return true;
}

bool Action::Menu::SelectCommand::execute()
{
    Draw::Section current = Draw::window()->getSection();
    
    switch (current)
    {
    case Draw::Section::PLAY:
        GameLoop::loop().game();
        break;
    }

    return true;
}