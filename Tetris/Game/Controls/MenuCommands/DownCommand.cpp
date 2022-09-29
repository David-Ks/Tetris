#include "DownCommand.hpp"

bool Action::Menu::DownCommand::isAvailable()
{
    int menuCurrentSectionNumber = static_cast<int>(Draw::window()->getSection());

    if (menuCurrentSectionNumber + 1 < Draw::window()->menu.size())
    {
        return true;
    }
    return false;
}

bool Action::Menu::DownCommand::execute()
{
    int menuCurrentSectionNumber = static_cast<int>(Draw::window()->getSection());

    Draw::window()->setSection(static_cast<Draw::Section>(menuCurrentSectionNumber + 1));
    return true;
}