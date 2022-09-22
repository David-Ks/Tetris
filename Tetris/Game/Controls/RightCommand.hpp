#ifndef RIGHTCOMMAND_H
#define RIGHTCOMMAND_H

#include "Command.hpp"

namespace Action
{
    class RightCommand : public Command
    {
    public:
        RightCommand(Object::Figure *figure) : Command(figure) {}
        ~RightCommand() {}

    public:
        bool isAvailable(map_t map);
        bool execute();
    };
} // namespace Action

#endif