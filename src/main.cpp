
#include <pthread.h>
#include <iostream>
#include "philosopher.h"
#include "defines.h"
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <time.h>
#include "phil_graph.h"
#include "clock.h"

std::mutex cout_mutex;

PhilGraph phil_graph(NUM_PHILS);

void philosopher(Philosopher phil)
{
    {
        std::lock_guard<std::mutex> gcout(cout_mutex);
        phil.print_state();
        std::cout << phil.full_name() << " will need " << phil.num_drinks() << " drinks" << std::endl;
    }
    while (phil.drinks_remaining())
    {
        milliseconds initial_delay = rand_ms(MIN_WAIT_MS, MAX_WAIT_MS);
        {
            std::lock_guard<std::mutex> gcout(cout_mutex);
            std::cout << phil.full_name() << " will be thirsty in " << std::to_string(initial_delay.count()) << " ms" << std::endl;
        }
        std::this_thread::sleep_for(initial_delay);
        phil.state = Thirsty;
        {
            std::lock_guard<std::mutex> gcout(cout_mutex);
            phil.print_state();
        }
        mutex_ptr_pair drink_pair = phil.try_get_available_drink(&phil_graph, &cout_mutex);
        {
            std::lock_guard<std::mutex> gdrink1(*drink_pair.first);
            phil.drink(&cout_mutex);
        }
    }
}

int main()
{

    srand(69);
    std::vector<std::thread> thread_list;
    // for (int i = 0; i < NUM_PHILS; ++i)
    // {
    //     thread_list.emplace_back([&]
    //                              { philosopher(Philosopher(i + 1)); });
    // }

    // for (auto &thread : thread_list)
    // {
    //     thread.join();
    // }

    std::thread t1([&]
                   { philosopher(Philosopher(1)); });
    std::thread t2([&]
                   { philosopher(Philosopher(2)); });
    std::thread t3([&]
                   { philosopher(Philosopher(3)); });
    std::thread t4([&]
                   { philosopher(Philosopher(4)); });
    std::thread t5([&]
                   { philosopher(Philosopher(5)); });
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}