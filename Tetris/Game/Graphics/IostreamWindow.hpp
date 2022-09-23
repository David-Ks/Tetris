#ifndef IOSTREAM_WINDOW_H
#define IOSTREAM_WINDOW_H

#include <string>
#include <iostream>

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
        void drawMenu(unsigned &choice);
        void drawGame();
        void clean();
        int input();
    };
} // namespace Draw

#endif