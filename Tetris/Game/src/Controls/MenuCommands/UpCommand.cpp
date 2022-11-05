#include "UpCommand.hpp"
#include "../../Graphics/Window.hpp"

bool Action::Menu::UpCommand::isAvailable() const
{
    const int menuCurrentSectionNumber = static_cast<int>(Draw::window()->getSection());

    if (menuCurrentSectionNumber - 1 >= 0)
    {
        return true;
    }
    return false;
}

bool Action::Menu::UpCommand::execute()
{
    int menuCurrentSectionNumber = static_cast<int>(Draw::window()->getSection());

    Draw::window()->setSection(static_cast<Draw::Section>(menuCurrentSectionNumber - 1));
    return true;
}