#ifndef DOWN_COMMAND_HPP
#define DOWN_COMMAND_HPP

#include "../Command.hpp"

namespace Action
{
    namespace Menu
    {
        class DownCommand : public Command
        {
        public:
            DownCommand() {}

        public:
            bool isAvailable() const;
            bool execute();
        };
    } // namespace Menu
    
} // namespace Action

#endif