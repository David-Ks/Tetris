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
        Object::Figure *nextFigure;

    public:
        figureList figures;
        map_t map;

    public:
        Board();
        ~Board() {}

    public:
        void lineClean(std::vector<int> fullLines);
        void dropNotActiveFigures(std::vector<int> fullLines);
        void lineCheck();
        void update();
        void clean();
        void theEndOfGame();

    public:
        void addFigure();
        void generateNextFigure();
        Object::Figure *getNextFigure();

    public:
        bool getGameOver() { return gameOver; }
        void setGameOver(bool gameOver) { this->gameOver = gameOver; }
    };

    Board &board();

} // namespace Map

#endif