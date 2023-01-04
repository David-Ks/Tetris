#include "Figure.hpp"

#include <cstdlib>
#include <ctime>

Figure::Figure()
{
    position = {0, 0};

    type = generateType();
    const auto figureBlocksPositions = Settings::figureTypes[type];

    for (const auto &position : figureBlocksPositions)
    {
        const Position blockPosition = {position[0], position[1]};
        addBlocksPosition(blockPosition);
    }
}

int Figure::generateType() const
{
    srand(time(0));

    static int lastType = rand() % Settings::figureTypes.size();
    int newType = rand() % Settings::figureTypes.size();

    while (lastType == newType)
    {
        newType = rand() % Settings::figureTypes.size();
    }
    lastType = newType;

    return newType;
}

void Figure::removeBlocksPosition(Position localPosition)
{
    for (Positions::size_type i = 0; i < blocksPositions.size(); i++)
    {
        if (blocksPositions[i].x == localPosition.x &&
            blocksPositions[i].y == localPosition.y)
        {
            blocksPositions.erase(blocksPositions.begin() + i);
            break;
        }
    }
}

void Figure::addBlocksPosition(Position localPosition)
{
    blocksPositions.push_back(localPosition);
}

bool Figure::isOwnBlock(const Position &absolutePosition) const
{
    for (const auto &blockPosition : blocksPositions)
    {
        if (blockPosition.x + position.x == absolutePosition.x &&
            blockPosition.y + position.y == absolutePosition.y)
        {
            return true;
        }
    }
    return false;
}

char Figure::getSymbol() const
{
    switch (type)
    {
    case 0:
        return '$';
    case 1:
        return '#';
    case 2:
        return '@';
    case 3:
        return '%';
    case 4:
        return '&';
    case 5:
        return '=';
    case 6:
        return '+';
    default:
        return '#';
    }
}
