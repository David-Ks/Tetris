#include "StandardPlayer.hpp"

int StandardPlayer::getScore()
{
    return score;
}

void StandardPlayer::setScore(int cleaned)
{
    if (cleaned == 1)
        score += 10;
    else if (cleaned == 2)
        score += 100;
    else if (cleaned == 3)
        score += 500;
    else if (cleaned == 4)
        score += 1000; 
    else
        score += 1;
}

std::string StandardPlayer::getName()
{
    return name;
}

void StandardPlayer::setName(std::string name)
{
    this->name = name;
}