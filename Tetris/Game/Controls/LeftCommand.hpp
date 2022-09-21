#ifndef LEFTCOMMAND_H
#define LEFTCOMMAND_H

#include "Command.hpp"

namespace Action
{
    class LeftCommand : public Command
    {
    public:
        LeftCommand(Figure *figure) : Command(figure) {}
        ~LeftCommand() {}

    public:
        bool isAvailable(map_t map);
        bool execute();
    };
} // namespace Action

#endif