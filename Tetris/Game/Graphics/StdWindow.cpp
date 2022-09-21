#include "StdWindow.hpp"
#include <iostream>

void Draw::StdWindow::menu(unsigned &choice)
{
    if (choice > menuItemsCount)
        choice = menuItemsCount;

    for (unsigned i = 0; i < menuItemsCount; i++)
    {
        if (i == choice)
            std::cout << "Your choice = " << menuItems[i] << std::endl;
    }
}

void Draw::StdWindow::game(Map::Board *board)
{
    map_t map = board->map;
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

void Draw::StdWindow::winClear()
{
    std::cout << "Just clean window ;)\n";
}

int Draw::StdWindow::input()
{
    int action;
    std::cin >> action;
    return action;
}