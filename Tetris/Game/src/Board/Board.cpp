#include <algorithm>
#include <set>
#include <vector>

#include "Board.hpp"
#include "../Figures/Figure.hpp"
#include "../Players/Player.hpp"
#include "../Settings.hpp"
#include "../../Utils/Objects/Tools.hpp"

Board::Board() : gameOver(false), nextFigure(0)
{
    matrix = BoardMatrix(Settings::height, std::vector<char>(Settings::width, ' '));
    generateNextFigure();
}

void Board::cleanMatrix()
{
    for (auto &row : matrix)
    {
        std::fill(row.begin(), row.end(), ' ');
    }
}

void Board::dropNotActiveFigures(const IndexList &fullLines)
{
    const int start = *std::min_element(fullLines.begin(), fullLines.end());
    const int count = fullLines.size();

    for (const auto &figure : figures)
    {
        if (!figure)
            continue;

        removeFigure(figure);

        for (const auto &block : figure->blocks)
        {
            if (!block)
                continue;

            Position blockPos = block->getPos();
            if (figure->getPos().x + blockPos.x <= start)
            {
                blockPos.x += count;
                block->setPos(blockPos);
            }
        }

        insertFigure(figure);
    }
}

void Board::theEndOfGame()
{
    Utils::Objects::clear(figures);
    Utils::Objects::del(nextFigure);
    cleanMatrix();
}

void Board::addFigure()
{
    if (!hasNextFigure())
    {
        generateNextFigure();
    }

    constexpr int centerY = (Settings::width - 3) / 2;
    constexpr Position figureStartPos{0, centerY};

    auto *nextFigure = getNextFigure();

    Utils::Objects::push(figures, nextFigure, figureStartPos);
    insertFigure(nextFigure);
    generateNextFigure();
}

Object::Figure *Board::getNextFigure() const
{
    return nextFigure;
}

bool Board::hasNextFigure() const
{
    if (nextFigure)
    {
        return true;
    }
    return false;
}

void Board::generateNextFigure()
{
    nextFigure = new Object::Figure;
}

bool Board::isGameOver() const
{
    return gameOver;
}

void Board::setGameOver(bool gameOver)
{
    this->gameOver = gameOver;
}

void Board::removeFigure(const Object::Figure *figure)
{
    constexpr char cleanSymbol = ' ';
    setFigureSymbols(figure, cleanSymbol); 
}

void Board::removeBlock(const Position &position)
{
    constexpr char cleanSymbol = ' ';
    setSymbol(position, cleanSymbol);
}

void Board::insertFigure(const Object::Figure *figure)
{
    constexpr char figureSymbol = '#'; // figure->getSymbol
    setFigureSymbols(figure, figureSymbol); 
}

void Board::setFigureSymbols(const Object::Figure *figure, const char symbol)
{
    if (!figure)
        return;

    for (const auto &block : figure->blocks)
    {
        if (!block)
            continue;

        const Position absPosition {block->getPos().x + figure->getPos().x,
                                    block->getPos().y + figure->getPos().y};

        setSymbol(absPosition, symbol);
    }
}

void Board::setSymbol(const Position &position, const char symbol)
{
    matrix[position.x][position.y] = symbol;
}

bool Board::isFreePosition(const Position &position) const
{
    if (matrix[position.x][position.y] != ' ')
    {
        return false;
    }
    return true;
}

bool Board::isFullLine(const int row) const
{
    const static std::vector<char> fullLineExample(Settings::width, '#');
    if (matrix[row] == fullLineExample)
    {
        return true;
    }
    return false;
}

BoardMatrix Board::getMatrix() const
{
    return matrix;
}