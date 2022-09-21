#ifndef SANDARD_BOARD_H
#define SANDARD_BOARD_H

#include "Board.hpp"

namespace Map
{
    class StandardBoard : public Board
    {
    public:
        StandardBoard(Player *player);
        ~StandardBoard();
    
    public:
        static void specialQueueForIndexes(int *arr, int size);

        void lineClean(std::vector<int>fullLines);
        void lineCheck();
        void update();
        void clean();
        void addFigure();
    };
} // namespace Map

#endif