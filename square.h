#ifndef SQUARE_SOLVER_H__
#define SQUARE_SOLVER_H__

struct coeffs {double a; double b; double c;};

enum solver_outcome {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS};

enum unit_test_res {SUCCEED, FAILED};

struct unit_test {struct coeffs coeffs_t; double x1; double x2; solver_outcome n_roots;};

const double ACCURACY = 0.000001;

bool are_equal(double x, double y);

void clean_input_buff();

void choose_mode(int argc, char * argv[], coeffs coeff_p, double * x1, double * x2, solver_outcome n_roots);

void help();

void welcome();

void std_mode_about();

void reading_coeffs(struct coeffs * coeffs_p);

int read_choice();

void file_input(struct coeffs * coeffs_p);
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

int start_unit_testing();

void dump_unit_test_results(int n_test, struct unit_test test_params,
                            double x1, double x2, solver_outcome test_n_roots);

unit_test_res run_test(int n_test, struct unit_test test_params,
                            double x1, double x2, solver_outcome test_n_roots);

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
