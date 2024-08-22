#include "all_service.h"
#include "unit_testing.h"
#include "square_solver.h"

#ifndef MENU_CHOOSING_MODE_H__
#define MENU_CHOOSING_MODE_H__

void choose_mode(int argc, char * argv[], coeffs coeff_p, double * x1, double * x2, solver_outcome n_roots);

void help();

void welcome();

void std_mode_about();

#endif //MENU_CHOOSING_MODE_H__
