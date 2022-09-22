#include "StandardPlayer.hpp"

void StandardPlayer::addScore(int cleaned)
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