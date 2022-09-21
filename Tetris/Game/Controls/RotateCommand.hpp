#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "Command.hpp"

namespace Action
{
    class RotateCommand : public Command
    {
    public:
        RotateCommand(Figure *figure) : Command(figure) {}
        ~RotateCommand() {}

    public:
        bool isAvailable(map_t map);
        bool execute();
    
    public:
        int getNewPos(int x);
    };
} // namespace Action

#endif