#ifndef SELECT_COMMAND_H
#define SELECT_COMMAND_H

#include "../Command.hpp"

namespace Action
{
    namespace Menu
    {
        class SelectCommand : public Command
        {
        public:
            SelectCommand() {}
            ~SelectCommand() {}

        public:
            bool isAvailable();
            bool execute();
        };
    } // namespace Menu
} // namespace Action

#endif