/**
 * \file flags.h
 * \brief handling executing flags functions
 */

#ifndef SQUARE_SOLVER_FLAGS_H__
#define SQUARE_SOLVER_FLAGS_H__

#include "data.h"

/**
 * \brief read coefficients from standart input once and solve the equation
 */
void standart_mode();

/**
 * \details look for mistakes in input
 *          execute -h first if found
 * \param flags_values - pointer to structure for setting vars to execute flags
 * \param argc - number of elements read from cmd
 * \param argv - array of char arrays with elements read from cmd
 */
void check_flags(struct flags_init * flags_values, const int argc, char * const argv[]);


//void check_file_name_after_f(char * const argv[], int n_flag, struct flags_init * flags_values);

/**
 * \brief execute flag -f: read coeffs from file and solve square equation
 * \param flag_values - pointer to structure to get file name order in argv
 * \details file input will be quit with reading "--q" as file name
 */
void execute_file_reading(struct flags_init * flags_values);

#endif //SQUARE_SOLVER_FLAGS_H__
