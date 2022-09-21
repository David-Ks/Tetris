#ifndef IOSTREAM_WINDOW_H
#define IOSTREAM_WINDOW_H

#include <string>
#include "Window.hpp"

namespace Draw
{
    class IostreamWindow : public Window
    {
    private:
        int hight;
        int weidth;

        static const int menuItemsCount = 3;
        const std::string menuItems[menuItemsCount] = {
            "Play",
            "Records",
            "Exit",
        };
    public:
        IostreamWindow() {};
        ~IostreamWindow() {};
    
    public:
        void menu(unsigned &choice);
        void game(Map::Board *board);

        void winClear();
        int input();
    };
} // namespace Draw

#endif