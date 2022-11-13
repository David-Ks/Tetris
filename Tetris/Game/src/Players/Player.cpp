#include "Player.hpp"

void User::Player::addScore(int cleaned)
{
    switch (cleaned)
    {
    case 1:
        score += 10;
        break;
    case 2:
        score += 100;
        break;
    case 3:
        score += 500;
        break;
    case 4:
        score += 1000;
        break;
    default:
        ++score;
        break;
    }
}

void User::Player::setScore(int score)
{
    this->score = score;
}

int User::Player::getScore() const
{
    return score;
}

std::string User::Player::getName() const
{
    return name;
}