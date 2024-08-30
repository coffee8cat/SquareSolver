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
 * \param[in] argc - number of elements read from cmd
 * \param[in] argv - array of char arrays with elements read from cmd
 * \param[out] flags_values - pointer to structure for setting vars to execute flags
 * \return true if flags read succesfully else false
 */
bool check_flags(flags_init *flags_values, int argc, char *const argv[]);


//void check_file_name_after_f(char * const argv[], int n_flag, struct flags_init * flags_values);

/**
 * \brief execute flag -f: read coeffs from file and solve square equation
 * \param[in] flag_values - pointer to structure to get file name order in argv
 * \details file input will be quit with reading "--q" as file name
 */
void execute_file_input_mode(char name_of_file[]);

#endif // SQUARE_SOLVER_FLAGS_H__
