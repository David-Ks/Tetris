#ifndef DROPCOMMAND_H
#define DROPCOMMAND_H

#include "Command.hpp"

namespace Action
{
    class DropCommand : public Command
    {
    public:
        DropCommand(Object::Figure *figure) : Command(figure) {}
        ~DropCommand() {}

    public:
        bool isAvailable(map_t map);
        bool execute();
    };
} // namespace Action

#endif