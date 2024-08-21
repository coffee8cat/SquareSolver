#include <TXLib.h>
#include "square.h"

int main()
{
    struct coeffs sq_coeffs{0, 0, 0};

    double x1 = 0.0;
    double x2 = 0.0;

    solver_outcome nRoots = NO_ROOTS;

    start_unit_testing();

    reading_coeffs(&sq_coeffs);

    nRoots = solver(sq_coeffs, &x1, &x2);

    output_solutions(x1, x2, nRoots);
}
