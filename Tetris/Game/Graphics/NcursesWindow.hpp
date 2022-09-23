#ifndef NCURSES_WINDOW_H
#define NCURSES_WINDOW_H

#include <ncurses.h>
#include <string>
#include "Window.hpp"

namespace Draw
{
    class NcursesWindow : public Window
    {
    private:
        int hight;
        int weidth;

        WINDOW *window;

        static const int menuItemsCount = 3;
        const std::string menuItems[menuItemsCount] = {
            "Play",
            "Records",
            "Exit",
        };
    public:
        NcursesWindow();
        ~NcursesWindow();
    
    public:
        void drawMenu(unsigned &choice);
        void drawGame();
        void clean();
        int input();
    };
} // namespace Draw

#endif