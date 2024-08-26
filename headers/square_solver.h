/**
 * \file square_solver.h
 * \brief solving cases of square equation
 */

#ifndef SQUARE_SOLVER_H__
#define SQUARE_SOLVER_H__

#include "data.h"

/**
 * \brief choosing solver for square equation
 * \param[in] sq_coeffs - coefficients for square equation
 * \param[out] x1 - pointer to the first root
 * \param[out] x2 - pointer to the second root
 * \return square equation has : NO_ROOTS
 *                               ONE_ROOT
 *                               TWO_ROOTS
 *                               INF_NUM_OF_ROOTS
 */
solver_outcome solver(const struct coeffs square_coeffs, double * const x1, double * const x2);

/**
 * \brief solve square equation
 * \param[in] sq_coeffs - coefficients for square equation
 * \param[out] x1 - pointer to the first root
 * \param[out] x2 - pointer to the second root
 * \return square equation has : NO_ROOTS
 *                               ONE_ROOT
 *                               TWO_ROOTS
 *                               INF_NUM_OF_ROOTS
 */
solver_outcome square_equation(const struct coeffs square_coeffs, double * const x1, double * const x2);

/**
 * \brief solves linear equation
 * \param[in] sq_coeffs - coefficients for square equation (coeff a = 0)
 * \param[out] x - pointer to the first root
 * \return square equation has : NO_ROOTS
 *                               ONE_ROOT
 *                               INF_NUM_OF_ROOTS
 */
solver_outcome linear_equation(const struct coeffs square_coeffs, double * const x);

#endif // SQUARE_SOLVER_H__
