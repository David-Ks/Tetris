#ifndef LOOP_H
#define LOOP_H

#include "../Settings.hpp"
#include "../Events/MenuEvent.hpp"
#include "../Events/GameEvent.hpp"

class Loop
{
private:
    Map::Board *map;
    Player * player;
public:
    Loop(Player *player);
    ~Loop();

public:
    void menu(Draw::Window *win, Listen::Event *event);
    void game(Draw::Window *win, Listen::Event *event);
};

#endif