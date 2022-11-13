#ifndef SCRIPT_HPP
#define SCRIPT_HPP

#include "../Board/Board.hpp"
#include "../Players/Player.hpp"

namespace Scenario
{
    class Script
    {
    protected:
        Board &board;
        User::Player &player;

    public:
        Script(Board &board, User::Player &player) : 
            board(board),
            player(player) {}
        virtual ~Script() {}

    public:
        virtual void start() = 0;
        virtual void update() = 0;
    };
} // namespace Scenario

#endif