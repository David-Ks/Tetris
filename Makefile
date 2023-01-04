CC=g++
CFLAGS=-c -Wall
TARGET=Tetris

SRC=$(shell find $(Game) -name '*.cpp')
OBJ=$(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) -lncurses

%.o : %.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(shell find $(Game) -name '*.o') *.o

