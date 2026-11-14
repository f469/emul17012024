CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c chip8.c

compile: bin/main

bin/main: $(SRC) chip8.h | bin
	$(CC) $(CFLAGS) $(SRC) -o $@

bin:
	mkdir -p bin

clean:
	rm -rf bin

.PHONY: compile clean
