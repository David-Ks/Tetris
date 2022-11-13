#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../Graphics/Window.hpp"
#include "../Board/Board.hpp"

namespace Action
{
    class Command
    {
    protected:
        const Draw::Window *window;
        Board &board;

    public:
        Command(Board &board) : board(board), window(0) {}
        Command(Draw::Window *win, Board &board) : window(win), board(board) {}
        virtual ~Command() {}

    public:
        virtual bool isAvailable() const = 0;
        virtual bool execute() = 0;
    };
} // namespace Action

#endif