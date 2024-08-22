#include "all_service.h"

#ifndef UNIT_TESTING_H__
#define UNIT_TESTING_H__

enum unit_test_res {SUCCEED, FAILED};

struct unit_test {struct coeffs coeffs_t; double x1; double x2; solver_outcome n_roots;};

void start_unit_testing();

void dump_unit_test_results(int n_test, struct unit_test test_params,
                            double x1, double x2, solver_outcome test_n_roots);

unit_test_res run_test(int n_test, struct unit_test test_params,
                            double x1, double x2, solver_outcome test_n_roots);

#endif //UNIT_TESTING_H__
