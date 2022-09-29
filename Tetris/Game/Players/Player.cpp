#include "Player.hpp"

User::Player &User::player()
{
    static User::Player plyr;
    return plyr;
}

void User::Player::addScore(int cleaned)
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

void User::Player::setScore(int score)
{
    this->score = score;
}

int User::Player::getScore()
{
    return score;
}

std::string User::Player::getName()
{
    return name;
}