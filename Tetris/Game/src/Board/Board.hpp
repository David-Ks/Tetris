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

    Object::Figure *nextFigure;
    bool gameOver;
    
    BoardMatrix matrix;

public:
    FigureList figures;

public:
    Board();

public:
    BoardMatrix getMatrix() const;
    void dropNotActiveFigures(const IndexList &);
    void cleanMatrix();
    void theEndOfGame();

public:
    void addFigure();
    void generateNextFigure();
    Object::Figure *getNextFigure() const;
    bool hasNextFigure() const;

public:
    bool isFreePosition(const Position &) const;
    bool isFullLine(const int row) const;
    bool isGameOver() const;
    void setGameOver(bool);

public:
    void insertFigure(const Object::Figure *);
    void removeFigure(const Object::Figure *);
    void removeBlock(const Position &);

private:
    void setFigureSymbols(const Object::Figure *, const char);
    void setSymbol(const Position&, char);
};

#endif