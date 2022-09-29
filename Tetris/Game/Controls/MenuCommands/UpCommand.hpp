#ifndef UP_COMMAND_H
#define UP_COMMAND_H

#include "../Command.hpp"

namespace Action
{
    namespace Menu
    {
        class UpCommand : public Command
        {
        public:
            UpCommand() {}
            ~UpCommand() {}

        public:
            bool isAvailable();
            bool execute();
        };
    } // namespace Menu
} // namespace Action

#endif