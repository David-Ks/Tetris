#ifndef TETRIS_H
#define TETRIS_H

#include "Game/Settings.hpp"

class Tetris
{
private:
    Draw::Window *window;
    Map::Board *map;
    Player *player;
    Loop *loop;

public:
    Tetris();
    ~Tetris();

public:
    void run();
};

#endif