#include "NcursesInput.hpp"

NcursesInput::NcursesInput()
{
    if (stdscr == 0)
    {
        initscr();
    }
}

int NcursesInput::getKey() const
{
    halfdelay(Settings::loopSpeed);
    return getch();
}
