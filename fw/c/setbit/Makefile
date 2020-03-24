all: setbit
	./setbit

setbit: main.o setbit.o
	gcc $^ -o $@

%.o: %.c
	gcc -Wall -g -O3 -c $< -o $@
