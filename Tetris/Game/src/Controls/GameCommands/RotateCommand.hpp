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
            RotateCommand(Board &board) : Command(board) {}

        public:
            bool isAvailable() const;
            bool execute();

        private:
            static Position getNewRotatedPos(const Position blockPosition);
            bool isFreePosition(const Position &position) const;
        };
    } // namespace Game

} // namespace Action

#endif