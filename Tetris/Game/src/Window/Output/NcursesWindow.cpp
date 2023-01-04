#include "NcursesWindow.hpp"

NcursesWindow::NcursesWindow(Settings::GameState &state) : Window(state)
{
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    getmaxyx(stdscr, height, width);
    noecho();
}

NcursesWindow::~NcursesWindow()
{
    endwin();
}

void NcursesWindow::drawPlay(const Board *playerBoard, const bool isBigSize) const
{
    clear();

    const int playerBoardPosX = height / 2 - Settings::height + 10 - (isBigSize ? 10 : 0);
    const int playerBoardPosY = width / 2 - Settings::width;

    const int boxWidth = 2 * Settings::width + (isBigSize ? Settings::width - 1: 0);
    const int boxHeight = Settings::height + 10 + (isBigSize ? Settings::height * 0.8 : 0);
    const std::string boxTitle = "-=Tetris=-";

    const int timerPosX = playerBoardPosX - 1;
    const int timerPosY = playerBoardPosY + 2 + (isBigSize ? Settings::width / 2 : 0);

    printBoard(playerBoardPosX, playerBoardPosY, isBigSize, playerBoard->getMatrix());
    printPlayerInfo(playerBoardPosX + 1 + (isBigSize ? Settings::height * 0.8 + 2 : 0), playerBoardPosY + (isBigSize ? Settings::width / 2 : 0), playerBoard->getPlayer());
    printNextFigure(playerBoardPosX + 1 + (isBigSize ? Settings::height * 0.8 + 1 : 0), playerBoardPosY + (isBigSize ? Settings::width / 2 : 0), playerBoard);
    printTimer(timerPosX, timerPosY, playerBoard->getCurrentTime());
    printBox(playerBoardPosX - 7, playerBoardPosY - 6, boxWidth, boxHeight, boxTitle);

    refresh();
}

void NcursesWindow::drawPlayerVsBot(const Board *playerBoard, const Board *botBoard, const bool isBigSize) const
{
    clear();

    const int playerBoardPosX = height / 2 - Settings::height + 10 - (isBigSize ? 10 : 0);
    const int playerBoardPosY = width / 2 - Settings::width - 20;

    const int botBoardPosX = height / 2 - Settings::height + 10 - (isBigSize ? 10 : 0);
    const int botBoardPosY = width / 2 - Settings::width + 20;

    const int boxWidth =  Settings::width * 5 - 1 + (isBigSize ? Settings::width - 2: 0);
    const int boxHeight = Settings::height + 10 + (isBigSize ? Settings::height * 0.8 : 0);
    const std::string boxTitle = "-=Tetris=-";

    const int timerPosX = playerBoardPosX - 1;
    const int timerPosY = playerBoardPosY + 2;

    printBoard(playerBoardPosX, playerBoardPosY, isBigSize, playerBoard->getMatrix());
    printPlayerInfo(playerBoardPosX + 1 + (isBigSize ? Settings::height * 0.8 + 2 : 0), playerBoardPosY + (isBigSize ? Settings::width / 2 : 0), playerBoard->getPlayer());
    printNextFigure(playerBoardPosX + 1 + (isBigSize ? Settings::height * 0.8 + 1 : 0), playerBoardPosY + (isBigSize ? Settings::width / 2 : 0), playerBoard);

    printBoard(botBoardPosX, botBoardPosY, isBigSize, botBoard->getMatrix());
    printPlayerInfo(botBoardPosX + 1 + (isBigSize ? Settings::height * 0.8 + 2 : 0), botBoardPosY + (isBigSize ? Settings::width / 2 : 0), botBoard->getPlayer());
    printNextFigure(botBoardPosX + 1 + (isBigSize ? Settings::height * 0.8 + 1 : 0), botBoardPosY + (isBigSize ? Settings::width / 2 : 0), botBoard);

    printTimer(timerPosX + (isBigSize ? Settings::height * 2 + 2 : 0), timerPosY + (isBigSize ? Settings::width * 1.9: 0), playerBoard->getCurrentTime());
    printBox(playerBoardPosX - 7, playerBoardPosY - 6, boxWidth, boxHeight, boxTitle);

    refresh();
}

