#include <stdio.h>
#include <string.h>
#include <math.h>

#include "data.h"
#include "my_macros.h"
#include "output_and_reading_input.h"
#include "square_solver.h"

bool file_input(struct coeffs coeff_p[MAX_FILE_INPUTS], char file_name[], int * n_read)
{
    my_assert(coeff_p != NULL);
    my_assert(file_name != NULL);
    my_assert(n_read != NULL);

    FILE *fp = NULL;

    bool reading_file = false;

    reading_file = read_file_name_and_open(&fp, file_name);

    if (reading_file)
    {
        int i = 0;

        while (fscanf(fp, "%lg %lg %lg", &coeff_p[i].a, &coeff_p[i].b, &coeff_p[i].c) != -1)
        {
            i++;
        }

        *n_read = i;

        if (fclose(fp) == EOF)
        {
            fprintf(stderr, "ERROR: Cannot close a file [%s]\n", file_name);
        }
    }
    else
    {
        printf("quit file input\n\n");
    }

    return reading_file;
}

bool read_file_name_and_open(FILE ** fp, char file_name[])
{
    my_assert(fp != NULL);
    my_assert(file_name != NULL);

    while (true)
    {
        *fp = fopen(file_name, "r");
        printf("opening file [%s]\n", file_name);

        if ( *fp )
        {
            return true;
        }
        else
        {
            fprintf(stderr, "Cannot open file [%s]\n", file_name);
        }

        printf("Write a name of file for input\n"
               "--q for returning to menu\n");

        scanf("%s", file_name);

        if (strncmp(file_name, "--q", 3) == 0)
        {
            return false;
        }
    }

    return true;
}

void std_input(struct coeffs * coeff_p)
{
    my_assert(coeff_p != NULL);

    printf("Enter a, b, c:\n");

    while (scanf("%lg %lg %lg", &coeff_p->a, &coeff_p->b, &coeff_p->c) != 3)
    {
        clean_input_buff();
        fprintf(stderr, "ERROR: Only decimal coefficients allowed\n"
                        "Example: -4.6, 64, 0.7\n");
    }
}

void output_solutions(double x1, double x2, solver_outcome nRoots)
{
    my_assert (isfinite (x1));
    my_assert (isfinite (x2));
    switch(nRoots)
    {

        case NO_ROOTS:
            printf("No solutions\n\n");
            break;

        case ONE_ROOT:
            printf("Single solution: x = %lf\n\n", x1);
            break;

        case TWO_ROOTS:
            printf("Two solutions:\n");
            printf(" x1 = %lf\n", x1);
            printf(" x2 = %lf\n\n", x2);
            break;

        case INF_ROOTS:
            printf("Infinite number of solutions\n\n");
            break;

        default:
            fprintf(stderr, "output_solutions error: nRoots = %d\n\n", nRoots);
            break;
    }
}
