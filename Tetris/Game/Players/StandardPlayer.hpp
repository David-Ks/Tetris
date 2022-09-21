#ifndef STANDARD_PLAYER_H
#define STANDARD_PLAYER_H

#include "Player.hpp"

class StandardPlayer : public Player
{
public:
    StandardPlayer() {}
    ~StandardPlayer() {}

public:
    int getScore();
    void setScore(int score);

    std::string getName();
    void setName(std::string name);
};

#endif