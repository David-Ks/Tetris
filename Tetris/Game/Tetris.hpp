#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "src/Board/Board.hpp"
#include "src/Players/Player.hpp"
#include "src/Graphics/NcursesWindow.hpp"

class Tetris
{
private:
    static User::Player player;
    static Board board;
    static Draw::Window *window;
    static bool exit;

public:
    static void quit();
    
    static void menu();
    static void game();

private:
    static bool isRunned();
};

#endif