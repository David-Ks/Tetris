#ifndef COMMAND_H
#define COMMAND_H

#include "../Settings.cpp"

namespace Action
{
    class Command
    {
    public:
        Command() {}
        virtual ~Command() {}

    public:
        virtual bool isAvailable() = 0;
        virtual bool execute() = 0;
    };
} // namespace Action

#endif