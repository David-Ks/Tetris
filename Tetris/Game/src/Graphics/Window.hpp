#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../Board/Board.hpp"
#include "../Players/Player.hpp"

#include <vector>
#include <string>

using PressedKey = int;
using MenuList = std::vector<std::string>;

namespace Draw
{
    enum Section
    {
        PLAY = 0,
        SETTINGS,
        RECORDS,
        EXIT
    };

    class Window
    {
    protected:
        const Board &board;
        const User::Player &player;
        mutable Section section;

    public:
        const MenuList menu;

    public:
        Window(const Board &board, const User::Player &player) : 
            section(Section::PLAY), 
            board(board),
            player(player),
            menu({
                    "Play",
                    "Settings",
                    "Records",
                    "Exit"
                })
            {
                init();
            }
        virtual ~Window() {}

    public:
        virtual void init() {};

        virtual void drawMenu() const = 0;
        virtual void drawGame() const = 0;
        
        virtual void clean() = 0;
        virtual PressedKey input() = 0;
    
    public:
        void setSection(Section section) const { this->section = section; }
        Section getSection() const { return section; }
    };
} // namespace Draw

#endif