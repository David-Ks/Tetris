#ifndef WINDOW_H
#define WINDOW_H

#include "../Settings.hpp"

namespace Draw
{
    class Window
    {
    public:
        Window() {}
        virtual ~Window() {}

    public:
        virtual void menu(unsigned &choice) = 0;
        virtual void game(Map::Board *board) = 0;
        
        virtual void winClear() = 0;
        virtual int input() = 0;
    };
} // namespace Draw

#endif