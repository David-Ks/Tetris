#ifndef SANDARD_BOARD_H
#define SANDARD_BOARD_H

#include "Board.hpp"

namespace Map
{
    class StandardBoard : public Board
    {
    public:
        StandardBoard();
        ~StandardBoard();

    public:
        void dropNotActiveFigures(std::vector<int> fullLines);
        void lineClean(std::vector<int> fullLines);
        void lineCheck();
        void update();
        void clean();
        void theEndOfGame();

    public:
        void addFigure();
        void generateNextFigure();
        Object::Figure *getNextFigure();
    };
} // namespace Map

#endif