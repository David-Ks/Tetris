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
        //GameLoop::loop().game();
        Tetris::game();
        break;
    case Draw::Section::EXIT:
        // GameLoop::loop().quite();
        Tetris::quit();
        break;
    }

    return true;
}