#include "SelectCommand.hpp"

bool Action::Menu::SelectCommand::isAvailable()
{
    return true;
}

bool Action::Menu::SelectCommand::execute()
{
    Draw::Section menuCurrentSection = Draw::window()->getSection();
    
    switch (menuCurrentSection)
    {
    case Draw::Section::PLAY:
        GameLoop::loop().game();
        break;
    case Draw::Section::EXIT:
        GameLoop::loop().quite();
        break;
    }

    return true;
}