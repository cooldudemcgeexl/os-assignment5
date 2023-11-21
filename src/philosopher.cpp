#include "philosopher.h"
#include <stdlib.h>
#include "defines.h"
#include <algorithm>
#include <iostream>
#include <string>
#include "clock.h"
#include <thread>

auto enum_rep(PhilState state)
{
    switch (state)
    {
    case PhilState::Tranquil:
        return "Tranquil";
    case PhilState::Thirsty:
        return "Thirsty";
    case PhilState::Drinking:
        return "Drinking";
    }
    return "Unknown";
}

std::vector<int> Philosopher::make_drink_vec(int num_drinks, int num_phils)
{
    std::vector<int> drink_vec(num_drinks);
    for (auto i = 0; i < num_drinks; i++)
    {
        drink_vec.push_back(std::rand() % num_phils);
    }
    return drink_vec;
}

Philosopher::Philosopher(int phil_num)
{
    this->phil_num = phil_num;
    drink_vec = make_drink_vec(std::rand() % MAX_DRINKS + 1, NUM_PHILS);
    state = PhilState::Tranquil;
}

Philosopher::~Philosopher()
{
}

int Philosopher::num_drinks()
{
    return drink_vec.size();
}

int Philosopher::get_num()
{
    return this->phil_num;
}

void Philosopher::print_drinks()
{
    for (auto i : drink_vec)
    {
        std::cout << i << ",";
    }
    std::cout << std::endl;
}

void Philosopher::print_state()
{
    std::cout << full_name() << " is " << enum_rep(state) << std::endl;
}

mutex_ptr_pair Philosopher::try_get_available_drink(PhilGraph *phil_graph, std::mutex *cout_mutex)
{
    int phil_index = get_phil_index();
    while (state == PhilState::Thirsty)
    {
        for (unsigned i = 0; i < drink_vec.size(); ++i)
        {
            auto drink = drink_vec[i];
            if (phil_graph->is_drink_free(phil_index, drink))
            {
                std::cout << full_name() << " getting drink " << drink << std::endl;
                drink_vec.erase(drink_vec.begin() + i);
                return std::make_pair(phil_graph->get_lock(phil_index, drink), phil_graph->get_lock(drink, phil_index));
            }
        }
    }
}

void Philosopher::drink(std::mutex *cout_mutex)
{
    this->state = PhilState::Drinking;
    {
        std::lock_guard<std::mutex> gcout(*cout_mutex);
        print_state();
    }
    milliseconds drink_time = rand_ms(MIN_WAIT_MS, MAX_WAIT_MS);
    std::this_thread::sleep_for(drink_time);
    {
        std::lock_guard<std::mutex> gcout(*cout_mutex);
        std::cout << full_name() << " finished drinking" << std::endl;
    }
    this->state = PhilState::Tranquil;
}