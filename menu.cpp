#include <stdio.h>

#include "all_service.h"
#include "menu.h"
#include "flags.h"

void choose_mode(int argc, char * argv[], coeffs coeff_p, double * x1, double * x2, solver_outcome n_roots)
{
    if(argc > 1)
    {
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
           " -f reading coeffs from FILE\n"
           " -s reading coeffs from STDIN\n"
           " -u start solver unit testing\n"
           " -h ask for help about programm\n");
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
           "# std input by default\n");
}
