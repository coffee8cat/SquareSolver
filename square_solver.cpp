#include <stdio.h>
#include <string.h>

#include <math.h>

#include <assert.h>
#include <errno.h>

#include "square_solver.h"
#include "all_service.h"

bool are_equal(double x, double y)
{
    return fabs(x - y) < ACCURACY;
}

void file_input(struct coeffs * coeff_p, read_type_name read_type, char file_name[])
{
    FILE *fp = NULL;

    if(read_type == with_flags)
    {
        if(!open_file(file_name, &fp))
        {
            bool read_status = false, open_status = false;
            while(!read_status or !open_status)
            {
                printf("Write a name of file for input\n");
                read_status = manual_read_file_name(file_name);
                printf("[%s]\n", file_name);
                open_status = open_file(file_name, &fp);
            }
        }
    }
    else
    {
        bool read_status = false, open_status = false;
        while(!read_status or !open_status)
        {
            printf("Write a name of file for input\n");
            read_status = manual_read_file_name(file_name);
            printf("[%s]\n", file_name);
            open_status = open_file(file_name, &fp);
        }
    }

    while (fscanf(fp, "%lg %lg %lg", &coeff_p->a, &coeff_p->b, &coeff_p->c) != 3)
    {
        clean_input_buff();
        fprintf(stderr, "ERROR: Only decimal coefficients allowed\n"
                        "Example: -4.6, 64, 0.7\n");
    }

    if (fclose(fp) == EOF)
    {
        printf("CLOSING_FILE_ERROR: cannot close file %s", file_name);
    }
}

bool manual_read_file_name(char file_name[])
{
    if(scanf("%19s", file_name) != 1)
    {
        printf("FILE_READ_ERROR\n");
        return false;
    }
    else
    {
        return true;
    }
}

bool open_file(char file_name[], FILE **fp)
{
    *fp = fopen(file_name, "r");
    if ( !*fp )
    {
        perror("fopen: ");
        return false;
    }
    else
    {
        return true;
    }
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

solver_outcome solver(struct coeffs sq_coeffs, double * x1, double * x2)
{

    assert (isfinite (sq_coeffs.a));
    assert (isfinite (sq_coeffs.b));
    assert (isfinite (sq_coeffs.c));

    if(are_equal(sq_coeffs.a, 0.0))
    {
        return linear_equation(sq_coeffs, x1);
    }
    else
    {
        return square_equation(sq_coeffs, x1, x2);
    }

}

solver_outcome square_equation(struct coeffs sq_coeffs, double * x1, double * x2)
{

    assert (isfinite (sq_coeffs.a));
    assert (isfinite (sq_coeffs.b));
    assert (isfinite (sq_coeffs.c));

    const double d = sq_coeffs.b * sq_coeffs.b - 4 * sq_coeffs.a * sq_coeffs.c;

    if(are_equal(d, 0.0))
    {
        * x1 = -sq_coeffs.b / (2 * sq_coeffs.a);
        return ONE_ROOT;
    }

    else
    {
        if(d > 0)
        {
            * x1 = (-sq_coeffs.b + sqrt(d)) / (2 * sq_coeffs.a);
            * x2 = (-sq_coeffs.b - sqrt(d)) / (2 * sq_coeffs.a);
            return TWO_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }
    }
}

solver_outcome linear_equation(struct coeffs sq_coeffs, double * x)
{

    if(are_equal(sq_coeffs.b, 0.0))
    {

        if(are_equal(sq_coeffs.c, 0.0))
        {
            return INF_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }
    }
    else
    {
        if(are_equal(sq_coeffs.c, 0.0))
        {
            * x = 0;
            return ONE_ROOT;
        }
        else
        {
            * x = -sq_coeffs.c / sq_coeffs.b;
            return ONE_ROOT;
        }
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
