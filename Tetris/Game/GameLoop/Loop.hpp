#ifndef LOOP_H
#define LOOP_H

#include "../Events/MenuEvent.hpp"
#include "../Events/GameEvent.hpp"

#include <set>
#include <map>

class Loop
{
public:
    Loop() {}
    ~Loop() {}

public:
    void menu(Listen::Event *event);
    void game(Listen::Event *event);
};

#endif