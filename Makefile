CC := gcc
CFLAGS := -c
CFLAGS += -std=c99
CFLAGS += -Wall

all: main

main: main.o
	$(CC) $? -o $@

main.o: main.c
	$(CC) $(CFLAGS) $? -o $@

clean:
	rm -f *.o
