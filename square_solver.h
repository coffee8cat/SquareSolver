#include "all_service.h"

#ifndef SQUARE_SOLVER_H__
#define SQUARE_SOLVER_H__

const double ACCURACY = 0.000001;

enum read_type_name{manual, with_flags};

bool are_equal(double x, double y);

void file_input(struct coeffs * coeff_p, read_type_name read_type, char file_name[]);

bool manual_read_file_name(char file_name[]);

bool open_file(char file_name[], FILE **fp);

/**--------------------------------------------------
 * @brief read coefs for ax^2 + bx + c = 0
 *
 * @param a : coef before x^2
 * @param b : coef before x
 * @param c : free coef
 *
 * @return number of roots
*/
void std_input(struct coeffs * coeffs_p);

/**--------------------------------------------------
 * @brief choose solver for ax^2 + bx + c = 0
 *
 * @param a : coef before x^2
 * @param b : coef before x
 * @param c : free coef
 * @param x1: pointer to the first root
 * @param x2: pointer to the second root
 *
 * @return number of roots
*/
solver_outcome solver(struct coeffs square_coeffs, double * const x1, double * const x2);

/**--------------------------------------------------
 * @brief solves square equation ax^2 + bx + c = 0
 *
 * @param a : coef before x^2
 * @param b : coef before x
 * @param c : free coef
 * @param x1: pointer to the first root
 * @param x2: pointer to the second root
 *
 * @return number of roots
*/
solver_outcome square_equation(struct coeffs square_coeffs, double * const x1, double * const x2);

/**--------------------------------------------------
 * @brief solves linear equation bx + c = 0
 * @param b : coef before x
 * @param c : free coef
 * @param x: pointer to the root
 * @return number of roots
*/
solver_outcome linear_equation(struct coeffs square_coeffs, double * const x);

/**--------------------------------------------------
 * @brief print solutions
 *
 * @param x1: pointer to the first root
 * @param x2: pointer to the second root
 * @param nRoots: number of roots
*/
void output_solutions(double x1, double x2, solver_outcome n_roots);

#endif // SQUARE_SOLVER_H__
