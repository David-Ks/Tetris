#ifndef BOARD_H
#define BOARD_H

#include <algorithm>

#include "../Settings.cpp"
#include "../Figures/Figure.hpp"

using MapMatrix = std::vector<std::vector<char>>;
using NumericLine = std::vector<int>;
using FigureList = std::vector<Object::Figure *>;

namespace Map
{
    class Board
    {
    protected:
        bool gameOver;
        Object::Figure *nextFigure;

    public:
        FigureList figures;
        MapMatrix map;

    public:
        Board();
        ~Board() {}

    public:
        void lineClean(const NumericLine &fullLines);
        void dropNotActiveFigures(const NumericLine &fullLines);
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