#ifndef IOSTREAM_WINDOW_HPP
#define IOSTREAM_WINDOW_HPP

#include "Window.hpp"

namespace Draw
{
    class IostreamWindow : public Window
    {
    public:
        IostreamWindow() {}
    
    public:
        void drawMenu();
        void drawGame();
        void clean();
        PressedKey input();
    };
} // namespace Draw

#endif