#ifndef FILE_TOOL_CPP
#define FILE_TOOL_CPP

#include <string>
#include <vector>

namespace Utils
{
    namespace Files
    {
        using FileContent = std::vector<std::string>;

        FileContent read(const std::string &fileName);
        void append(const std::string &fileName, const std::string &content);
    } // namespace Files
} // namespace Utils

#endif