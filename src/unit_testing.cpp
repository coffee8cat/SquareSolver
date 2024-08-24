#include <stdio.h>
#include <math.h>

#include "data.h"
#include "my_macros.h"
#include "unit_testing.h"
#include "square_solver.h"
#include "tests.h"

void start_unit_testing()
{
    for (int n_test = 0; n_test < n_tests; n_test++)
    {
        double x1 = 0, x2 = 0;
        solver_outcome test_n_roots = NO_ROOTS;

        unit_test_res test_result = run_test(n_test, test_params[n_test], x1, x2, test_n_roots);

        if (test_result == SUCCEED)
        {
            print_green("Unit test %d: SUCCESS\n", n_test+1);
        }
        else
        {
            print_red("Unit test %d failed\n", n_test+1);
        }
    }
}

void dump_unit_test_results(int n_test, struct unit_test failed_test_params,
                            double x1, double x2, solver_outcome test_n_roots)
{
    my_assert(isfinite(x1));
    my_assert(isfinite(x2));

    print_red(  "--------------------------------------------------\n"
                "RUN_TEST ERROR: test %d failed\n"
                "Input:           a = %f\n"
                "                 b = %f\n"
                "                 c = %f\n \n"
                "Expected Output: x1 = %f\n"
                "                 x2 = %f\n"
                "                 n_roots = %d\n\n"
                "Solver Output:   x1 = %f\n"
                "                 x2 = %f\n"
                "                 n_roots = %d\n\n"
                "--------------------------------------------------\n",
                n_test+1,
                failed_test_params.coeffs_t.a,   failed_test_params.coeffs_t.b,   failed_test_params.coeffs_t.c,
                failed_test_params.x1,           failed_test_params.x2,           failed_test_params.n_roots,
                x1,                              x2,                              test_n_roots);
}

unit_test_res run_test(int n_test, struct unit_test run_test_params,
                    double x1, double x2, solver_outcome test_n_roots)
{
    my_assert(isfinite(x1));
    my_assert(isfinite(x2));

    test_n_roots = solver(run_test_params.coeffs_t, &x1, &x2);

    if (test_n_roots != run_test_params.n_roots || !are_equal(x1, run_test_params.x1)
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
