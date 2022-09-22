#include "NcursesWindow.hpp"

Draw::NcursesWindow::NcursesWindow()
{
    this->window = initscr();
    curs_set(0);
    keypad(stdscr, true);
    getmaxyx(stdscr, hight, weidth);
}

Draw::NcursesWindow::~NcursesWindow()
{
    endwin();
}

void Draw::NcursesWindow::menu(unsigned &choice)
{
    int centerHight = hight / 2 - menuItemsCount;
    int centerWeidth = weidth / 2 - 10; // 10-is menu items max length

    if (choice >= menuItemsCount - 1)
        choice = menuItemsCount - 1;

    for (unsigned i = 0; i < menuItemsCount; i++)
    {
        mvprintw(centerHight + i, centerWeidth, " ");

        if (i == choice)
            addch('>');
        else
            addch(' ');

        printw("%s\n", menuItems[i].c_str());
    }
}

void Draw::NcursesWindow::game(Map::Board *board)
{
    map_t map = board->map;
    int centerHight = hight / 2 - Settings::height + 10;
    int centerWeidth = weidth / 2 - Settings::weidth; // 10-is menu items max length

    for (int i = 0; i < Settings::height - 1; i++)
    {
        mvprintw(centerHight + i, centerWeidth, "||");
        for (int j = 0; j < Settings::weidth; j++)
        {
            if (map[i][j] != '#')
                printw(" ");
            else
                printw("%c", '#');
        }
        printw("||\n");
    }

    mvprintw(centerHight + Settings::height - 1, centerWeidth, "T");
    for (int t = 0; t < Settings::weidth + 3; t++)
        printw("T");

    printw("\n");
    mvprintw(centerHight + Settings::height, centerWeidth, "Player: %s\n", board->getPlayer()->getName().c_str());
    mvprintw(centerHight + Settings::height + 1, centerWeidth,"Score: %d\n", board->getPlayer()->getScore());
}

void Draw::NcursesWindow::winClear()
{
    clear();
    refresh();
}

int Draw::NcursesWindow::input()
{
    halfdelay(5);
    char ch = getch();
    return ch;
}