#ifndef PLAYER_H
#define PLAYER_H

#include <string>

namespace User
{
    class Player
    {
    protected:
        int score;
        std::string name;

    public:
        Player(std::string name = "Anonymous") : 
            score(0),
            name(name)
        {
        }
        ~Player() {}

    public:
        void addScore(int cleaned);
        void setScore(int score);
        int getScore();
        std::string getName();
    };

    Player &player();
} // namespace User

#endif