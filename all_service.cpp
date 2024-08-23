#include "data.h"
#include <stdio.h>
#include <math.h>

void clean_input_buff()
{
    while (getchar() != '\n')
        continue;
}

bool are_equal(double x, double y)
{
    return fabs(x - y) < ACCURACY;
}
