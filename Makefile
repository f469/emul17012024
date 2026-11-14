CC     = gcc
CFLAGS = -Wall -Wextra -g
SRC    = main.c chip8.c

bin/main: $(SRC) chip8.h | bin
	$(CC) $(CFLAGS) $(SRC) -o $@

bin:
	mkdir -p bin

compile: bin/main

clean:
	rm -rf bin

.PHONY: compile clean
