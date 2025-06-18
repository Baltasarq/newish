// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#include "parser.h"
#include "io.h"

#include <string.h>


static const char * spaces = " \t\r\n";


char * skip_spaces(const char *s)
{
    char * p = (char *) s;

    while ( strchr( spaces, *s ) != NULL ) {
        ++p;
    }

    return p;
}

const Ctrl * parse(char *input)
{
    Ctrl * ctrl = get_ctrl();
    char * p = skip_spaces( input );
    char * p2 = p;
    char ** args = ctrl->args;

    --args;

    // Read command's main part
    while( *p != '\0'
        && *p2 != '\0'
        && strchr( spaces, *p2 ) == NULL )
    {
        p2++;
    }

    // First argument
    while ( *p2 != '\0') {
        *p2 = '\0';
        p = p2 + 1;
        ctrl->num_args += 1;
        *(++args) = p;

        p = p2 = skip_spaces( input );

        // Read command's main part
        while( *p != '\0'
            && *p2 != '\0'
            && strchr( spaces, *p2 ) == NULL )
        {
            p2++;
        }
    }

    return ctrl;
}
