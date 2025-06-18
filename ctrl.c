// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#include "ctrl.h"

#include <unistd.h>
#include <string.h>
#include <stdbool.h>


static Ctrl ctrl;
static const char * DEFAULT_PROMPT = "~: ";


Ctrl * create_ctrl()
{
    ctrl.in = stdin;
    ctrl.out = stdout;
    ctrl.should_exit = false;

    strcpy( ctrl.prompt, DEFAULT_PROMPT );

    if ( getcwd( ctrl.cwd, MAX_CWD_BUFFER ) == NULL ) {
        ctrl.cwd[ 0 ] = '.';
        ctrl.cwd[ 1 ] = '\0';
    }

    ctrl.should_exit = false;
    *ctrl.cmd = '\0';

    memset( ctrl.args, sizeof( ctrl.args ), 0 );
    return &ctrl;
}


Ctrl * get_ctrl()
{
    return &ctrl;
}
