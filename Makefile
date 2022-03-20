CC = gcc
OBJS = src/*.c 
OBJ = bin/la

all: build run

build:
	$(CC) $(OBJS) -o $(OBJ)

run:
	./$(OBJ)

clean:
	rm ./$(OBJ)
	echo "Cleaned!"
