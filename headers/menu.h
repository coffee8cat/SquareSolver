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
 * \brief checks if programm started with flags or not
 * \param[in] argc - number of elements read from cmd
 */
bool is_standart_mode(const int argc);

/**
 * \brief choosing programm mode after incorrect file input
 * \details allows to choose between standart mode and file input
 * \return true if input mode chosen and false if quit chosen
 */
bool menu();

/**
 * \brief print menu options
 */
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

#endif // MENU_CHOOSING_MODE_H__
