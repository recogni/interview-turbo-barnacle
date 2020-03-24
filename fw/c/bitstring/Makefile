all: bitstring
	./bitstring

bitstring: main.o bitstring.o insbitstring.o
	g++ $^ -o $@

%.o: %.c
	gcc -Wall -g -c $< -o $@
