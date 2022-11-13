#ifndef RIGHT_COMMAND_HPP
#define RIGHT_COMMAND_HPP

#include "../Command.hpp"

namespace Action
{
    namespace Game
    {
        class RightCommand : public Command
        {
        public:
            RightCommand(Board &board) : Command(board) {}

        public:
            bool isAvailable() const;
            bool execute();
        };
    } // namespace Game

} // namespace Action

#endif