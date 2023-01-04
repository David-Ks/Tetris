#!/bin/sh

g++ -Wall -g main.cpp $(find Game -type f -iregex ".*\.cpp") -lncurses
