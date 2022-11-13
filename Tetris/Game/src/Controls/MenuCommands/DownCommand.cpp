#include "DownCommand.hpp"
#include "../../Graphics/Window.hpp"

bool Action::Menu::DownCommand::isAvailable() const
{
    const int menuCurrentSectionNumber = static_cast<int>(window->getSection());

    if (menuCurrentSectionNumber + 1 < window->menu.size())
    {
        return true;
    }
    return false;
}

bool Action::Menu::DownCommand::execute()
{
    int menuCurrentSectionNumber = static_cast<int>(window->getSection());

    window->setSection(static_cast<Draw::Section>(menuCurrentSectionNumber + 1));
    return true;
}