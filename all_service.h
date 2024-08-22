#ifndef ALL_SERVICE_SQUARE_EQUATION_H__
#define ALL_SERVICE_SQUARE_EQUATION_H__

struct coeffs {double a; double b; double c;};

enum solver_outcome {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS};

void clean_input_buff();

#endif // ALL_SERVICE_SQUARE_EQUATION_H__
