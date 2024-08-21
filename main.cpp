#include <TXLib.h>
#include "square.h"

int main(int argc, char * argv[])
{
    coeffs sq_coeffs = {0, 0, 0};

    double x1 = 0, x2 = 0;

    solver_outcome n_roots = NO_ROOTS;

    choose_mode(argc, argv, sq_coeffs);

    n_roots = solver(sq_coeffs, &x1, &x2);

    output_solutions(x1, x2, n_roots);
}
