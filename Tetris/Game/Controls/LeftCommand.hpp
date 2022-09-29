#ifndef LEFTCOMMAND_H
#define LEFTCOMMAND_H

#include "Command.hpp"

namespace Action
{
    class LeftCommand : public Command
    {
    public:
        LeftCommand() {}
        ~LeftCommand() {}

    public:
        bool isAvailable();
        bool execute();
    };
} // namespace Action

#endif