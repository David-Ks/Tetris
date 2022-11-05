#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

namespace User
{
    class Player
    {
    protected:
        int score;
        std::string name;

    public:
        Player(const std::string &name = "Anonymous") : 
            score(0),
            name(name)
        {
        }

    public:
        void addScore(int cleaned);
        void setScore(int score);
        int getScore() const;
        std::string getName() const;
    };

    Player &player();
} // namespace User

#endif