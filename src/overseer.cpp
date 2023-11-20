#include "overseer.h"
#include "philosopher.h"

Overseer::Overseer()
{
    for (int i = 0; i < NUM_PHILS; i++)
    {
        state[i] = PhilState::Tranquil;
    }
    for (int i = 0; i < NUM_PHILS; i++)
    {
        pthread_cond_init(&philosopherCond[i], NULL);
    }

    pthread_mutex_init(&condLock, NULL);
}

Overseer::~Overseer()
{
    for (int i = 0; i < NUM_PHILS; i++)
    {
        pthread_cond_destroy(&philosopherCond[i]);
    }

    pthread_mutex_destroy(&condLock);
}

void Overseer::test_state(int phil_num)
{
    if (state[get_left])
}

void Overseer::take_drink(int phil_num)
{
}

void Overseer::put_drink(int phil_num)
{
}