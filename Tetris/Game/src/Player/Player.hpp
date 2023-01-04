#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

class Player
{
private:
    using Text = std::string;
    using PlayerData = std::vector<Text>;

    int score = 0;
    Text name = "Player";

public:
    Player();

public:
    void addScore(const int);
    void setName(const Text &);
    Text getName() const;
    int getScore() const;
    void setScore(const int);
    void saveScore();

private:
    void saveRecordToFile(const int row);

public:
    static PlayerData getPlayerDataFromLine(const Text &line);
    static bool isRecordNumberFormat(const Text &word);
};

#endif