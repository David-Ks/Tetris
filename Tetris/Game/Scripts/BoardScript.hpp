#ifndef BOARD_SCRIPT_HPP
#define BOARD_SCRIPT_HPP

#include "Script.hpp"

#include <vector>

namespace Scenario
{
    class BoardScript : public Script
    {
    private:
        using IndexList = std::vector<int>;
        
    public:
        BoardScript() {}
        ~BoardScript() {}

    public:
        void start();
        void update();

    private:
        IndexList getFullLines();
        void cleanLines(const IndexList&);
    };
} // namespace Scenario


#endif