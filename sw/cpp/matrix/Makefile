G++ := g++
CPPFLAGS := -Wall -std=c++11 -g -O3

all: main
	./main

main: main.o
	$(G++) $< -o $@

%.o: %.cpp
	$(G++) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f main.o main
