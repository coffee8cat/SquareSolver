#include <stdio.h>
#include <string.h>

#include <math.h>

#include <assert.h>
#include <errno.h>

#include "square_solver.h"
#include "all_service.h"

/**
 * \brief check if two double number are equal with precised accuracy
 * \param x, y - double numbers to check
 */
bool are_equal(double x, double y)
{
    return fabs(x - y) < ACCURACY;
}

/**
 * \brief input coefficients for square solver from file
 * \param coeff_p - pointer to structure with coefficients for square equation
 * \param read_type - was file name written with flags or not
 * \param file name - file to read from
 */
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

/**
 * \brief read file name from cmd
 * \param file name - for reading name of file
 * \return true if file name read succesfully else false
 */
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

/**
 * \brief open a file with perror in case of fail
 * \param file name - name of file to open
 * \param fp - pointer to pointer to file
 * \return true if opened succesfully else false
 */
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

/**
 * \brief input coefficients for square equation from cmd
 * \param coeff_p - pointer to structure with coefficients for square equation
 */
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

/**
 * \brief choosing solver for square equation
 * \param sq_coeffs - coefficients for square equation
 * \param x1 - pointer to the first root
 * \param x2 - pointer to the second root
 * \return square equation has : NO_ROOTS
 *                               ONE_ROOT
 *                               TWO_ROOTS
 *                               INF_NUM_OF_ROOTS
 */
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

/**
 * \brief solve square equation
 * \param sq_coeffs - coefficients for square equation
 * \param x1 - pointer to the first root
 * \param x2 - pointer to the second root
 * \return square equation has : NO_ROOTS
 *                               ONE_ROOT
 *                               TWO_ROOTS
 *                               INF_NUM_OF_ROOTS
 */
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

/**
 * \brief solves linear equation
 * \param sq_coeffs - coefficients for square equation (coeff a = 0)
 * \param x - pointer to the first root
 * \return square equation has : NO_ROOTS
 *                               ONE_ROOT
 *                               INF_NUM_OF_ROOTS
 */
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

/**
 * \brief prints solutions for square equation
 * \param x1 - first root
 * \param x2 - second root
 * \param n_roots - number of roots
 */
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
