#include "NcursesWindow.hpp"

Draw::NcursesWindow::NcursesWindow()
{
    window = initscr();
    curs_set(0);
    keypad(stdscr, true);
    getmaxyx(stdscr, hight, weidth);
}

Draw::NcursesWindow::~NcursesWindow()
{
    endwin();
}

void Draw::NcursesWindow::drawMenu()
{
    int menuItemsMaxLength = 10;
    int centerHight = hight / 2 - menu.size();
    int centerWeidth = weidth / 2 - menuItemsMaxLength;

    for (int i = 0; i < menu.size(); ++i)
    {
        mvprintw(centerHight + i, centerWeidth, " ");

        if (i == section)
            addch('>');
        else
            addch(' ');

        printw("%s\n", menu[i].c_str());
    }
}

void Draw::NcursesWindow::drawGame()
{
    MapMatrix map = Map::board().map;

    int centerHight = hight / 2 - Settings::height + 10;
    int centerWeidth = weidth / 2 - Settings::weidth;

    for (int i = 0; i < Settings::height - 1; ++i)
    {
        mvprintw(centerHight + i, centerWeidth, "||");
        for (int j = 0; j < Settings::weidth; ++j)
        {
            if (map[i][j] == '#')
                printw("%c", '#');
            else
                printw(" ");
        }
        printw("||\n");
    }

    mvprintw(centerHight + Settings::height - 1, centerWeidth, "T");
    for (int t = 0; t < Settings::weidth + 3; ++t)
        printw("T");

    printw("\n");

    mvprintw(centerHight + Settings::height, centerWeidth, "Player: %s\n", User::player().getName().c_str());
    mvprintw(centerHight + Settings::height + 1, centerWeidth, "Score: %d\n", User::player().getScore());

    char nextFigure[4][4];
    for (auto &block : Map::board().getNextFigure()->blocks)
    {
        Position blockPos = block->getPos();
        nextFigure[blockPos.x][blockPos.y] = '#';
    }

    mvprintw(centerHight + Settings::height + 3, centerWeidth, "Next Figure: \n");
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (nextFigure[i][j] != '#')
                mvprintw(centerHight + Settings::height + i + 1, centerWeidth + 12 + j, " ");
            else
                mvprintw(centerHight + Settings::height + i + 1, centerWeidth + 12 + j, "%c", '#');
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