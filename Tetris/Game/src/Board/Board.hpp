#ifndef BOARD_HPP
#define BOARD_HPP

#include "../EventSystem/EventSystem.hpp"
#include "../Player/Player.hpp"
#include "../Objects/Figure.hpp"

#include <vector>
#include <ctime>
#include <set>

class Board
{
protected:
    using Matrix = std::vector<std::vector<char>>;
    using ObjectPtr = Object *;
    using Objects = std::vector<ObjectPtr>;
    using LinesSet = std::set<int>;
    using Time = std::time_t;

protected:
    EventSystem &eventSystem;
    Settings::GameState &currentState;
    Player &player;
    Matrix matrix;

    Objects figures;
    ObjectPtr nextFigure;
    ObjectPtr activeFigure;
    Time startTime;
    
    char emptySymbol = ' ';

public:
    Board(EventSystem &, Settings::GameState &, Player &);
    virtual ~Board() {}

public:
    Matrix getMatrix() const;
    Objects getFigures() const;
    ObjectPtr getNextFigure() const;
    ObjectPtr getActiveFigure() const;
    Player getPlayer() const;
    int getCurrentTime() const;
    static int getBiggerElemsCount(const LinesSet&, int);

protected:
    virtual void setActionListeners() = 0;

    void rotate();
    bool moveDown();
    void moveLeft();
    bool moveRight();
    bool move(const Position &newPosition);
    void setMoveSpeed() const;

    static Position getRotatedPosition(const Position &);

protected:
    void addFigure();
    void replaceFigure(ObjectPtr, const Position &);
    void newNextFigure();

protected:
    void lineCheck();
    LinesSet getChangedLines() const;
    LinesSet getFullLines(const LinesSet &) const;
    void cleanFullLines(const LinesSet &);
    void dropNotActiveFigures(const LinesSet &);

protected:
    bool isPositionInBoard(const Position &absolutePosition) const;
    bool isFreePositionInMatrix(ObjectPtr, const Position &) const;
    bool isFreePositionInMatrix(const Position &absolutePosition) const;
    bool isGameStart() const;
    bool isEmptyPosition(const Position &) const;
    bool isAbleToRotate() const;

protected:
    void addToMatrix(const ObjectPtr &);
    void removeFromMatrix(const ObjectPtr &);
    void fillMatrixWithFigureBlocks(const ObjectPtr &, const char c);

public:
    void init();
    virtual void theEnd();
};

#endif // BOARD_HPP