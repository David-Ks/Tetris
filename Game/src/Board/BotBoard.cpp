#include "BotBoard.hpp"
#include <algorithm>

BotBoard::BotBoard(EventSystem &event, Settings::GameState &currentState, Player &player)
    : Board(event, currentState, player), activeFigureRotateDeg(0)
{
    matrix = Matrix(Settings::height, std::vector<char>(Settings::width, ' '));
    Board::newNextFigure();
    setActionListeners();
    player.setName("CPU");
}

BotBoard::~BotBoard()
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

void BotBoard::setActionListeners()
{
    const auto event = EventSystem::Event::EndOfWhile;
    const auto state = Settings::GameState::PlayerVsCPU;
    eventSystem.addListener(event, std::bind(&BotBoard::goToComfortPos, this), state);
    eventSystem.addListener(EventSystem::Event::Esc, std::bind(&BotBoard::theEnd, this), state);
}

void BotBoard::goToComfortPos()
{
    if (figures.empty())
    {
        Board::addFigure();
        comfortPosition = findComfortPos();
    }

    const Position activeFigurePosition = activeFigure->getPosition();
    if (activeFigureRotateDeg != comfortPosition.rotate)
    {
        Board::rotate();
        ++activeFigureRotateDeg;
    }
    else if (activeFigurePosition.y > comfortPosition.position.y)
    {
        Board::moveLeft();
    }
    else if (activeFigurePosition.y < comfortPosition.position.y)
    {
        Board::moveRight();
    }
    else
    {
        if (!Board::moveDown())
        {
            comfortPosition = findComfortPos();
        }
    }

    if (!Board::moveDown())
    {
        comfortPosition = findComfortPos();
    }
}

SpecialPosition BotBoard::findComfortPos()
{
    const auto positionForSave = activeFigure->getPosition(); // Need copy constructor
    const auto blocksPositionsForSave = activeFigure->getBlocksPositions();

    Board::removeFromMatrix(activeFigure);
    Positions bestPositions;

    const int heightPosition = calculateStartHeight();
    if (heightPosition <= 0)
    {
        theEnd();
        return {};
    }

    int rotateDegree = 0;

    while (rotateDegree != 4)
    {
        toStartPosition(heightPosition);
        do
        {
            Board::removeFromMatrix(activeFigure);
            fullDropDown();
            const int usability = calculateUsability();
            bestPositions.push_back({activeFigure->getPosition(), rotateDegree, usability});

            auto pos = activeFigure->getPosition();
            pos.x = heightPosition;
            activeFigure->setPosition(pos);
        } while (Board::moveRight());

        ++rotateDegree;
        Board::rotate();
        Board::removeFromMatrix(activeFigure);
    }

    activeFigure->setPosition(positionForSave);
    activeFigure->setBlocksPositions(blocksPositionsForSave);
    activeFigureRotateDeg = 0;

    return getOptimalPosition(bestPositions);
}

bool BotBoard::compareByUsability(SpecialPosition a, SpecialPosition b)
{
    return (a.usability < b.usability);
}

bool BotBoard::compareByPositionX(SpecialPosition a, SpecialPosition b)
{
    return (a.position.x <= b.position.x);
}

SpecialPosition BotBoard::getOptimalPosition(Positions bestPositions) const
{
    int bestIndex = std::max_element(bestPositions.begin(), bestPositions.end(), compareByUsability) - bestPositions.begin();
    for (int i = 0; i < (int)bestPositions.size(); ++i)
    {
        if (bestPositions[bestIndex].usability != bestPositions[i].usability)
        {
            bestPositions.erase(bestPositions.begin() + i);
            if (i < bestIndex)
            {
                --bestIndex;
            }
            --i;
        }
    }

    bestIndex = std::max_element(bestPositions.begin(), bestPositions.end(), compareByPositionX) - bestPositions.begin();
    for (int i = 0; i < (int)bestPositions.size(); ++i)
    {
        if (bestPositions[bestIndex].position.x != bestPositions[i].position.x)
        {
            bestPositions.erase(bestPositions.begin() + i);
            if (i < bestIndex)
            {
                --bestIndex;
            }
            --i;
        }
    }

    return bestPositions[0];
}

int BotBoard::calculateUsability() const
{
    int usability = 0;

    const Position currentPosition = activeFigure->getPosition();
    for (const auto &blockPosition : activeFigure->getBlocksPositions())
    {
        const Position absPosition = {blockPosition.x + currentPosition.x,
                                      blockPosition.y + currentPosition.y};

        if (!Board::isFreePositionInMatrix({absPosition.x + 1, absPosition.y})) // Under Figure
        {
            ++usability;
        }
        if (!Board::isFreePositionInMatrix({absPosition.x, absPosition.y + 1})) // Right
        {
            ++usability;
        }
        if (!Board::isFreePositionInMatrix({absPosition.x, absPosition.y - 1})) // Left
        {
            ++usability;
        }
    }

    return usability;
}

void BotBoard::toStartPosition(const int x)
{
    int y = 0;
    bool flag = true;
    for (const auto &blockPosition : activeFigure->getBlocksPositions())
    {
        if (blockPosition.y == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        y = -1;
    }

    activeFigure->setPosition({x, y});
}

int BotBoard::calculateStartHeight() const
{
    for (int i = matrix.size() - 2; i >= 0; --i)
    {
        bool isLineClean = true;
        for (int j = 0; j < (int)matrix[i].size(); ++j)
        {
            if (matrix[i][j] != ' ')
            {
                isLineClean = false;
                break;
            }
        }
        if (isLineClean)
        {
            return i - 4;
        }
    }
    return 0;
}

void BotBoard::fullDropDown()
{
    Position currentPosition = activeFigure->getPosition();
    while (Board::isFreePositionInMatrix(activeFigure, currentPosition))
    {
        currentPosition.x += 1;
    }
    currentPosition.x -= 1;
    activeFigure->setPosition(currentPosition);
}

void BotBoard::theEnd()
{
    matrix.clear();
    matrix = Matrix(Settings::height, std::vector<char>(Settings::width, ' '));
    player.setScore(0);
    currentState = Settings::GameState::Menu;

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

    newNextFigure();
    figures.clear();
}