#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "data.h"

void clean_input_buff()
{
    while (getchar() != '\n')
        continue;
}

bool are_equal(double x, double y)
{
    assert(isfinite(x));
    assert(isfinite(y));

    return fabs(x - y) < ACCURACY;
}
