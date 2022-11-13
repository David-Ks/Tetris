#ifndef NCURSES_WINDOW_HPP
#define NCURSES_WINDOW_HPP

#include "Window.hpp"
#include "../Players/Player.hpp"
#include "../Board/Board.hpp"

namespace Draw
{
    class NcursesWindow : public Window
    {
    private:
        int height;
        int width;
        
    public:
        NcursesWindow(const Board &board, const User::Player &player) : Window(board, player) { init(); }
        ~NcursesWindow();
    
    public:
        void init();
        void drawMenu() const;
        void drawGame() const;
        void clean();
        PressedKey input();

    private:
        void printPlayerInfo(const int height, const int width) const;
        void printBoardBottom(const int height, const int width) const;
        void printBoard(const int height, const int width) const;
        void printNextFigure(const int height, const int width) const;
    };
} // namespace Draw

#endif