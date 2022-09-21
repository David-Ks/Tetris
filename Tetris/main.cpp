#include "Tetris.cpp"

#include "Game/Figures/StandardFigure.cpp"
#include "Game/Map/StandardBoard.cpp"
#include "Game/Graphics/NcursesWindow.cpp"
#include "Game/Graphics/StdWindow.cpp"
#include "Game/GameLoop/StdLoop.cpp"
#include "Game/Players/StandardPlayer.cpp"
#include "Game/Events/GameEvent.cpp"
#include "Game/Events/MenuEvent.cpp"

int main()
{
    Tetris game;
    game.run();

    return 0;
}