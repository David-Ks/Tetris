#include "Board.hpp"

Board::Board(EventSystem &event, Settings::GameState &currentState, Player &player)
    : eventSystem(event), currentState(currentState), player(player), nextFigure(0)
{
    matrix = Matrix(Settings::height, std::vector<char>(Settings::width, emptySymbol));
    newNextFigure();
}

void Board::addFigure()
{
    setMoveSpeed();
    if (isGameStart())
        startTime = time(0);

    constexpr int centerY = Settings::width / 2 - 2;
    constexpr Position startPosition{0, centerY};

    activeFigure = getNextFigure();
    activeFigure->setPosition(startPosition);
    figures.push_back(activeFigure);
    addToMatrix(activeFigure);
    newNextFigure();
}

void Board::setMoveSpeed() const
{
    if (player.getScore() >= 100)
        Settings::loopSpeed = 5;
    else if (player.getScore() >= 500)
        Settings::loopSpeed = 3;
    else if (player.getScore() >= 1000)
        Settings::loopSpeed = 1;
    else
        Settings::loopSpeed = 7;
}

void Board::replaceFigure(ObjectPtr figure, const Position &newPosition)
{
    removeFromMatrix(figure);
    figure->setPosition(newPosition);
    addToMatrix(figure);
}

void Board::newNextFigure()
{
    nextFigure = new Figure();
}

void Board::lineCheck()
{
    const LinesSet changedLines = getChangedLines();
    const LinesSet fullLines = getFullLines(changedLines);
    if (!fullLines.empty())
    {
        player.addScore(fullLines.size());
        cleanFullLines(fullLines);
        dropNotActiveFigures(fullLines);
    }
}

void Board::dropNotActiveFigures(const LinesSet &fullLines)
{
    for (auto &figure : figures)
    {
        removeFromMatrix(figure);
        const Position figurePosition = figure->getPosition();
        auto blocksPositions = figure->getBlocksPositions();

        for (auto &blockPosition : blocksPositions)
            blockPosition.x += getBiggerElemsCount(fullLines, blockPosition.x + figurePosition.x);

        figure->setBlocksPositions(blocksPositions);
        addToMatrix(figure);
    }
}

int Board::getBiggerElemsCount(const LinesSet& elems, int num)
{
    int count = 0;
    for (const auto &elem : elems)
        if (elem > num)
            ++count;
    return count;
}


void Board::cleanFullLines(const LinesSet &fullLines)
{
    for (int i = 0; i < (int)figures.size(); ++i)
    {
        auto figurePos = figures[i]->getPosition();
        auto blocksPos = figures[i]->getBlocksPositions();
        removeFromMatrix(figures[i]);

        for (int j = 0; j < (int)blocksPos.size(); ++j)
        {
            if (fullLines.find(blocksPos[j].x + figurePos.x) != fullLines.end())
            {
                blocksPos.erase(blocksPos.begin() + j);
                --j;
            }
        }

        if (blocksPos.empty())
        {
            delete figures[i];
            figures.erase(figures.begin() + i);
            --i;
        }
        else
        {
            figures[i]->setBlocksPositions(blocksPos);
            addToMatrix(figures[i]);
        }
    }
}

Board::LinesSet Board::getChangedLines() const
{
    LinesSet changedLines;
    const Position activeFigurePosition = activeFigure->getPosition();

    for (const auto &blockPosition : activeFigure->getBlocksPositions())
        changedLines.insert(blockPosition.x + activeFigurePosition.x);

    return changedLines;
}

Board::LinesSet Board::getFullLines(const LinesSet &lines) const
{
    LinesSet fullLines;
    for (const auto &line : lines)
    {
        bool isFullLine = true;
        for (int i = 0; i < (int)matrix[line].size() - 1; ++i)
        {
            if (isEmptyPosition({line, i}))
            {
                isFullLine = false;
                break;
            }
        }
        if (isFullLine)
        {
            fullLines.insert(line);
        }
    }

    return fullLines;
}

bool Board::moveDown()
{
    if (figures.empty())
        addFigure();

    Position activeFigurePosition = activeFigure->getPosition();
    activeFigurePosition.x += 1;

    const bool canMove = move(activeFigurePosition);
    if (!canMove)
    {
        if (activeFigurePosition.x <= 2 && figures.size() > 1)
        {
            theEnd();
            return false;
        }

        lineCheck();
        addFigure();
        return false;
    }
    return true;
}

void Board::moveLeft()
{
    Position activeFigurePosition = activeFigure->getPosition();
    activeFigurePosition.y -= 1;
    move(activeFigurePosition);
}

