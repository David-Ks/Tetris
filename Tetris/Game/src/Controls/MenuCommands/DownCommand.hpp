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
            DownCommand(const Draw::Window *win, Board &board) : Command(win, board) {}

        public:
            bool isAvailable() const;
            bool execute();
        };
    } // namespace Menu
    
} // namespace Action

#endif