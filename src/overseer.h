#pragma once
#include "defines.h"
#include <pthread.h>
#include "philosopher.h"

class Overseer
{
    PhilState state[NUM_PHILS];

    pthread_cond_t philosopherCond[NUM_PHILS];

    pthread_mutex_t condLock;

public:
    void test_state(int phil_num);

    void take_drink(int phil_num);

    void put_drink(int phil_num);

    Overseer();
    ~Overseer();
};