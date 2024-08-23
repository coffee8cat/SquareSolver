/**
 * \file tests.h
 * \brief data for unit_testing
 */

#ifndef TESTS_FOR_UNIT_TESTING_H__
#define TESTS_FOR_UNIT_TESTING_H__

#include "unit_testing.h"

const int n_tests = 5; /// \brief nuber of unit tests

unit_test test_params[n_tests] = {
    {{1, 2, 1},     -1,  0, ONE_ROOT},
    {{0, 0, 0},      0,  0, INF_ROOTS},
    {{0, 8, 9}, -1.125,  0, ONE_ROOT},
    {{3.5, 7.47, -34.7888}, 2.261288, -4.395574, TWO_ROOTS},
    {{48.007, 12.47, 1374.99}, 0, 0, NO_ROOTS}
};


#endif //TESTS_FOR_UNIT_TESTING_H__
