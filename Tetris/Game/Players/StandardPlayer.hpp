#ifndef STANDARD_PLAYER_H
#define STANDARD_PLAYER_H

#include "Player.hpp"

class StandardPlayer : public Player
{
public:
    StandardPlayer() {}
    ~StandardPlayer() {}

public:
    void addScore(int score);
};

#endif