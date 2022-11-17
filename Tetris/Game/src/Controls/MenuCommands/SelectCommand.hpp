#ifndef SELECT_COMMAND_HPP
#define SELECT_COMMAND_HPP

#include "../Command.hpp"

namespace Action
{
    namespace Menu
    {
        class SelectCommand : public Command
        {
        public:
            SelectCommand(const Draw::Window *win, Board &board) : Command(win, board) {}

        public:
            bool isAvailable() const;
            bool execute();
        };
    } // namespace Menu

} // namespace Action

#endif