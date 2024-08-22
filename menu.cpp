#include <stdio.h>

#include "all_service.h"
#include "menu.h"
#include "flags.h"

/**
 * \brief mode based on launch with flags or not
 * \param argc - number of elements read from cmd
 * \param argv - array with char arrays: elements read from cmd
 * \param coeff_p - pointer to structure with coefficients of square equation
 * \param x1 - pointer to the first root
 * \param x2 - pointer to the second root
 * \param n_roots - number of roots will be written here
 * \details in case without flags will run standart mode with cmd input and solving square equation
 * in case with flags will execute flag commands
 */
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


/**
 * \brief print info about flags
 */
void help()
{
    printf("Use flags below after a.exe:\n"
           " -u start solver unit testing\n"
           " -h ask for help about programm\n"
           " -f reading coeffs from FILE\n\n");
}
/**
 * \brief print welcoming message
 */
void welcome()
{
    printf("# Square Solver\n"
           "# Ded Course 2024\n"
           "-------------------------------------\n\n");
}

/**
 * \brief print mode name and about -h flag for help
 */
void std_mode_about()
{
    printf("# use a.exe -h for help\n"
           "# std input by default\n\n");
}
