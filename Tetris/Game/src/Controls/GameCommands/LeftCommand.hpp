#ifndef LEFT_COMMAND_HPP
#define LEFT_COMMAND_HPP

#include "../Command.hpp"

namespace Action
{
    namespace Game
    {
        class LeftCommand : public Command
        {
        public:
            LeftCommand(Board &board) : Command(board) {}

        public:
            bool isAvailable() const;
            bool execute();
        };
    } // namespace Game

} // namespace Action

#endif