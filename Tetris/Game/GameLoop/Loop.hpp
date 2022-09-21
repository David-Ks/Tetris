#ifndef LOOP_H
#define LOOP_H

#include "../Graphics/Window.hpp"
#include "../Events/Event.hpp"
#include "../Events/GameEvent.hpp"
#include "../Map/Board.hpp"

class Loop
{
protected:
    Map::Board *map;
    Player * player;

public:
    Loop(Player *player) {
        this->player = player;
    }
    virtual ~Loop() {}

public:
    virtual void menu(Draw::Window *win, Listen::Event *event) = 0;
    virtual void game(Draw::Window *win, Listen::Event *event) = 0;
};

#endif