all: thread_example

thread_example: thread_example.o
	g++ -o $@ $< -lpthread

thread_example.o: thread_example.cpp thread_queue.h
	g++ -std=c++14 -c $<

clean:
	rm -f thread_example thread_example.o