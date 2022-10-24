#ifndef BOARD_HPP
#define BOARD_HPP

#include "../Figures/Figure.cpp"

#include <vector>
#include <string>

using MapMatrix = std::vector<std::vector<char>>;

namespace Map
{
    class Board
    {
    private:
        using Indexes = std::vector<int>;
        using FigureList = std::vector<Object::Figure *>;
        using IndexList = std::vector<int>;

    private:
        bool gameOver;
        Object::Figure *nextFigure;

    public:
        FigureList figures;
        MapMatrix map;

    public:
        Board();

    public:
        void dropNotActiveFigures(const IndexList &);
        void update();
        void clean();
        void theEndOfGame();

    public:
        void addFigure();
        void generateNextFigure();
        Object::Figure *getNextFigure() const;

    public:
        bool getGameOver() const;
        void setGameOver(bool);
    };

    Board &board();

} // namespace Map

#endif