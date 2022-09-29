#include "DownCommand.hpp"

bool Action::Menu::DownCommand::isAvailable()
{
    int current = static_cast<int>(Draw::window()->getSection());
    if (current + 1 < Draw::window()->menuItems.size())
    {
        return true;
    }
    return false;
}

bool Action::Menu::DownCommand::execute()
{
    int current = static_cast<int>(Draw::window()->getSection());
    Draw::window()->setSection(static_cast<Draw::Section>(current + 1));
    return true;
}