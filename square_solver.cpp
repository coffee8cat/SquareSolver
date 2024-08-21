#include "square.h"

#include <stdio.h>
#include <string.h>

#include <math.h>

#include <assert.h>
#include <errno.h>

bool are_equal(double x, double y)
{
    return fabs(x - y) < ACCURACY;
}

void clean_input_buff()
{
    while (getchar() != '\n')
        continue;
}

void choose_mode(int argc, char * argv[], coeffs coeff_p, double * x1, double * x2, solver_outcome n_roots)
{
    if(argc > 1)
    {
        execute_flags(argc, argv, coeff_p, x1, x2, n_roots);
    }
    else
    {
        start_unit_testing();

        std_mode_about();

        std_input(&coeff_p);

        n_roots = solver(coeff_p, x1, x2);

        output_solutions(*x1, *x2, n_roots);
    }
}

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

void file_input(struct coeffs * coeff_p)
{
    bool file_name_error = true;

    printf("Write a name of file for input\n");

    char file_name[20] = {};

    FILE *fp = NULL;
    while(file_name_error)
    {
        if(scanf("%19s", file_name) != 1)
        {
            printf("FILE_READ ERROR\n");
        }
        else
        {
            printf("[%s]\n", file_name);

            fp = fopen(file_name, "r");
            if ( !fp )
            {
                perror("fopen: ");
                printf("\nWrite a name of file for input\n");
            }
            else
            {
                file_name_error = false;
            }
        }
    }

    while(fscanf(fp, "%lg %lg %lg", &coeff_p->a, &coeff_p->b, &coeff_p->c) != 3)
    {
        clean_input_buff();
        fprintf(stderr, "ERROR: Only decimal coefficients allowed\n"
                        "Example: -4.6, 64, 0.7\n");
    }

    if(fclose(fp) == EOF)
    {
        printf("CLOSING_FILE_ERROR: cannot close file %s", file_name);
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
