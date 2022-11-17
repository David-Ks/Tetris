#include "SelectCommand.hpp"
#include "../../Graphics/Window.hpp"
#include "../../../Tetris.hpp"

bool Action::Menu::SelectCommand::isAvailable() const
{
    return true;
}

bool Action::Menu::SelectCommand::execute()
{
    Draw::Section menuCurrentSection = window->getSection();
    
    switch (menuCurrentSection)
    {
    case Draw::Section::PLAY:
        Tetris::game(window);
        break;
    case Draw::Section::EXIT:
        Tetris::quit();
        break;
    }

    return true;
}