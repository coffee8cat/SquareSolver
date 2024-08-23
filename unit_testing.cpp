#include <stdio.h>

#include "data.h"
#include "unit_testing.h"
#include "square_solver.h"
#include "tests.h"

void start_unit_testing()
{
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

void dump_unit_test_results(int n_test, struct unit_test failed_test_params,
                            double x1, double x2, solver_outcome test_n_roots)
{
    printf("--------------------------------------------------\n"
               "RUN_TEST ERROR: test %d failed\n"
               "Input: a = %15f, b = %30f, c = %45f\n \n"
               "Expected Output: x1 = %15f; x2 = %30f; n_roots = %45d;\n"
               "Solver Output:   x1 = %15f; x2 = %30f; n_roots = %45d;\n"
               "--------------------------------------------------\n",
               n_test,
               failed_test_params.coeffs_t.a,   failed_test_params.coeffs_t.b,   failed_test_params.coeffs_t.c,
               failed_test_params.x1,           failed_test_params.x2,           failed_test_params.n_roots,
               x1,                              x2,                              test_n_roots);
}

unit_test_res run_test(int n_test, struct unit_test run_test_params,
                    double x1, double x2, solver_outcome test_n_roots)
{
    test_n_roots = solver(run_test_params.coeffs_t, &x1, &x2);

    if(test_n_roots != run_test_params.n_roots || !are_equal(x1, run_test_params.x1)
        || !are_equal(x2, run_test_params.x2))
    {
        dump_unit_test_results(n_test, run_test_params, x1, x2, test_n_roots);
        return FAILED;
    }
    else
    {
        return SUCCEED;
    }
}
