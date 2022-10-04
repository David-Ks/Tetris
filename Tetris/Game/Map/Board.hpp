#ifndef BOARD_H
#define BOARD_H

#include "../Figures/Figure.cpp"
#include "../Players/Player.cpp"

using MapMatrix = std::vector<std::vector<char>>;
using Indexes = std::vector<int>;
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
        void lineClean(const Indexes &fullLines);
        void dropNotActiveFigures(int start, int count);
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