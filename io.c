// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#include "io.h"
#include "ctrl.h"

#include <stdio.h>
#include <string.h>


const char * input()
{
    Ctrl * ctrl = get_ctrl();

    fgets( ctrl->cmd, MAX_INPUT_BUFFER - 1, ctrl->in );

    ctrl->cmd[ strcspn( ctrl->cmd, "\r\n" ) ] = '\0';
    return ctrl->cmd;
}

void output(const char * buffer)
{
    output_padded( buffer, 0 );
}

void output_padded(const char * buffer, int column_size)
{
    static char str_col_size[80];
    Ctrl * ctrl = get_ctrl();

    if ( column_size > 0 ) {
        sprintf( str_col_size, "%%-%ds", column_size );
    } else {
        strcpy( str_col_size, "%s" );
    }

    fprintf( ctrl->out, str_col_size, buffer );
}

void output_char(char ch)
{
    Ctrl * ctrl = get_ctrl();

    fprintf( ctrl->out, "%c", ch );
}

void output_size(size_t sz)
{
    Ctrl * ctrl = get_ctrl();

    fprintf( ctrl->out, "%8u", sz );
}

void output_int(int x)
{
    Ctrl * ctrl = get_ctrl();

    fprintf( ctrl->out, "%8d", x );
}

void show_prompt()
{
    Ctrl * ctrl = get_ctrl();

    output_char( '\n' );
    output( ctrl->cwd );
    output_char( '\n' );
    output( ctrl->prompt );
}
