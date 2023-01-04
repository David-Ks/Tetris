#ifndef NCURSES_INPUT_HPP
#define NCURSES_INPUT_HPP

#include "Input.hpp"
#include <ncurses.h>

class NcursesInput : public Input
{
public:
    NcursesInput();

public:
    int getKey() const;
};

#endif // NCURSES_INPUT_HPP