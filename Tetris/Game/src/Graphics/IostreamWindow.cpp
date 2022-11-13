#include "IostreamWindow.hpp"

#include "../Players/Player.hpp"
#include "../Board/Board.hpp"
#include "../Settings.hpp"

#include <iostream>

void Draw::IostreamWindow::drawMenu() const
{
    for (int i = 0; i < menu.size(); ++i)
    {
        if (i == section)
        {
            std::cout << "Your choice = " << menu[section] << std::endl;
        }
    }
}

void Draw::IostreamWindow::drawGame() const
{
    for (int i = 0; i < Settings::height - 1; ++i)
    {
        std::cout << "||";
        for (int j = 0; j < Settings::width; ++j)
        {
            if (board.map[i][j] != '#')
                std::cout << " ";
            else
                std::cout << "#";
        }
        std::cout << "||\n";
    }
    for (int t = 0; t <= Settings::width + 3; ++t)
        std::cout << "T";
}

void Draw::IostreamWindow::clean()
{
    std::cout << "Just clean window ;)\n";
}

PressedKey Draw::IostreamWindow::input()
{
    int action;
    std::cin >> action;
    return action;
}