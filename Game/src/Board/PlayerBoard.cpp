#include "PlayerBoard.hpp"

PlayerBoard::PlayerBoard(EventSystem &event, Settings::GameState &currentState, Player &player)
    : Board(event, currentState, player)
{
    matrix = Matrix(Settings::height, std::vector<char>(Settings::width, ' '));
    Board::newNextFigure();
    setActionListeners();
}

PlayerBoard::~PlayerBoard()
{
    if (nextFigure)
    {
        delete nextFigure;
        nextFigure = 0;
    }

    if (!figures.empty())
    {
        for (auto &figure : figures)
        {
            if (figure)
            {
                delete figure;
                figure = 0;
            }
        }
    }
}

void PlayerBoard::setActionListeners()
{
    constexpr auto playState = Settings::GameState::Play;

    eventSystem.addListener(EventSystem::Event::KeyDown, std::bind(&PlayerBoard::moveDown, this), playState);
    eventSystem.addListener(EventSystem::Event::KeyRight, std::bind(&PlayerBoard::moveRight, this), playState);
    eventSystem.addListener(EventSystem::Event::KeyLeft, std::bind(&PlayerBoard::moveLeft, this), playState);
    eventSystem.addListener(EventSystem::Event::KeyUp, std::bind(&PlayerBoard::rotate, this), playState);
    eventSystem.addListener(EventSystem::Event::EndOfWhile, std::bind(&PlayerBoard::moveDown, this), playState);

    eventSystem.addListener(EventSystem::Event::Esc, std::bind(&PlayerBoard::theEnd, this), playState);
}