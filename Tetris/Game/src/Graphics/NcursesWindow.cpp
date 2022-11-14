#include "NcursesWindow.hpp"

#include "../Players/Player.hpp"
#include "../Board/Board.hpp"
#include "../Settings.hpp"

#include <ncurses.h>

void Draw::NcursesWindow::init()
{
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    getmaxyx(stdscr, height, width);
}

Draw::NcursesWindow::~NcursesWindow()
{
    endwin();
}

void Draw::NcursesWindow::drawMenu() const
{
    const int centerHeight = height / 2 - menu.size();
    const int centerWidth = width / 2;

    for (int i = 0; i < menu.size(); ++i)
    {
        if (i == section)
        {
            mvprintw(centerHeight + i, centerWidth, ">%s\n", menu[i].c_str());
        }
        else
        {
            mvprintw(centerHeight + i, centerWidth, " %s\n", menu[i].c_str());
        }
    }
}

void Draw::NcursesWindow::drawGame() const
{
    const int centerHeight = height / 2 - Settings::height + 10;
    const int centerWidth = width / 2 - Settings::width;

    printBoard(centerHeight, centerWidth);
    printPlayerInfo(centerHeight, centerWidth);
    printNextFigure(centerHeight, centerWidth);
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

void Draw::NcursesWindow::printPlayerInfo(const int height, const int width) const
{
    mvprintw(height + Settings::height, width, "Player: %s\n", player.getName().c_str());
    mvprintw(height + Settings::height + 1, width, "Score: %d\n", player.getScore());
}

void Draw::NcursesWindow::printBoardBottom(const int height, const int width) const
{
    mvprintw(height + Settings::height - 1, width, "T");
    for (int t = 0; t < Settings::width + 3; ++t)
    {
        addch('T');
    }
    addch('\n');
}

void Draw::NcursesWindow::printBoard(const int height, const int width) const
{
    for (int i = 0; i < Settings::height - 1; ++i)
    {
        mvprintw(height + i, width, "||");
        for (int j = 0; j < Settings::width; ++j)
        {
            addch(board.matrix[i][j]);
        }
        printw("||\n");
    }
    printBoardBottom(height, width);
}


// Need update 1!!!!!!!!!!!!!!
void Draw::NcursesWindow::printNextFigure(const int height, const int width) const
{
    char nextFigure[4][4];
    for (const auto &block : board.getNextFigure()->blocks)
    {
        const Position blockPos = block->getPos();
        nextFigure[blockPos.x][blockPos.y] = '#';
    }

    mvprintw(height + Settings::height + 3, width, "Next Figure: \n");
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (nextFigure[i][j] != '#')
                mvprintw(height + Settings::height + i + 1, width + 12 + j, " ");
            else
                mvprintw(height + Settings::height + i + 1, width + 12 + j, "%c", '#');
        }
        printw("\n");
    }
}