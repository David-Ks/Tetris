#ifndef DROPCOMMAND_H
#define DROPCOMMAND_H

#include "../Command.hpp"

namespace Action
{
    namespace Game
    {
        class DropCommand : public Command
        {
        public:
            DropCommand() {}
            ~DropCommand() {}

        public:
            bool isAvailable();
            bool execute();
        };
    } // namespace Game

} // namespace Action

#endif