#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <assert.h>

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
    assert(flags_values != NULL);
    assert(argv != NULL);

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

void execute_file_input_mode(char name_of_file[])
{
    assert(name_of_file != NULL);

    coeffs sq_coeffs[MAX_FILE_INPUTS];

    double x1 = 0, x2 = 0;
    solver_outcome n_roots = NO_ROOTS;

    int n_read = 0;

    bool reading_file = file_input(sq_coeffs, name_of_file, &n_read);

    if (reading_file)
    {
        for (int i=0; i < n_read; i++)
        {
            printf("equation number %d\n"
                   "a = %f; b = %f, c = %f\n",
                   i, sq_coeffs[i].a, sq_coeffs[i].b, sq_coeffs[i].c);
            n_roots = solver(sq_coeffs[i], &x1, &x2);
            output_solutions(x1, x2, n_roots);
        }
    }
    else
    {
        printf("call menu\n");
        menu(&x1, &x2, n_roots);
    }

}
