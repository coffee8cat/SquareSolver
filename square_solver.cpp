#include "square.h"

#include <stdio.h>
#include <string.h>

#include <math.h>

#include <assert.h>
#include <errno.h>

void show_errno()
{
    const char *err_info = "unknown error";

    switch (errno)
    {
    case EDOM:   err_info = "domain error";
                 break;

    case EILSEQ: err_info = "illegal sequence";
                 break;

    case ERANGE: err_info = "pole or range error";
                 break;
    case EINVAL: err_info = "closing file error";

    case 0:      err_info = "no error";
                 break;

    default:     break;
    }

    fputs(err_info, stdout);
    puts(" occurred\n");
}

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
    switch(argc)
    {
        case 1:     std_mode_about();
                    std_input(&coeff_p);
                    break;

        case 2:     if(strncmp(argv[1], "-h", sizeof("-h")-1) == 0)
                    {
                        help();
                    }
                    else
                    {
                        if(strncmp(argv[1], "-u", sizeof("-u")-1) == 0)
                        {
                            start_unit_testing();
                        }
                        else
                        {
                            if(strncmp(argv[1], "-s", sizeof("-s")-1) == 0)
                            {
                                std_input(&coeff_p);
                                n_roots = solver(coeff_p, x1, x2);
                                output_solutions(*x1, *x2, n_roots);
                            }
                            else
                            {
                                if(strncmp(argv[1], "-f", sizeof("-u")-1) == 0)
                                {
                                    file_input(&coeff_p);
                                    n_roots = solver(coeff_p, x1, x2);
                                    output_solutions(*x1, *x2, n_roots);
                                }
                                else
                                {
                                    printf("FLAG_READ_ERROR: No such flag");
                                }
                            }
                        }
                    }
                    break;

        default:    show_errno();
                    printf("FLAG_READ_ERROR: invalid number of arguments\n");
                    break;
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

/*void reading_coeffs(struct coeffs * coeff_p)
{
    if(read_choice() == 1)
    {
        file_input(coeff_p);
    }
    else
    {
        std_input(coeff_p);
    }
}

int read_choice()
{
    printf("Choose input type:\n"
            "FILE:  1\n"
            "stdin: 0\n");


    int is_file_input = 0;

    while (true)
    {
        if (scanf("%d", &is_file_input) != 1)
        {
            printf("Allowed input are 0 and 1\n");
        }
        else
        {
            break;
        }

        clean_input_buff();
    }

    return is_file_input;
}*/

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
                show_errno();
                printf("FILE_OPEN ERROR: No such file\n");
                printf("Write a name of file for input\n");
            }
            else
            {
                file_name_error = false;
            }
        }
    }

    while(fscanf(fp, "%lg %lg %lg", &coeff_p->a, &coeff_p->b, &coeff_p->c) != 3)
    {
        show_errno();
        clean_input_buff();
        fprintf(stderr, "ERROR: Only decimal coefficients allowed\n"
                        "Example: -4.6, 64, 0.7\n");
    }

    if(fclose(fp) == EOF)
    {
        show_errno();
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

int start_unit_testing()
{
    const int n_tests = 3;

    coeffs test_coeffs[n_tests] = {
        {1, 2, 1},
        {0, 0, 0},
        {0, 8, 9}
    };

    unit_test test_exp[n_tests] = {
        {-1,     0, ONE_ROOT},
        {0,      0, INF_ROOTS},
        {-1.125, 0, ONE_ROOT},
    };

    unit_test test_out[n_tests] = {
        {0, 0, NO_ROOTS},
        {0, 0, NO_ROOTS},
        {0, 0, NO_ROOTS}
    };

    for(int n_test = 0; n_test < n_tests; n_test++)
    {
        unit_test_res test_result = run_test(n_test, test_coeffs[n_test], test_exp[n_test], &test_out[n_test]);

        if(test_result == SUCCEED)
        {
            printf("Unit test %d: SUCCESS\n", n_test+1);
        }
        else
        {
            printf("Unit test %d failed\n", n_test+1);
        }
    }

    return n_tests;
}

void dump_unit_test_results(int n_test, struct coeffs test_coeffs, struct unit_test test_exp,
                struct unit_test test_out)
{
    printf("--------------------------------------------------\n"
               "RUN_TEST ERROR: test %d failed\n"
               "Input: a = %f, b = %f, c = %f\n \n"
               "Expected Output: x1 = %f; x2 = %f; n_roots = %d;\n"
               "Solver Output:   x1 = %f; x2 = %f; n_roots = %d;\n"
               "--------------------------------------------------\n",
               n_test,
               test_coeffs.a,   test_coeffs.b,   test_coeffs.c,
               test_exp.x1,     test_exp.x2,     test_exp.n_roots,
               test_out.x1,     test_out.x2,     test_out.n_roots);
}

unit_test_res run_test(int n_test, struct coeffs test_coeffs, struct unit_test test_exp,
                struct unit_test * test_out)
{
    test_out -> n_roots = solver(test_coeffs, &test_out -> x1, &test_out -> x2);

    if(test_out -> n_roots != test_exp.n_roots || !are_equal(test_out -> x1, test_exp.x1)
        || !are_equal(test_out -> x2, test_exp.x2))
    {
        dump_unit_test_results(n_test, test_coeffs, test_exp, *test_out);
        return FAILED;
    }
    else
    {
        return SUCCEED;
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
