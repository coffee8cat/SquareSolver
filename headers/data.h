/**
 * \file data.h
 * \brief essential data and functions for all files in project
 */

#ifndef ALL_SERVICE_SQUARE_EQUATION_H__
#define ALL_SERVICE_SQUARE_EQUATION_H__

#include <stdio.h>
#include <math.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define print_red(...)  printf(ANSI_COLOR_RED);\
                        printf(__VA_ARGS__); \
                        printf(ANSI_COLOR_RESET)

#define print_green(...)    printf(ANSI_COLOR_GREEN);\
                            printf(__VA_ARGS__); \
                            printf(ANSI_COLOR_RESET)

const double ACCURACY = 0.000001; ///< accuracy for all calculations in programm

/// @brief structure for setting flags to execute based on programm start
struct flags_init
{
    bool is_help;          ///< execute -h help: print info about flags
    bool is_unit_testing;  ///< execute -u start unit testing
    bool is_file_input;    ///< execute -f=[file_name] reading coeffs from file
    char name_of_file[BUFSIZ]; ///< order of file name in input array with flags
};

/// @brief coefficients for square equation ax^2 + bx + c = 0
struct coeffs
{
    double a; ///< coefficient before x^2
    double b; ///< coefficient before x
    double c; ///< free coefficient
};

/// @brief number of roots of square equation
enum solver_outcome
{
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};

/**
 * \brief clean input buffer
 */
inline void clean_input_buff()
{
    while (getchar() != '\n')
        continue;
}

/**
 * \brief check if two double number are equal with precised accuracy
 * \param x, y - double numbers to check
 * \return true if equal else false
 */
inline bool are_equal(double x, double y)
{
    return fabs(x - y) < ACCURACY;
}

#endif // ALL_SERVICE_SQUARE_EQUATION_H__
