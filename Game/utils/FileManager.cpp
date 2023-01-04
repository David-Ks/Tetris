#include "FileManager.hpp"

#include <fstream>
#include <string>

/**
 * @brief Read data from file 
 * 
 * @param fileName 
 * @return Utils::FileManager::FileContent 
 */
Utils::FileManager::FileContent Utils::FileManager::read(const std::string &fileName)
{
    FileContent text;
    std::fstream file;
    file.open(path + fileName, std::ios::in);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            text.push_back(line);
        }
        file.close();
    }

    return text;
}

/**
 * @brief Write data to a specific location in the file
 * 
 * @param fileName 
 * @param line data
 * @param row specific place
 */
void Utils::FileManager::write(const std::string &fileName, const std::string &line, const int row)
{
    FileContent text = read(fileName);
    text.emplace(text.begin() + row, line);

    std::fstream file;
    file.open(path + fileName, std::ios::out);

    if (file.is_open())
    {
        for (const auto &line : text)
        {
            file << line << std::endl;
        }
        file.close();
    }
}