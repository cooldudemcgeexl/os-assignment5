#pragma once
#include "defines.h"

enum PhilState
{
    Tranquil,
    Thirsty,
    Drinking,
};

int get_left(int phil_num);
int get_right(int phil_num);