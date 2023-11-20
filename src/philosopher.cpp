#include "philosopher.h"
#include <stdlib.h>
#include "defines.h"
#include <algorithm>
#include <iostream>
#include <string>

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

int Philosopher::get_left(int phil_num)
{
    return (phil_num + 4) % NUM_PHILS;
}

int Philosopher::get_right(int phil_num)
{
    return (phil_num + 1) % NUM_PHILS;
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
    std::cout << "Philosopher " << phil_num << " is " << enum_rep(state) << std::endl;
}