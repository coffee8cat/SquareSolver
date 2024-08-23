#ifndef MY_SQSOLVER_MACROS_H__
#define MY_SQSOLVER_MACROS_H__

#include <stdio.h>

#define my_assert(expr) (expr == 0) ? fprintf(stderr, __FILE__ __LINE__ #expr)

#endif //
