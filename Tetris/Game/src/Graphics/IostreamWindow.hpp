#ifndef IOSTREAM_WINDOW_HPP
#define IOSTREAM_WINDOW_HPP

#include "Window.hpp"
#include "../Board/Board.hpp"
#include "../Players/Player.hpp"

namespace Draw
{
    class IostreamWindow : public Window
    {
    public:
        IostreamWindow(const Board &board, const User::Player &player) : Window(board, player) { init(); }
    
    public:
        void drawMenu() const;
        void drawGame() const;
        void clean();
        PressedKey input();
    };
} // namespace Draw

#endif