#ifndef UP_COMMAND_HPP
#define UP_COMMAND_HPP

#include "../Command.hpp"

namespace Action
{
    namespace Menu
    {
        class UpCommand : public Command
        {
        public:
            UpCommand(const Draw::Window *win, Board &board) : Command(win, board) {}

        public:
            bool isAvailable() const;
            bool execute();
        };
    } // namespace Menu
    
} // namespace Action

#endif