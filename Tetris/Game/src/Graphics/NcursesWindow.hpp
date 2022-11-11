#ifndef NCURSES_WINDOW_HPP
#define NCURSES_WINDOW_HPP

#include "Window.hpp"

namespace Draw
{
    class NcursesWindow : public Window
    {
    private:
        int hight;
        int width;
        
    public:
        NcursesWindow();
        ~NcursesWindow();
    
    public:
        void drawMenu();
        void drawGame();
        void clean();
        PressedKey input();
    };
} // namespace Draw

#endif