bool Board::moveRight()
{
    Position activeFigurePosition = activeFigure->getPosition();
    activeFigurePosition.y += 1;
    return move(activeFigurePosition);
}

bool Board::move(const Position &newPosition)
{
    if (!isFreePositionInMatrix(activeFigure, newPosition))
        return false;

    removeFromMatrix(activeFigure);
    activeFigure->setPosition(newPosition);
    addToMatrix(activeFigure);
    return true;
}

void Board::rotate()
{
    if (!isAbleToRotate())
        return;

    removeFromMatrix(activeFigure);
    std::vector<Position> blocksPositions;

    for (auto &blockPosition : activeFigure->getBlocksPositions())
        blocksPositions.push_back(getRotatedPosition(blockPosition));

    activeFigure->setBlocksPositions(blocksPositions);
    addToMatrix(activeFigure);
}

Position Board::getRotatedPosition(const Position &blockPosition)
{
    Position rotatedPosition{blockPosition.y, blockPosition.x}; // Rotate x,y positions

    switch (rotatedPosition.y)
    {
    case 0:
        rotatedPosition.y = 3;
        break;
    case 1:
        rotatedPosition.y = 2;
        break;
    case 2:
        rotatedPosition.y = 1;
        break;
    case 3:
    case 4:
        rotatedPosition.y = 0;
        break;
    }

    return rotatedPosition;
}

void Board::addToMatrix(const ObjectPtr &figure)
{
    const char symbol = figure->getSymbol();
    fillMatrixWithFigureBlocks(figure, symbol);
}

void Board::removeFromMatrix(const ObjectPtr &figure)
{
    fillMatrixWithFigureBlocks(figure, emptySymbol);
}

void Board::fillMatrixWithFigureBlocks(const ObjectPtr &figure, const char c)
{
    const Position figurePosition = figure->getPosition();

    for (const auto &blockPosition : figure->getBlocksPositions())
        if (isPositionInBoard({figurePosition.x + blockPosition.x, figurePosition.y + blockPosition.y}))
            matrix[figurePosition.x + blockPosition.x][figurePosition.y + blockPosition.y] = c;
}

bool Board::isFreePositionInMatrix(ObjectPtr figure, const Position &newPosition) const
{
    for (const auto &blockPosition : figure->getBlocksPositions())
    {
        const Position absPosition = {blockPosition.x + newPosition.x, blockPosition.y + newPosition.y};

        if (!isPositionInBoard(absPosition))
            return false;

        if (figure->isOwnBlock(absPosition))
            continue;

        if (matrix[absPosition.x][absPosition.y] != emptySymbol)
            return false;
    }
    return true;
}

bool Board::isAbleToRotate() const
{
    const Position activeFigurePosition = activeFigure->getPosition();
    for (const auto &blockPosition : activeFigure->getBlocksPositions())
    {
        Position rotatedBlockPosition = getRotatedPosition(blockPosition);
        const Position absPosition = {rotatedBlockPosition.x + activeFigurePosition.x,
                                      rotatedBlockPosition.y + activeFigurePosition.y};
        if (activeFigure->isOwnBlock(absPosition))
            continue;

        if (!isFreePositionInMatrix(absPosition))
            return false;
    }
    return true;
}

bool Board::isFreePositionInMatrix(const Position &absolutePosition) const
{
    return isPositionInBoard(absolutePosition) && isEmptyPosition({absolutePosition.x, absolutePosition.y});
}

bool Board::isGameStart() const
{
    return (figures.empty() && player.getScore() == 0);
}

bool Board::isEmptyPosition(const Position &position) const
{
    return matrix[position.x][position.y] == emptySymbol;
}

int Board::getCurrentTime() const
{
    return std::difftime(time(0), startTime);
}

bool Board::isPositionInBoard(const Position &absolutePosition) const
{
    return (
        absolutePosition.x >= 0 &&
        absolutePosition.y >= 0 &&
        absolutePosition.y < (int)matrix[0].size() - 1 &&
        absolutePosition.x < (int)matrix.size() - 1);
}

Board::ObjectPtr Board::getActiveFigure() const
{
    if (figures.size())
    {
        return figures[0];
    }
    return 0;
}

Board::Matrix Board::getMatrix() const
{
    return matrix;
}

Board::Objects Board::getFigures() const
{
    return figures;
}

Board::ObjectPtr Board::getNextFigure() const
{
    return nextFigure;
}

Player Board::getPlayer() const
{
    return player;
}

void Board::theEnd()
{
    matrix.clear();
    matrix = Matrix(Settings::height, std::vector<char>(Settings::width, emptySymbol));
    currentState = Settings::GameState::Menu;
    player.saveScore();

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