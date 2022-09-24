#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "../Figures/Figure.hpp"

typedef std::vector<std::vector<char>> map_t;
typedef std::vector<Object::Figure *> figureList;

namespace Map
{
    class Board
    {
    protected:
        bool gameOver;
        int *linesScore;
        Object::Figure *nextFigure;

    public:
        figureList figures;
        map_t map;

    public:
        Board() : gameOver(false) {}
        virtual ~Board() {}

    public:
        virtual void lineClean(std::vector<int> fullLines) = 0;
        virtual void lineCheck() = 0;
        virtual void update() = 0;
        virtual void clean() = 0;
        virtual void theEndOfGame() = 0;

    public:
        virtual void addFigure() = 0;
        virtual void generateNextFigure() = 0;
        virtual Object::Figure *getNextFigure() = 0;

    public:
        bool getGameOver()
        {
            return gameOver;
        }

        void setGameOver(bool gameOver)
        {
            this->gameOver = gameOver;
        }
    };
} // namespace Map

#endif