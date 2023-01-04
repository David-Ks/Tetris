#include "Player.hpp"
#include "../../utils/FileManager.hpp"

Player::Player() {}

void Player::addScore(const int cleanedLinesCount)
{
    switch (cleanedLinesCount)
    {
    case 1:
        score += 10;
        break;
    case 2:
        score += 50;
        break;
    case 3:
        score += 100;
        break;
    case 4:
        score += 500;
    }
}

void Player::setScore(const int score)
{
    this->score = score;
}

void Player::saveScore()
{
    Utils::FileManager::FileContent lines = Utils::FileManager::read("records.txt");
    constexpr int recordsDefaultAddSize = 10;
    bool isRecordAdded = false;
    int rowForSave = 0;

    if (!score)
        return;

    if (lines.empty())
    {
        saveRecordToFile(rowForSave);
        isRecordAdded = true;
    }

    for (rowForSave = 0; rowForSave < (int)lines.size(); rowForSave++)
    {
        const PlayerData data = getPlayerDataFromLine(lines[rowForSave]);
        const auto recordInString = data[1];
        if (isRecordNumberFormat(recordInString))
        {
            if (score >= stoi(recordInString))
            {
                saveRecordToFile(rowForSave);
                isRecordAdded = true;
                break;
            }
        }
    }

    if (!isRecordAdded && lines.size() <= recordsDefaultAddSize)
        saveRecordToFile(rowForSave);

    setScore(0);
}

void Player::saveRecordToFile(const int row)
{
    Text playerRecordData = name + "/" + std::to_string(score) + "/";
    Utils::FileManager::write("records.txt", playerRecordData, row);
}

bool Player::isRecordNumberFormat(const Text &word)
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

Player::PlayerData Player::getPlayerDataFromLine(const Text &line)
{
    PlayerData data;
    Text delSymbol = "/";

    int start, end = -1 * delSymbol.size();
    do
    {
        start = end + delSymbol.size();
        end = line.find(delSymbol, start);
        data.push_back(line.substr(start, end - start));
    } while (end != -1);

    return data;
}

void Player::setName(const Text &name)
{
    this->name = name;
}

Player::Text Player::getName() const
{
    return name;
}

int Player::getScore() const
{
    return score;
}