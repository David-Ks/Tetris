#include "Player.hpp"

#include "../../Utils/Files/FileTools.hpp"

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

void User::Player::saveScore()
{
    Utils::Files::FileContent lines = Utils::Files::read("records.txt");
    bool isRecordAdded = false;
    constexpr int recordsDefaultAddSize = 10;

    if (score == 0)
    {
        return;
    }

    if (lines.size() == 0)
    {
        saveRecordToFile(0);
        isRecordAdded = true;
    }

    int row;
    for (row = 0; row < (int)lines.size(); row++)
    {
        PlayerData data = getPlayerDataFromLine(lines[row]);
        if (isRecordNumberFormat(data[1]))
        {
            if (score >= stoi(data[1]))
            {
                saveRecordToFile(row);
                isRecordAdded = true;
                break;
            }
        }
    }

    if (!isRecordAdded && lines.size() <= recordsDefaultAddSize)
    {
        saveRecordToFile(row);
    }

    setScore(0);
}

void User::Player::saveRecordToFile(const int row)
{
    std::string playerRecordData = name + "/" 
                                 + std::to_string(score) + "/";
    Utils::Files::write("records.txt", playerRecordData, row);
}

bool User::Player::isRecordNumberFormat(const std::string &word)
{
    for (const char &letter : word)
    {
        if (!std::isdigit(letter))
        {
            return false;
        }
    }
    return true;
}

User::Player::PlayerData User::Player::getPlayerDataFromLine(const std::string &line)
{
    PlayerData data;
    std::string delSymbol = "/";

    int start, end = -1 * delSymbol.size();
    do
    {
        start = end + delSymbol.size();
        end = line.find(delSymbol, start);
        data.push_back(line.substr(start, end - start));
    } while (end != -1);

    return data;
}

int User::Player::getScore() const
{
    return score;
}

std::string User::Player::getName() const
{
    return name;
}