void NcursesWindow::drawMenu(const Sections &sections, int selected, const Additionl &additionlLines) const
{
    clear();

    const int additionHeight = additionlLines.size() > 10 ? 10 : additionlLines.size();

    const int centerHeight = height / 2 - sections.size();
    const int centerWidth = width / 2 - 5;

    const int boxWidth = 20;
    const int boxHeight = 10 + additionHeight / 2;
    const std::string boxTitle = "-=Tetris=-";

    for (int i = 0; i < additionHeight; ++i)
    {
        const auto data = Player::getPlayerDataFromLine(additionlLines[i]);
        const auto recordInString = data[1];
        mvprintw(centerHeight + i, centerWidth, "%d) %s", i + 1, recordInString.c_str());
    }

    for (int i = 0; i < (int)sections.size(); ++i)
    {
        if (selected == i)
        {
            mvprintw(centerHeight + 1 + additionHeight + i, centerWidth, ">%s\n", sections[i].c_str());
        }
        else
        {
            mvprintw(centerHeight + 1 + additionHeight + i, centerWidth, " %s\n", sections[i].c_str());
        }
    }
    printBox(centerHeight - 6, centerWidth - 4, boxWidth, boxHeight, boxTitle);

    refresh();
}


void NcursesWindow::printBoard(const int height, const int width, const bool isBigSize, const Matrix &matrix) const
{
    int rowRepeat = 1;
    if (isBigSize)
        rowRepeat = 2;

    for (int i = 0; i < ((int)matrix.size() - 1) * rowRepeat; ++i)
    {
        mvprintw(height + i, width, "||");
        for (int j = 0; j < ((int)matrix[i / rowRepeat].size() - 1); ++j)
        {
            addch(matrix[i / rowRepeat][j]);
            if (isBigSize)
                addch(matrix[i / rowRepeat][j]);
        }
        printw("||");
    }

    printBoardBottom(height, width, isBigSize);
}

void NcursesWindow::printBoardBottom(const int height, const int width, const bool isBigSize) const
{
    int bottomWidth = Settings::width + 2;
    int startHeight = height + (Settings::height - 1);
    if (isBigSize)
    {
        startHeight = height + (Settings::height - 1) * 2;
        bottomWidth = Settings::width * 2 + 1;
    }
    mvprintw(startHeight, width, "T");

    for (int t = 0; t < bottomWidth; ++t)
    {
        addch('T');
    }
    addch('\n');
}

void NcursesWindow::printPlayerInfo(int centerHeight, int centerWidth, const Player &player) const
{
    int infoHeight = centerHeight + Settings::height;
    if (isBigSize)
    {
        infoHeight = centerHeight + (Settings::height - 1) * 2;
    }
    mvprintw(infoHeight, centerWidth, "Name: %s\n", player.getName().c_str());
    mvprintw(infoHeight + 1, centerWidth, "Score: %d\n", player.getScore());
}

void NcursesWindow::printNextFigure(int centerHeight, int centerWidth, const Board *board) const
{
    const auto nextFigureBlocksPositions = board->getNextFigure()->getBlocksPositions();
    const char symbol = board->getNextFigure()->getSymbol();
    mvprintw(centerHeight + Settings::height + 3, centerWidth, "Next Figure: \n");
    for (const auto &blockPosition : nextFigureBlocksPositions)
    {
        mvprintw(centerHeight + Settings::height + blockPosition.x + 1, centerWidth + 12 + blockPosition.y, "%c", symbol);
    }
}

void NcursesWindow::printBox(int x, int y, int width, int height, const std::string &title)
{
    constexpr int titleBarHeight = 4;

    // Row
    mvprintw(x, y, "+");
    for (int i = 1; i < width; ++i)
    {
        mvprintw(x, y + i, "-");
    }
    mvprintw(x, y + width, "+");

    // Columns
    for (int i = 1; i < titleBarHeight; ++i)
    {
        mvprintw(x + i, y, "|");
        mvprintw(x + i, y + width, "|");
    }

    // Title
    mvprintw(x + titleBarHeight / 2, y + (width - (int)title.size()) / 2 + 1, "%s", title.c_str());

    // Title Bottom
    mvprintw(x + titleBarHeight, y, "+");
    for (int i = 1; i < width; ++i)
    {
        mvprintw(x + titleBarHeight, y + i, "-");
    }
    mvprintw(x + titleBarHeight, y + width, "+");

    // Columns
    for (int i = 1; i < height; ++i)
    {
        mvprintw(x + i + titleBarHeight, y, "|");
        mvprintw(x + i + titleBarHeight, y + width, "|");
    }

    // Row
    mvprintw(x + height + titleBarHeight, y, "+");
    for (int i = 1; i < width; ++i)
    {
        mvprintw(x + height + titleBarHeight, y + i, "-");
    }
    mvprintw(x + height + titleBarHeight, y + width, "+");
}

void NcursesWindow::printTimer(const int height, const int width, const int seconds)
{
    const int min = seconds / 60;
    const int sec = seconds - (min * 60);
    mvprintw(height, width, "Timer [%02d:%02d]", min, sec);
}
