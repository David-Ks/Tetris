#ifndef LOOP_H
#define LOOP_H

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