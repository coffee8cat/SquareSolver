#include <stdio.h>
#include <string.h>

#include "all_service.h"
#include "flags.h"
#include "menu.h"
#include "square_solver.h"
#include "unit_testing.h"

/**
 * \details look for mistakes in input
 *          execute -h first if found
 * \param argc - number of elements read from cmd
 * \param argv - array of char arrays with elements read from cmd
 */
void check_flags(const int argc, const  char *argv[])
{
    for(int n_flag = 1; n_flag < argc; n_flag++)
    {
        bool help_state = false;

        if(argv[n_flag][0] == '-')
        {
            switch(argv[n_flag][1])
            {
                case 'h': if(!help_state)
                          {
                              help();
                              help_state = true;
                              break;
                          }
                          break;

                case 'u': break;

                case 'f': break;

                default:  printf("flag error: No such flag\n");
                          break;
            }
        }
    }
}

/**
 * \brief read and execute flags
 * \param argc - number of elements read from cmd
 * \param argv - array of char arrays with elements read from cmd
 * \param coeff_p - pointer to structure with coefficients of square equation
 * \param x1 - pointer to the first root
 * \param x2 - pointer to the second root
 * \param n_roots - number of roots will be written here
 * \details -u start unit testing
 *          -f input from file for square equation solver
 *          -h print info about flags
 */
void execute_flags(const int argc, const char * argv[], coeffs coeff_p, double * x1, double * x2, solver_outcome n_roots)
{
    for(int n_flag = 1; n_flag < argc; n_flag++)
    {
        if(argv[n_flag][0] == '-')
        {
            switch(argv[n_flag][1])
            {
                case 'u': start_unit_testing();
                          break;

                case 'f': char file_name[20];
                          if(check_file_name(argc, argv, n_flag))
                          {
                              strncpy(file_name, argv[n_flag+1], 20);
                              file_input(&coeff_p, with_flags, file_name);
                              n_flag++;
                          }
                          else
                          {
                              file_input(&coeff_p, manual, file_name);
                          }
                          n_roots = solver(coeff_p, x1, x2);
                          output_solutions(*x1, *x2, n_roots);
                          break;

                default:  break;
            }
        }
        else
        {
            printf("flag read error: incorrect input in position %d\n", n_flag + 1);
        }
    }
}

/**
 * \brief check if file name was written after flag -f
 * \param argc - number of elements read from cmd
 * \param argv - array of char arrays with elements read from cmd
 * \param n_flag - flag number
 */
bool check_file_name(const int argc, const char *argv[], int n_flag)
{
    if(n_flag < argc && argv[n_flag + 1][0] != '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}
