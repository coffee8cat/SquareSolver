#include <TXLib.h>
#include "all_service.h"
#include "menu.h"

int main(int argc, char * argv[])
{
    errno = 0;

    coeffs sq_coeffs = {0, 0, 0};

    double x1 = 0, x2 = 0;

    solver_outcome n_roots = NO_ROOTS;

    welcome();
    choose_mode(argc, argv, sq_coeffs, &x1, &x2, n_roots);

}
