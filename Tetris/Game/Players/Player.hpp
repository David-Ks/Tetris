#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
protected:
    int score;
    std::string name;

public:
    Player(std::string name = "Anonymous") { score = 0; this->name = name; }
    virtual ~Player() {}

public:
    virtual void addScore(int score) = 0;

public:
    void setScore(int score) { this->score = score; }
    int getScore() { return score; }
    std::string getName() { return this->name; }
};

#endif