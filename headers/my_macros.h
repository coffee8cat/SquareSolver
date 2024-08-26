/**
 * \file my_macros.h
 * \brief my own version of some macros: assert, isnan, isinf
 */

#ifndef MY_SQSOLVER_MACROS_H__
#define MY_SQSOLVER_MACROS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data.h"

#define my_isnan(x) ((x) != (x))
#define my_isinf(x) (my_isnan(x-x))

#define my_assert(expr) my_assert_f(expr, #expr, __FILE__, __LINE__)

/**
 * \brief my version of assert
 * \param expr - expression to check
 * \param expression - text representation of original expression
 */
inline void my_assert_f(int expr, const char expression[], const char file_name[], int line)
{
    if (expr == 0)
    {
        fprintf(stderr, ANSI_COLOR_RED "    !!! ASSERTION FAILED !!!\n In file %s in line %d: %s\n"
                 ANSI_COLOR_RESET, file_name, line, expression);

        exit(EXIT_FAILURE);
    }
}

#endif // MY_SQSOLVER_MACROS_H__
