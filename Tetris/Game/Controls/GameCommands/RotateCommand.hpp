#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "../Command.hpp"

namespace Action
{
    namespace Game
    {
        class RotateCommand : public Command
        {
        public:
            RotateCommand() {}
            ~RotateCommand() {}

        public:
            bool isAvailable();
            bool execute();

        public:
            int getNewPos(int x);
        };
    } // namespace Game

} // namespace Action

#endif