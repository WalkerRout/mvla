CC = gcc
OBJS = src/*.c 
OBJ = bin/mvla
CFLAGS = -O3
LIBS = -lm

all: run

build:
	@$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(OBJ)

run: build
	@./$(OBJ)

debug:
	@valgrind -s ./$(OBJ)

clean:
	@rm ./$(OBJ)
	@echo "Cleaned!"
