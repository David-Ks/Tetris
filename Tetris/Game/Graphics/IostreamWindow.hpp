#ifndef IOSTREAM_WINDOW_H
#define IOSTREAM_WINDOW_H

#include <string>
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
        int input();
    };
} // namespace Draw

#endif