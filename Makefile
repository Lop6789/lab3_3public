CC = g++
PREF_HEAD = ./Headers/
PREF_SRC = ./Src/

SOURCE = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, %.o, $(SOURCE))

all:
	$(CC) -Wall -c $(SOURCE)
	$(CC) -Wall -o lab3 $(OBJ)
	rm *.o
