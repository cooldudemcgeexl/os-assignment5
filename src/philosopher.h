#pragma once
#include "defines.h"
#include <vector>
#include <string>

enum PhilState
{
    Tranquil,
    Thirsty,
    Drinking,
};
class Philosopher
{
    int phil_num;
    std::vector<int> drink_vec;

    std::vector<int> make_drink_vec(int num_drinks, int num_phils);

public:
    PhilState state;

    int get_left(int phil_num);
    int get_right(int phil_num);
    int num_drinks();
    int get_num();
    std::string full_name() { return std::string("Philosopher ") + std::to_string(phil_num); }

    void print_drinks();

    Philosopher(int phil_num);
    ~Philosopher();

    std::vector<int> wanted_drinks() { return drink_vec; };
    int get_phil_index() { return phil_num - 1; };

    void print_state();
    bool drinks_remaining() { return !drink_vec.empty(); };
};
