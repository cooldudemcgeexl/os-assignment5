
#include <pthread.h>
#include <iostream>
#include "philosopher.h"
#include "defines.h"
#include <stdlib.h>
#include <unistd.h>
#include "overseer.h"

int philosophers[NUM_PHILS];

Overseer overseer;

void *philosoper_do(void *arg)
{
    int num_drinks = rand() % MAX_DRINKS;
    int drink = 0;
    while (drink < num_drinks)
    {
        int i = *(int *)arg;
        sleep(1);
        overseer.take_drink(i);
        sleep(0.5);
        overseer.put_drink(i);
        drink++;
    }
}

int main()
{

    srand(69);
    pthread_t thread_id[NUM_PHILS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (int i = 0; i < NUM_PHILS; i++)
    {
        philosophers[i] = i;
    }

    for (int i = 0; i < NUM_PHILS; i++)
    {
        pthread_create(&thread_id[i], &attr, philosoper_do, &philosophers[i]);
        std::cout << "Philosopher " << i + 1 << "is tranquil..." << std::endl;
    }

    for (int i = 0; i < NUM_PHILS; i++)
    {
        pthread_join(thread_id[i], NULL);
    }

    pthread_attr_destroy(&attr);
    pthread_exit(NULL);

    return 0;
}