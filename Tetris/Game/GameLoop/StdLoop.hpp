#ifndef STD_LOOP_H
#define STD_LOOP_H

#include "Loop.hpp"

class StdLoop : public Loop
{
public:
    StdLoop(Player *player);
    ~StdLoop();

public:
    void menu(Draw::Window *win, Listen::Event *event);
    void game(Draw::Window *win, Listen::Event *event);
};

#endif