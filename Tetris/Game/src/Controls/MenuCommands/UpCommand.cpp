#include "UpCommand.hpp"
#include "../../Graphics/Window.hpp"

bool Action::Menu::UpCommand::isAvailable() const
{
    const int menuCurrentSectionNumber = static_cast<int>(window->getSection());

    if (menuCurrentSectionNumber - 1 >= 0)
    {
        return true;
    }
    return false;
}

bool Action::Menu::UpCommand::execute()
{
    const int menuCurrentSectionNumber = static_cast<int>(window->getSection());
    window->setSection(static_cast<Draw::Section>(menuCurrentSectionNumber - 1));
    return true;
}