#include <stdio.h>
#include <string.h>

#include "data.h"
#include "output_and_reading_input.h"

bool file_input(struct coeffs * coeff_p, char file_name[])
{
    FILE *fp = NULL;

    bool reading_file = false;

    reading_file = read_file_name_and_open(&fp, file_name);

    if(reading_file)
    {
        while (fscanf(fp, "%lg %lg %lg", &coeff_p->a, &coeff_p->b, &coeff_p->c) != 3)
        {
            clean_input_buff();
            fprintf(stderr, "ERROR: Only decimal coefficients allowed\n"
                            "Example: -4.6, 64, 0.7\n");
        }

        if (fclose(fp) == EOF)
        {
            printf("CLOSING_FILE_ERROR: cannot close file %s\n", file_name);
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
    while (!(*fp = fopen(file_name, "r")))
    {
        printf("Write a name of file for input\n"
               "--q for returning to menu\n");

        scanf("%s", file_name);

        if(strncmp(file_name, "--q", 3) == 0)
        {
            return false;
        }

        printf("opening file [%s]\n", file_name);
    }

    return true;
}

void std_input(struct coeffs * coeff_p)
{
    printf("Enter a, b, c:\n");

    while(scanf("%lg %lg %lg", &coeff_p->a, &coeff_p->b, &coeff_p->c) != 3)
    {
        clean_input_buff();
        fprintf(stderr, "ERROR: Only decimal coefficients allowed\n"
                        "Example: -4.6, 64, 0.7\n");
    }
}

void output_solutions(double x1, double x2, solver_outcome nRoots)
{
    switch(nRoots)
    {

        case NO_ROOTS: printf("No solutions\n");
                       break;

        case ONE_ROOT: printf("Single solution: x = %lf\n", x1);
                       break;

        case TWO_ROOTS: printf("Two solutions:\n");
                        printf(" x1 = %lf\n", x1);
                        printf(" x2 = %lf\n", x2);
                        break;

        case INF_ROOTS: printf("Infinite number of solutions\n");
                        break;

        default: fprintf(stderr, "output_solutions error: nRoots = %d\n", nRoots);
                 break;
    }
}
