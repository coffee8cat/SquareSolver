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

#ifndef N_DEBUG
#define my_assert(expr) my_assert_f(expr, #expr, __FILE__, __LINE__, __func__)

#else
#define my_assert(expr); ;
#endif

/**
 * \brief my version of assert
 * \param[in] expr - expression to check
 * \param[in] expression - text representation of original expression
 */
inline void my_assert_f(const int expr, const char expression[], const char file_name[], const int line,
                        const char func_name[])
{
    if (expr == 0)
    {
        fprintf(stderr, ANSI_COLOR_RED "    !!! ASSERTION FAILED !!!\n In file %s function %s in line %d: %s\n"
                 ANSI_COLOR_RESET, file_name, func_name, line, expression);

        exit(EXIT_FAILURE);
    }
}

#endif // MY_SQSOLVER_MACROS_H__
