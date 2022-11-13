#ifndef DROP_COMMAND_HPP
#define DROP_COMMAND_HPP

#include "../Command.hpp"

namespace Action
{
    namespace Game
    {
        class DropCommand : public Command
        {
        public:
            DropCommand(Board &board) : Command(board) {}

        public:
            bool isAvailable() const;
            bool execute();
        };
    } // namespace Game

} // namespace Action

#endif