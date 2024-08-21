#include "square.h"

const int n_tests = 3;

const test_input test[n_tests] = {
    {1, 2, 1,
    -1, 0, ONE_ROOT,
    0, 0, NO_ROOTS},

    {0, 0, 0,
    0, 0, INF_ROOTS,
    0, 0, NO_ROOTS},

    {0, 9, 8,
    -1.125, 0, ONE_ROOT,
    0, 0, NO_ROOTS}
};
