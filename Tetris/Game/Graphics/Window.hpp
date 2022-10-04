#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <string>

#include "../Players/Player.hpp"

using PressedKey = int;
using MenuList = std::vector<std::string>;

namespace Draw
{
    enum Section
    {
        PLAY = 0,
        SETTINGS,
        RECORDS,
        EXIT
    };

    class Window
    {
    protected:
        Section section;
    
    public:
        static const MenuList menu;

    public:
        Window() : section(Section::PLAY) {}
        virtual ~Window() {}

    public:
        virtual void drawMenu() = 0;
        virtual void drawGame() = 0;
        virtual void clean() = 0;
        virtual PressedKey input() = 0;
    
    public:
        void setSection(Section section) { this->section = section; }
        Section getSection() { return section; }
    };

    const MenuList Window::menu = {
        "Play",
        "Settings",
        "Records",
        "Exit"
    };

    Window *window();
} // namespace Draw

#endif