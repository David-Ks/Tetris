#ifndef BOARD_HPP
#define BOARD_HPP

#include "../Figures/Figure.hpp"

#include <vector>
#include <string>

using BoardMatrix = std::vector<std::vector<char>>;

class Board
{
private:
    using Indexes = std::vector<int>;
    using FigureList = std::vector<Object::Figure *>;
    using IndexList = std::vector<int>;

    bool gameOver;
    Object::Figure *nextFigure;

public:
    FigureList figures;
    BoardMatrix matrix;

public:
    Board();

public:
    void dropNotActiveFigures(const IndexList &);
    void update();
    void cleanBoardMatrix();
    void theEndOfGame();

public:
    void addFigure();
    void generateNextFigure();
    Object::Figure *getNextFigure() const;
    bool hasNextFigure() const;

public:
    bool isGameOver() const;
    void setGameOver(bool);
};

#endif