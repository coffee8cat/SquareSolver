#include <stdio.h>

#include "all_service.h"
#include "unit_testing.h"
#include "square_solver.h"

/**
 * \brief start unit testing
 */
void start_unit_testing()
{
    const int n_tests = 3;

    unit_test test_params[n_tests] = {
        {{1, 2, 1},     -1,  0, ONE_ROOT},
        {{0, 0, 0},      0,  0, INF_ROOTS},
        {{0, 8, 9}, -1.125,  0, ONE_ROOT},
    };

    for(int n_test = 0; n_test < n_tests; n_test++)
    {
        double x1 = 0, x2 = 0;
        solver_outcome test_n_roots = NO_ROOTS;

        unit_test_res test_result = run_test(n_test, test_params[n_test], x1, x2, test_n_roots);

        if(test_result == SUCCEED)
        {
            printf("Unit test %d: SUCCESS\n", n_test+1);
        }
        else
        {
            printf("Unit test %d failed\n", n_test+1);
        }
    }
}

/**
 * \brief dump results of failed test
 * \param n_test - number of failed test
 * \param test_params - structure with coefficients of square equation and expected roots
 * \param x1 - first root got from test
 * \param x2 - second root got from test
 * \param test_n_roots - number of roots got from test
 */
void dump_unit_test_results(int n_test, struct unit_test test_params,
                            double x1, double x2, solver_outcome test_n_roots)
{
    printf("--------------------------------------------------\n"
               "RUN_TEST ERROR: test %d failed\n"
               "Input: a = %15f, b = %30f, c = %45f\n \n"
               "Expected Output: x1 = %15f; x2 = %30f; n_roots = %45d;\n"
               "Solver Output:   x1 = %15f; x2 = %30f; n_roots = %45d;\n"
               "--------------------------------------------------\n",
               n_test,
               test_params.coeffs_t.a,   test_params.coeffs_t.b,   test_params.coeffs_t.c,
               test_params.x1,           test_params.x2,           test_params.n_roots,
               x1,                       x2,                       test_n_roots);
}

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
                    double x1, double x2, solver_outcome test_n_roots)
{
    test_n_roots = solver(test_params.coeffs_t, &x1, &x2);

    if(test_n_roots != test_params.n_roots || !are_equal(x1, test_params.x1)
        || !are_equal(x2, test_params.x2))
    {
        dump_unit_test_results(n_test, test_params, x1, x2, test_n_roots);
        return FAILED;
    }
    else
    {
        return SUCCEED;
    }
}
