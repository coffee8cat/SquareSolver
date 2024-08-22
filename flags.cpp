#include <stdio.h>

#include "all_service.h"
#include "flags.h"
#include "menu.h"
#include "square_solver.h"
#include "unit_testing.h"

void execute_flags(int argc, char * argv[], coeffs coeff_p, double * x1, double * x2, solver_outcome n_roots)
{
    for(int n_flag = 1; n_flag < argc; n_flag++)
    {
        if(argv[n_flag][0] == '-')
        {
            switch(argv[n_flag][1])
            {
                case 'h': help();
                          break;

                case 'u': start_unit_testing();
                          break;

                case 's': std_input(&coeff_p);
                          n_roots = solver(coeff_p, x1, x2);
                          output_solutions(*x1, *x2, n_roots);
                          break;

                case 'f': file_input(&coeff_p);
                          n_roots = solver(coeff_p, x1, x2);
                          output_solutions(*x1, *x2, n_roots);
                          break;

                default:  printf("flag error: No such flag\n");
                          break;
            }
        }
        else
        {
            printf("flag read error: incorrect input in position %d\n", n_flag + 1);
        }
    }
}
