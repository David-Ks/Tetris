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
        using ChangedLines = std::set<int>;

    public:
        BoardScript() {}
        ~BoardScript() {}

    public:
        void start();
        void update();

    private:
        ChangedLines getChangedLines(const Object::Figure *);
        IndexList getFullLines();
        void cleanLines(const IndexList&);
    };
} // namespace Scenario


#endif