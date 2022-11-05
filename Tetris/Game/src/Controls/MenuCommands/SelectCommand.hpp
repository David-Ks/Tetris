#ifndef SELECT_COMMAND_HPP
#define SELECT_COMMAND_HPP

#include "../Command.hpp"
#include "../../GameLoop/Loop.hpp"

namespace Action
{
    namespace Menu
    {
        class SelectCommand : public Command
        {
        public:
            SelectCommand() {}

        public:
            bool isAvailable() const;
            bool execute();
        };
    } // namespace Menu

} // namespace Action

#endif