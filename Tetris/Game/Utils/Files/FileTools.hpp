#ifndef FILE_TOOL_CPP
#define FILE_TOOL_CPP

#include <string>
#include <vector>

namespace Utils
{
    namespace Files
    {
        using FileContent = std::vector<std::string>;

        const std::string path = "Game/cache/";

        FileContent read(const std::string &fileName);
        void write(const std::string &fileName, const std::string &line, const int row);
    } // namespace Files
} // namespace Utils

#endif