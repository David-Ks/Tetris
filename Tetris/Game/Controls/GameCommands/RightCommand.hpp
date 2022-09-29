#ifndef RIGHTCOMMAND_H
#define RIGHTCOMMAND_H

#include "../Command.hpp"

namespace Action
{
    namespace Game
    {
        class RightCommand : public Command
        {
        public:
            RightCommand() {}
            ~RightCommand() {}

        public:
            bool isAvailable();
            bool execute();
        };
    } // namespace Game

} // namespace Action

#endif