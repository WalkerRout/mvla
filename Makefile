CC = gcc
OBJ = bin/mvla
OBJS = tests/*.c
CFLAGS = -O1 -g -Wall -Wextra -Wpedantic -Werror
LIBS = -lm

all: test

build:
	@$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(OBJ)

test: build
	@./$(OBJ)

debug:
	@valgrind -s ./$(OBJ)

clean:
	@rm ./$(OBJ)
	@echo "Cleaned!"
