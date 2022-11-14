#include "FileTools.hpp"

#include <fstream>
#include <string>

Utils::Files::FileContent Utils::Files::read(const std::string &fileName)
{
    FileContent text;
    std::ifstream file(fileName, std::ios::in);
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

// need to append on correct row

// void Utils::Files::append(const std::string &fileName, const std::string &content)
// {
//     std::ifstream file(fileName, std::ios::app);
//     if (file.is_open())
//     {
//         file << content;
//         file.close();
//     }
// }