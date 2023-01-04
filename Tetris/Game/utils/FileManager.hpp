#ifndef FILE_MANAGER_CPP
#define FILE_MANAGER_CPP

#include <string>
#include <vector>

namespace Utils
{
    namespace FileManager
    {
        using FileContent = std::vector<std::string>;

        const std::string path = "Game/other/";

        FileContent read(const std::string &fileName);
        void write(const std::string &fileName, const std::string &line, const int row);

    } // namespace FileManager
} // namespace Utils

#endif // FILE_MANAGER_CPP