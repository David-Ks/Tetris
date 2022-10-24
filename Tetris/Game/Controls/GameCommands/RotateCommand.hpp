#ifndef ROTATE_COMMAND_HPP
#define ROTATE_COMMAND_HPP

#include "../Command.hpp"

namespace Action
{
    namespace Game
    {
        class RotateCommand : public Command
        {
        public:
            RotateCommand() {}

        public:
            bool isAvailable() const;
            bool execute();

        public:
            int getNewPos(int x) const;
        };
    } // namespace Game

} // namespace Action

#endif