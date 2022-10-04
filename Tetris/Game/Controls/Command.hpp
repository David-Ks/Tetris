#ifndef COMMAND_H
#define COMMAND_H

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