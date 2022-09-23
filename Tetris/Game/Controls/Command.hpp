#ifndef COMMAND_H
#define COMMAND_H

namespace Action
{
    class Command
    {
    protected:
        Object::Figure *figure;

    public:
        Command(Object::Figure *figure) { this->figure = figure; }
        virtual ~Command() {}

    public:
        virtual bool isAvailable(map_t map) = 0;
        virtual bool execute() = 0;
    };
} // namespace Action

#endif