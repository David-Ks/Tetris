#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
protected:
    int score;
    std::string name;

public:
    Player() { score = 0; name = "Anonymous"; }
    virtual ~Player() {}

public:
    virtual int getScore() = 0;
    virtual void setScore(int score) = 0;

    virtual std::string getName() = 0;
    virtual void setName(std::string name) = 0;
};

#endif