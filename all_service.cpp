#include "all_service.h"
#include <stdio.h>

/**
 * \brief clean input buffer
 */
void clean_input_buff()
{
    while (getchar() != '\n')
        continue;
}
