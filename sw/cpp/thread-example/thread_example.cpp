// thread example
#include <iostream> // std::cout
#include <thread>   // std::thread
#include <sstream>

#include <unistd.h>
#include <stdlib.h>
#include <queue>
#include <mutex>
#include <condition_variable>

#include "thread_queue.h"

#define LAST_MESSAGE 99999

//
// A simple message structure consisting of a sequence number and a string
//
typedef struct
{
    unsigned int sequence_number;
    std::string data;
} message_t;

//
// The input generator thread fills up a queue with message setting
// gust the message_t structures sequence_number field
//
void input_generator_thread(Queue<message_t> &oq)
{
    unsigned int count;

    std::cout << "Starting input generator " << std::endl;

    // Run for 100 monotonically increasing sequence numbers
    for (count = 0; count < 100; count++)
    {
        message_t new_message;
        new_message.sequence_number = count;
        new_message.data = std::string("");
        oq.push(new_message);
    }

    // And push a special final message in the queue
    message_t last_message;
    last_message.sequence_number = LAST_MESSAGE;
    last_message.data = "";
    oq.push(last_message);

    // And die
}

//
// The worker thread pops messages from the shared input queue and
// converts their sequence_number to a string which includes the
// sequence number and thread_id and, after a variable delay,
// pushes the modified message onto the shared output queue
//
void worker_thread(Queue<message_t> &iq, Queue<message_t> &oq, int thread_id)
{
    std::cout << "Starting worker thread " << thread_id << std::endl;

    message_t m;
    for (;;)
    {
        std::ostringstream message_string;
        m = iq.pop();
        message_string << "Sequence number " << m.sequence_number << " thread " << thread_id;
        m.data = message_string.str();
        usleep(int(1000000.0 * drand48()));
        oq.push(m);
    }
}

//
// The single "display" thread reads messages out of the output queue
// prints the .data field string
//
void display_thread(Queue<message_t> &iq)
{
    std::cout << "Starting display thread" << std::endl;
    message_t m;
    for (;;)
    {
        m = iq.pop();
        std::cout << m.data << std::endl;
        if (m.sequence_number == LAST_MESSAGE)
            return;
    }
}

int main()
{
    Queue<message_t> input_generator_q;
    Queue<message_t> result_q;

    std::cout << "Starting threads\n";

    std::thread input_generator(input_generator_thread, std::ref(input_generator_q));

    std::queue<std::thread> worker_threads;
    for (int i = 0; i < 10; i++)
    {
        worker_threads.push(std::thread(worker_thread, std::ref(input_generator_q), std::ref(result_q), std::ref(i)));
    }

    std::thread display(display_thread, std::ref(result_q));

    input_generator.join();
    display.join();

    std::cout << "Done.\n";

    exit(0);
}