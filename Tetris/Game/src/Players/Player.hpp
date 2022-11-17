#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

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
        {}

    public:
        void addScore(int cleaned);
        void setScore(int score);
        void saveScore();
        int getScore() const;
        std::string getName() const;
    
    private:
        using PlayerData = std::vector<std::string>;

        void saveRecordToFile(const int row);
        static PlayerData getPlayerDataFromLine(const std::string &line);
        static bool isRecordNumberFormat(const std::string &word);
    };
} // namespace User

#endif