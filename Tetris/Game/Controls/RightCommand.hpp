#ifndef RIGHTCOMMAND_H
#define RIGHTCOMMAND_H

#include "Command.hpp"

namespace Action
{
    class RightCommand : public Command
    {
    public:
        RightCommand() {}
        ~RightCommand() {}

    public:
        bool isAvailable();
        bool execute();
    };
} // namespace Action

#endif