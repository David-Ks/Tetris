#include "NcursesWindow.hpp"
#include "../Players/Player.hpp"
#include "../Board/Board.cpp"
#include "../Settings.cpp"

#include <ncurses.h>

Draw::NcursesWindow::NcursesWindow()
{
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    getmaxyx(stdscr, hight, width);
}

Draw::NcursesWindow::~NcursesWindow()
{
    endwin();
}

void Draw::NcursesWindow::drawMenu()
{
    int menuItemsMaxLength = 10;
    int centerHight = hight / 2 - menu.size();
    int centerWidth = width / 2 - menuItemsMaxLength;

    for (int i = 0; i < menu.size(); ++i)
    {
        mvprintw(centerHight + i, centerWidth, " ");

        if (i == section)
            addch('>');
        else
            addch(' ');

        printw("%s\n", menu[i].c_str());
    }
}

void Draw::NcursesWindow::drawGame()
{
    BoardMatrix map = board().map;

    int centerHight = hight / 2 - Settings::hight + 10;
    int centerWidth = width / 2 - Settings::width;

    for (int i = 0; i < Settings::hight - 1; ++i)
    {
        mvprintw(centerHight + i, centerWidth, "||");
        for (int j = 0; j < Settings::width; ++j)
        {
            if (map[i][j] == '#')
                printw("%c", '#');
            else
                printw(" ");
        }
        printw("||\n");
    }

    mvprintw(centerHight + Settings::hight - 1, centerWidth, "T");
    for (int t = 0; t < Settings::width + 3; ++t)
        printw("T");

    printw("\n");

    mvprintw(centerHight + Settings::hight, centerWidth, "Player: %s\n", User::player().getName().c_str());
    mvprintw(centerHight + Settings::hight + 1, centerWidth, "Score: %d\n", User::player().getScore());

    char nextFigure[4][4];
    for (auto &block : board().getNextFigure()->blocks)
    {
        Position blockPos = block->getPos();
        nextFigure[blockPos.x][blockPos.y] = '#';
    }

    mvprintw(centerHight + Settings::hight + 3, centerWidth, "Next Figure: \n");
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (nextFigure[i][j] != '#')
                mvprintw(centerHight + Settings::hight + i + 1, centerWidth + 12 + j, " ");
            else
                mvprintw(centerHight + Settings::hight + i + 1, centerWidth + 12 + j, "%c", '#');
        }
        printw("\n");
    }
}

void Draw::NcursesWindow::clean()
{
    clear();
    refresh();
}

PressedKey Draw::NcursesWindow::input()
{
    halfdelay(5);
    char ch = getch();
    return ch;
}