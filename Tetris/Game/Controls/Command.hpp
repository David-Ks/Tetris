#ifndef COMMAND_H
#define COMMAND_H

#include "../Settings.hpp"

namespace Action
{
    class Command
    {
    protected:
        Figure *figure;

    public:
        Command(Figure *figure) { this->figure = figure; }
        virtual ~Command() {}

    public:
        virtual bool isAvailable(map_t map) = 0;
        virtual bool execute() = 0;
    };
} // namespace Action

#endif