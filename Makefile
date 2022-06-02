CC = gcc
OBJS = src/*.c 
OBJ = bin/mvla
CFLAGS = 
LIBS = -lm

all: build run

build:
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(OBJ)

run:
	./$(OBJ)

clean:
	rm ./$(OBJ)
	echo "Cleaned!"
