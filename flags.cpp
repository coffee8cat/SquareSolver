#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "data.h"
#include "flags.h"
#include "menu.h"
#include "square_solver.h"
#include "unit_testing.h"
#include "output_and_reading_input.h"

void standart_mode()
{
    coeffs sq_coeffs = {0, 0, 0};
    double x1 = 0, x2 = 0;
    solver_outcome n_roots = NO_ROOTS;

    printf("[standart mode]\n\n");

    std_input(&sq_coeffs);
    n_roots = solver(sq_coeffs, &x1, &x2);
    output_solutions(x1, x2, n_roots);
}

void check_flags(struct flags_init * flags_values, const int argc, char * const argv[])
{
    int opt = 0;
    char optstring[] = "huf:";
    while ((opt = getopt(argc, argv, optstring)) != -1)
    {
        switch (opt)
        {
            case 'h':
                flags_values -> is_help = true;
                break;

            case 'u':
                flags_values -> is_unit_testing = true;
                break;
            case 'f':
                flags_values -> is_file_input = true;
                strncpy(flags_values -> name_of_file, optarg, strlen(optarg));
                break;

            case ':':
                printf("option -%c needs a value\n", optopt);
                break;

            case '?':
                printf("Unknown option: %c\n", optopt);
                break;

            default:
                printf("option read error\n");
                break;
        }
    }
}

/*void check_file_name_after_f(char * const argv[], int n_flag, struct flags_init * flags_values)
{
    if(argv[n_flag][2] == '=')
    {
        int n_flag_size = sizeof(argv[n_flag]);
        for(int i=3; i < n_flag_size; i++)
        {
            flags_values -> name_of_file[i-3] = argv[n_flag][i];
        }
    }
    else
    {
        printf("-f syntax error: use -f=file_name.txt\n");
    }
}*/

void execute_file_reading(struct flags_init * flags_values)
{
    coeffs sq_coeffs = {0, 0, 0};
    double x1 = 0, x2 = 0;
    solver_outcome n_roots = NO_ROOTS;

    bool reading_file = file_input(&sq_coeffs, flags_values -> name_of_file);

    if(reading_file)
    {
        n_roots = solver(sq_coeffs, &x1, &x2);
        output_solutions(x1, x2, n_roots);
    }
    else
    {
        printf("call menu\n");
        menu(sq_coeffs, &x1, &x2, n_roots);
    }

}
