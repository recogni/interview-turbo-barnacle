CC = gcc
CFLAGS = -Wall -g

all: mem
	./mem

mem: mem.o
	$(CC) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f mem.o mem
