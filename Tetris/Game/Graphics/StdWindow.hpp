#ifndef STD_WINDOW_H
#define STD_WINDOW_H

#include <string>
#include "Window.hpp"

namespace Draw
{
    class StdWindow : public Window
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
        StdWindow() {};
        ~StdWindow() {};
    
    public:
        void menu(unsigned &choice);
        void game(Map::Board *board);

        void winClear();
        int input();
    };
} // namespace Draw

#endif