#include <TXLib.h>

#include "data.h"
#include "menu.h"
#include "flags.h"

int main(const int argc, char * const argv[])
{
    flags_init flags_values = {false, false, false, ""};

    welcome();

    check_flags(&flags_values, argc, argv);

    if(is_standart_mode(argc))
    {
        standart_mode();
    }
    else
    {
        if(flags_values.is_help)
        {
            help();
        }
        if(flags_values.is_unit_testing)
        {
            start_unit_testing();
        }
        if(flags_values.is_file_input)
        {
            execute_file_reading(&flags_values);
        }
    }
}
