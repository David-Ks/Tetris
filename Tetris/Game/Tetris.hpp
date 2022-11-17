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
    static bool exit;

public:
    static void quit();
    
    static void menu();
    static void game(const Draw::Window *window);

private:
    static void setPlayer(const Draw::Window *window);
    static void settings(const Draw::Window *window);
    static void records(const Draw::Window *window);

private:
    static bool isRunned();
};

#endif