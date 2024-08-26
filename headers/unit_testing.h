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
 * \param[in] n_test - number of failed test
 * \param[in] test_params - structure with coefficients of square equation and expected roots
 * \param[in] x1 - first root got from test
 * \param[in] x2 - second root got from test
 * \param[in] test_n_roots - number of roots got from test
 */
void dump_unit_test_results(const size_t n_test, const struct unit_test failed_test_params,
                            const double x1, const double x2, const solver_outcome test_n_roots);

/**
 * \brief run single test from unit testing
 * \param[in] n_test - test number
 * \param[in] test_params - structure with coefficients for square equation,
 *                      expected roots and their number
 * \param[out] x1 - variable for the first root
 * \param[out] x2 - variable for the second root
 * \param[out] n_roots - variable for the number of roots
 * \return FAILED if test failed, else SUCCCED
 */
unit_test_res run_test(const size_t n_test, const struct unit_test test_params,
                            double x1, double x2, solver_outcome test_n_roots);

#endif // UNIT_TESTING_H__
