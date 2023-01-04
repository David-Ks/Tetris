#ifndef BOT_BOARD_HPP
#define BOT_BOARD_HPP

#include "Board.hpp"

struct SpecialPosition
{
    Position position;
    int rotate;
    int usability;
};

class BotBoard : public Board
{
private:
    using Positions = std::vector<SpecialPosition>;

    SpecialPosition comfortPosition;
    int activeFigureRotateDeg;

public:
    BotBoard(EventSystem &event, Settings::GameState &currentState, Player &player);
    ~BotBoard();
    
public:
    void theEnd();


protected:
    void setActionListeners();
    
private:
    void goToComfortPos();
    SpecialPosition findComfortPos();
    SpecialPosition getOptimalPosition(Positions) const;

private:
    void toStartPosition(const int height);
    void fullDropDown();
    int calculateStartHeight() const;
    int calculateUsability() const;

    static bool compareByUsability(SpecialPosition, SpecialPosition);
    static bool compareByPositionX(SpecialPosition, SpecialPosition);
};
#endif // BOT_BOARD_HPP