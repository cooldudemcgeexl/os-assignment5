#include "philosopher.h"
#include <stdlib.h>
#include "defines.h"

int get_left(int phil_num)
{
    return (phil_num + 4) % NUM_PHILS;
}

int get_right(int phil_num)
{
    return (phil_num + 1) % NUM_PHILS;
}