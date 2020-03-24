GCC := gcc
GCCFLAGS := -Wall -g

all: main
	./main

main: main.o
	$(GCC) $< -o $@

%.o: %.c
	$(GCC) $(GCCFLAGS) -c $< -o $@

clean:
	rm -f main.o main
