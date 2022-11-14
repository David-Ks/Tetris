#!/bin/sh

g++ -g main.cpp $(find Game -type f -iregex ".*\.cpp") -lncurses
#./a.out
#rm tetris
