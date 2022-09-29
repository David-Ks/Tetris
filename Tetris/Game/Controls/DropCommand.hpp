#ifndef DROPCOMMAND_H
#define DROPCOMMAND_H

#include "Command.hpp"

namespace Action
{
    class DropCommand : public Command
    {
    public:
        DropCommand() {}
        ~DropCommand() {}

    public:
        bool isAvailable();
        bool execute();
    };
} // namespace Action

#endif