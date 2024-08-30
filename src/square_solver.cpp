#include <stdio.h>
#include <string.h>

#include <math.h>

#include <assert.h>
#include <errno.h>

#include "square_solver.h"
#include "data.h"
#include "my_macros.h"

solver_outcome solver(const struct coeffs sq_coeffs, double *const x1, double *const x2)
{
    my_assert (isfinite (sq_coeffs.a));
    my_assert (isfinite (sq_coeffs.b));
    my_assert (isfinite (sq_coeffs.c));

    if(are_equal(sq_coeffs.a, 0.0))
    {
        return linear_equation(sq_coeffs, x1);
    }
    else
    {
        return square_equation(sq_coeffs, x1, x2);
    }
}

solver_outcome square_equation(const struct coeffs sq_coeffs, double *const x1, double *const x2)
{
    my_assert (isfinite (sq_coeffs.a));
    my_assert (isfinite (sq_coeffs.b));
    my_assert (isfinite (sq_coeffs.c));

    const double d = sq_coeffs.b * sq_coeffs.b - 4 * sq_coeffs.a * sq_coeffs.c;

    if(are_equal(d, 0.0))
    {
        *x1 = -sq_coeffs.b / (2 * sq_coeffs.a);
        return ONE_ROOT;
    }
    else
    {
        if(d > 0)
        {
            *x1 = (-sq_coeffs.b + sqrt(d)) / (2 * sq_coeffs.a);
            *x2 = (-sq_coeffs.b - sqrt(d)) / (2 * sq_coeffs.a);
            return TWO_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }
    }
}

solver_outcome linear_equation(const coeffs sq_coeffs, double *const x)
{
    my_assert(x != NULL);
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
            *x = 0;
        }
        else
        {
            *x = -sq_coeffs.c / sq_coeffs.b;
        }

        return ONE_ROOT;
    }
}
