#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>

namespace Settings
{
    typedef std::vector<std::vector<std::vector<int>>> typeList; // 3D

    const static int height = 30;
    const static int weidth = 12;

    const static typeList types = {
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
        {{1, 1}, {2, 1}, {2, 2}, {2, 3}},
        {{2, 1}, {2, 2}, {2, 3}, {1, 3}},
        {{1, 1}, {2, 1}, {2, 2}, {3, 2}},
        {{3, 1}, {2, 1}, {2, 2}, {1, 2}},
        {{1, 1}, {1, 2}, {2, 2}, {2, 1}},
        {{1, 2}, {2, 1}, {2, 2}, {2, 3}}};
} // namespace Settings

#endif