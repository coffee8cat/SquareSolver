#include <stdio.h>
#include <assert.h>


#include "data.h"
#include "menu.h"
#include "flags.h"
#include "output_and_reading_input.h"

bool is_standart_mode(const int argc)
{
    return argc == 1;
}

bool menu(double * x1, double * x2, solver_outcome n_roots)
{
    assert(x1 != NULL);
    assert(x2 != NULL);

    coeffs sq_coeffs = {0, 0, 0};

    char input = 'a';
    print_choose_input();

    while (true)
    {
        while (scanf("%c", &input) != 1)
        {
            printf("Only f, c, q are read as answeres\n");
            print_choose_input();
        }

        switch (input)
        {
            case 'f':
                char file_name[BUFSIZ];
                execute_file_input_mode(file_name);

                return true;

            case 'c':
                std_input(&sq_coeffs);
                n_roots = solver(sq_coeffs, x1, x2);
                output_solutions(*x1, *x2, n_roots);

                return true;

            case 'q':
                printf("quit menu\n");
                return false;

            default:
                printf("Only f, c, q are read as answeres\n");
                break;
        }
    }
}

void print_choose_input()
{
    printf("Choose input type:\n"
           "File input:     f\n"
           "Console input:  c\n"
           "Quit:           q\n");
}

void help()
{
    printf("Use flags below after a.exe:\n"
           " -u start solver unit testing\n"
           " -h ask for help about programm\n"
           " -f [file name] reading coeffs from FILE\n\n");
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
           "# std input by default\n\n");
}
