#ifndef MY_SQSOLVER_MACROS_H__
#define MY_SQSOLVER_MACROS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data.h"

#define my_isnan(x) ((x) != (x))
#define my_isinf(x) (my_isnan(x-x))

#define my_assert(expr) my_assert_f(expr, #expr)

inline void my_assert_f(int expr, const char expression[])
{
    if (expr == 0)
    {
        fprintf(stderr, ANSI_COLOR_RED "    !!! ASSERTION FAILED !!!\n" __FILE__ " line %d: %s\n"
                 ANSI_COLOR_RESET, __LINE__ , expression);

        exit(EXIT_FAILURE);
    }
}

#endif //
