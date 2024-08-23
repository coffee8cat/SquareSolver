/**
 * \file menu.h
 * \brief user interface functions
 */

#ifndef MENU_CHOOSING_MODE_H__
#define MENU_CHOOSING_MODE_H__

#include "data.h"
#include "unit_testing.h"
#include "square_solver.h"

/**
 * \brief mode based on launch with flags or not
 * \param argc - number of elements read from cmd
 * \param argv - array with char arrays: elements read from cmd
 * \param coeff_p - pointer to structure with coefficients of square equation
 * \param x1 - pointer to the first root
 * \param x2 - pointer to the second root
 * \param n_roots - number of roots will be written here
 * \details in case without flags will run standart mode with cmd input and solving square equation
 * in case with flags will execute flag commands
 */
bool is_standart_mode(const int argc);

bool menu(struct coeffs coeff_p, double * x1, double * x2, solver_outcome n_roots);

void print_choose_input();
/**
 * \brief print info about flags
 */
void help();

/**
 * \brief print welcoming message
 */
void welcome();

/**
 * \brief print mode name and about -h flag for help
 */
void std_mode_about();

#endif //MENU_CHOOSING_MODE_H__
