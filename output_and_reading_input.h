/**
 * \file output_and_reading_input.h
 * \brief input and output functions
 */

#ifndef OUTPUT_AND_READING_INPUT_H__
#define OUTPUT_AND_READING_INPUT_H__

#include "data.h"

/// @brief where to read file name from
enum read_type_name
{
    manual,    ///< from standart input
    with_flags ///< after flag -f=
};

/**
 * \brief input coefficients for square solver from file
 * \param coeff_p - pointer to structure with coefficients for square equation
 * \param read_type - was file name written with flags or not
 * \param file name - file to read from
 */
bool file_input(struct coeffs * coeff_p, char file_name[]);

/**
 * \brief user-friendly read file name and open file with error handling
 * \param fp - pointer to file
 * \param file_name - variable for name of file
  */
bool read_file_name_and_open(FILE ** fp, char file_name[]);

/**
 * \brief read file name from cmd
 * \param file name - for reading name of file
 * \return true if file name read succesfully else false
 */
bool manual_read_file_name(char file_name[]);

/**
 * \brief open a file with perror in case of fail
 * \param file name - name of file to open
 * \param fp - pointer to pointer to file
 * \return true if opened succesfully else false
 */
bool open_file(char file_name[], FILE **fp);

/**
 * \brief input coefficients for square equation from cmd
 * \param coeff_p - pointer to structure with coefficients for square equation
 */
void std_input(struct coeffs * coeffs_p);

/**
 * \brief prints solutions for square equation
 * \param x1 - first root
 * \param x2 - second root
 * \param n_roots - number of roots
 */
void output_solutions(double x1, double x2, solver_outcome n_roots);

#endif //OUTPUT_AND_READING_INPUT_H__
