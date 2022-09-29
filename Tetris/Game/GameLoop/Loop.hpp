#ifndef LOOP_H
#define LOOP_H

#include "../Events/KeyBoardEvent.hpp"

#include "../Controls/GameCommands/RotateCommand.cpp"
#include "../Controls/GameCommands/DropCommand.cpp"
#include "../Controls/GameCommands/LeftCommand.cpp"
#include "../Controls/GameCommands/RightCommand.cpp"

#include "../Controls/MenuCommands/DownCommand.cpp"
#include "../Controls/MenuCommands/UpCommand.cpp"

#include <set>
#include <map>

namespace GameLoop
{
    class Loop
    {
    public:
        Loop() {}
        ~Loop() {}

    public:
        void menu();
        void game();
    };

    Loop &loop();
} // namespace GameLoop

#endif