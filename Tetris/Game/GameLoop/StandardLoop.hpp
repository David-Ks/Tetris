#ifndef STD_LOOP_H
#define STD_LOOP_H

#include "Loop.hpp"

class StandardLoop : public Loop
{
public:
    StandardLoop(Player *player);
    ~StandardLoop();

public:
    void menu(Draw::Window *win, Listen::Event *event);
    void game(Draw::Window *win, Listen::Event *event);
};

#endif