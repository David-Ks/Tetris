#include "IostreamWindow.hpp"
#include <iostream>

void Draw::IostreamWindow::drawMenu(unsigned &choice)
{
    if (choice > menuItemsCount)
        choice = menuItemsCount;

    for (unsigned i = 0; i < menuItemsCount; i++)
    {
        if (i == choice)
            std::cout << "Your choice = " << menuItems[i] << std::endl;
    }
}

void Draw::IostreamWindow::drawGame()
{
    map_t map = Game::map()->map;
    for (int i = 0; i < Settings::height - 1; i++)
    {
        std::cout << "||";
        for (int j = 0; j < Settings::weidth; j++)
        {
            if (map[i][j] != '#')
                std::cout << " ";
            else
                std::cout << "#";
        }
        std::cout << "||\n";
    }
    for (int t = 0; t <= Settings::weidth + 3; t++)
        std::cout << "T";
}

void Draw::IostreamWindow::clean()
{
    std::cout << "Just clean window ;)\n";
}

int Draw::IostreamWindow::input()
{
    int action;
    std::cin >> action;
    return action;
}