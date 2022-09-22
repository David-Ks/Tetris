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
        int *linesScore;
        Player *player;

    public:
        figureList figures;
        map_t map;

    public:
        Board(Player *player)
        {
            this->player = player;
            gameOver = false;
        }
        virtual ~Board() {}

    public:
        virtual void lineClean(std::vector<int> fullLines) = 0;
        virtual void lineCheck() = 0;
        virtual void update() = 0;
        virtual void clean() = 0;
        virtual void addFigure() = 0;

    public:
        Player *getPlayer()
        {
            return player;
        }

        bool getGameOver()
        {
            return gameOver;
        }

        void setGameOver(bool gameOver)
        {
            this->gameOver = gameOver;
        }

        void theEndOfGame()
        {
            for (auto &figure : figures)
            {
                if (!figure) continue;
                for (auto &block : figure->blocks)
                {
                    if (!block) continue;
                    delete block;
                    block = 0;
                }
                delete figure;
                figure = 0;
            }
        }
    };
} // namespace Map

#endif