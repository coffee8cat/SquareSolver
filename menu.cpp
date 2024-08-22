#include <stdio.h>

#include "all_service.h"
#include "menu.h"
#include "flags.h"

void choose_mode(const int argc, const char * argv[], coeffs coeff_p, double * x1, double * x2, solver_outcome n_roots)
{
    if(argc > 1)
    {
        check_flags(argc, argv);
        execute_flags(argc, argv, coeff_p, x1, x2, n_roots);
    }
    else
    {
        std_mode_about();

        std_input(&coeff_p);

        n_roots = solver(coeff_p, x1, x2);

        output_solutions(*x1, *x2, n_roots);
    }
}

void help()
{
    printf("Use flags below after a.exe:\n"
           " -u start solver unit testing\n"
           " -h ask for help about programm\n"
           " -f reading coeffs from FILE\n\n");
}

void welcome()
{
    printf("# Square Solver\n"
           "# Ded Course 2024\n"
           "-------------------------------------\n\n");
}

void std_mode_about()
{
    printf("# use a.exe -h for help\n"
           "# std input by default\n\n");
}
