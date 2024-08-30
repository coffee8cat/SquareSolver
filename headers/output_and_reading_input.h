/**
 * \file output_and_reading_input.h
 * \brief input and output functions
 */

#ifndef OUTPUT_AND_READING_INPUT_H__
#define OUTPUT_AND_READING_INPUT_H__

#include "data.h"

const int MAX_FILE_INPUTS = 100;

/// @brief where to read file name from
enum read_type_name
{
    manual,    ///< from standart input
    with_flags ///< after flag -f=
};

/**
 * \brief input coefficients for square solver from file
 * \param[in] read_type - was file name written with flags or not
 * \param[in] file name - file to read from
 * \param[out] coeff_p - pointer to structure with coefficients for square equation
 * \return false if quitting file input else true
 */
bool file_input(struct coeffs sq_coeffs[MAX_FILE_INPUTS], char file_name[], int * const n_read);

/**
 * \brief user-friendly read file name and open file with error handling
 * \param[in] fp - pointer to file
 * \param[in] file_name - variable for name of file
 * \return false if quitting file input else true
  */
bool read_file_name_and_open(FILE ** fp, char file_name[]);

/**
 * \brief input coefficients for square equation from cmd
 * \param[out] coeff_p - pointer to structure with coefficients for square equation
 */
void std_input(struct coeffs * coeffs_p);

/**
 * \brief prints solutions for square equation
 * \param[in] x1 - first root
 * \param[in] x2 - second root
 * \param[in] n_roots - number of roots
 */
void output_solutions(const double x1, const double x2, const solver_outcome n_roots);

#endif // OUTPUT_AND_READING_INPUT_H__
