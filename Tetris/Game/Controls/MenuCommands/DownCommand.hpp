#ifndef DOWN_COMMAND_H
#define DOWN_COMMAND_H

#include "../Command.hpp"

namespace Action
{
    namespace Menu
    {
        class DownCommand : public Command
        {
        public:
            DownCommand() {}
            ~DownCommand() {}

        public:
            bool isAvailable();
            bool execute();
        };
    } // namespace Menu
    
} // namespace Action

#endif