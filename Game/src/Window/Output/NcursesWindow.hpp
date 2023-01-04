#ifndef NCRUSES_WINDOW_HPP
#define NCRUSES_WINDOW_HPP

#include "Window.hpp"
#include <ncurses.h>

class NcursesWindow : public Window
{
public:
    NcursesWindow(Settings::GameState &);
    ~NcursesWindow();

public:
    void drawPlay(const Board *, const bool bigSize) const;
    void drawPlayerVsBot(const Board *, const Board *, const bool bigSize) const;
    void drawMenu(const Sections &, int selected, const Additionl &lines = {}) const;

private:
    void printBoard(const int height, const int width, const bool bigSize, const Matrix &) const;
    void printPlayerInfo(const int height, const int width, const Player &) const;
    void printNextFigure(const int height, const int width, const Board *) const;
    void printBoardBottom(const int height, const int width, const bool isBigSize) const;

private:
    static void printBox(int x, int y, int width, int height, const std::string &title);
    static void printTimer(const int, const int, const int seconds);
};

#endif // NCRUSES_WINDOW_HPP