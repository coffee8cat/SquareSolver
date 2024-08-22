#ifndef SQUARE_SOLVER_FLAGS_H__
#define SQUARE_SOLVER_FLAGS_H__

void execute_flags(const int argc, const char * argv[], coeffs coeff_p, double * x1, double * x2, solver_outcome n_roots);

void check_flags(const int argc, const char *argv[]);

bool check_file_name(const int argc, const char *argv[], int n_flag);

#endif //SQUARE_SOLVER_FLAGS_H__
