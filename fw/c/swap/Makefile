CXX = g++
CXXFLAGS = -Wall -g

all: swap
	./swap

swap: swap.o
	$(CXX) $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f swap.o swap
