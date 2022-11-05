#ifndef COMMAND_HPP
#define COMMAND_HPP

namespace Action
{
    class Command
    {
    public:
        Command() {}
        virtual ~Command() {}

    public:
        virtual bool isAvailable() const = 0;
        virtual bool execute() = 0;
    };
} // namespace Action

#endif