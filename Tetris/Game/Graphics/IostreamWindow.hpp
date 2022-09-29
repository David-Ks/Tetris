#ifndef IOSTREAM_WINDOW_H
#define IOSTREAM_WINDOW_H

#include <iostream>

#include "Window.hpp"

namespace Draw
{
    class IostreamWindow : public Window
    {
    public:
        IostreamWindow() {};
        ~IostreamWindow() {};
    
    public:
        void drawMenu();
        void drawGame();
        void clean();
        PressedKey input();
    };
} // namespace Draw

#endif