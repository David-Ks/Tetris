#include "UpCommand.hpp"

bool Action::Menu::UpCommand::isAvailable()
{
    int current = static_cast<int>(Draw::window()->getSection());
    if (current - 1 >= 0)
    {
        return true;
    }
    return false;
}

bool Action::Menu::UpCommand::execute()
{
    int current = static_cast<int>(Draw::window()->getSection());
    Draw::window()->setSection(static_cast<Draw::Section>(current - 1));
    return true;
}