#!/bin/sh

#g++ main.cpp Game/Tetris.cpp Game/Utils/Objects/Tools.cpp Game/src/Scripts/BoardScript.cpp Game/src/Players/Player.cpp Game/src/Graphics/NcursesWindow.cpp Game/src/Graphics/IostreamWindow.cpp -lncurses
g++ -g main.cpp $(find Game -type f -iregex ".*\.cpp") -o tetris -lncurses

