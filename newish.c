// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#include "appinfo.h"
#include "cmds.h"
#include "ctrl.h"
#include "parser.h"


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv)
{
    Ctrl * ctrl = create_ctrl();

    output( get_app_banner() );

    do {
        show_prompt();
        const char * INPUT = input();

        parse( INPUT );

        if ( !try_execute( ctrl->cmd ) ) {
            output( "ERROR command not found.\n" );
        }
    } while( !ctrl->should_exit );

    return EXIT_SUCCESS;
}
