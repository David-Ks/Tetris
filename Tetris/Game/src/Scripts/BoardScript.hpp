#ifndef BOARD_SCRIPT_HPP
#define BOARD_SCRIPT_HPP

#include "Script.hpp"

#include <vector>
#include <set>

namespace Scenario
{
    class BoardScript : public Script
    {
    public:
        using IndexList = std::vector<int>;
        using NoRepitList = std::set<int>;

    public:
        BoardScript(Board &board, User::Player &player) : Script(board, player) {}

    public:
        void start();
        void update();

    private:
        static bool isOnTheList(int, const IndexList &);
        static void deleteFigureIfEmpty(int blocksCount, Object::Figure *&figure);

        NoRepitList getChangedLines(const Object::Figure *);
        IndexList getFullLines();
        void cleanLines(const IndexList&);
    };
} // namespace Scenario


#endif