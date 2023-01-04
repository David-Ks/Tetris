#ifndef PLAYER_BOARD_HPP
#define PLAYER_BOARD_HPP

#include "Board.hpp"

class PlayerBoard : public Board
{
public:
    PlayerBoard(EventSystem &event, Settings::GameState &currentState, Player &player);
    ~PlayerBoard();

protected:
    void setActionListeners();
};

#endif // PLAYER_BOARD_HPP