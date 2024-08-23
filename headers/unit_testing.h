/**
 * \file unit_testing.h
 * \brief unit_testing functions and structures
 */

#ifndef UNIT_TESTING_H__
#define UNIT_TESTING_H__

#include "data.h"

/// @brief unit_test result
enum unit_test_res
{
    SUCCEED,
    FAILED
};

/// @brief data for single unit test
struct unit_test
{
    struct coeffs coeffs_t; ///< coefficients for square equation
    double x1;              ///< expected first root
    double x2;              ///< expected second root
    solver_outcome n_roots; ///< expected number of roots
};

/**
 * \brief start unit testing
 */
void start_unit_testing();

/**
 * \brief dump results of failed test
 * \param n_test - number of failed test
 * \param test_params - structure with coefficients of square equation and expected roots
 * \param x1 - first root got from test
 * \param x2 - second root got from test
 * \param test_n_roots - number of roots got from test
 */
void dump_unit_test_results(int n_test, struct unit_test test_params,
                            double x1, double x2, solver_outcome test_n_roots);

/**
 * \brief run single test from unit testing
 * \param n_test - test number
 * \param test_params - structure with coefficients for square equation,
 *                      expected roots and their number
 * \param x1 - variable for the first root
 * \param x2 - variable for the second root
 * \param n_roots - variable for the number of roots
 * \return FAILED if test failed, else SUCCCED
 */
unit_test_res run_test(int n_test, struct unit_test test_params,
                            double x1, double x2, solver_outcome test_n_roots);

#endif //UNIT_TESTING_H__
