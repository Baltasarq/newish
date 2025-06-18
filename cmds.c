// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#include "cmds.h"
#include "io.h"
#include "ctrl.h"
#include "atr.h"
#include "error.h"
#include "util.h"

#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


const char * ID[] = {
    "cat",
    "exit",
    "pwd",
    "cd",
    "help",
    NULL
};

void (*CMD[])() = {
    cat,
    exit_shell,
    pwd,
    cd,
    help,
    NULL
};

const char * HELP[] = {
    "cat      - Returns the catalogue of the current directory.",
    "exit     - Finishes this session.",
    "pwd      - Prints the current working directory.",
    "cd       - Changes directory,",
    NULL
};


// Exit the shell
void exit_shell()
{
    Ctrl * ctrl = get_ctrl();
    ctrl->should_exit = true;
}

// Show the directory
void cat()
{
    Ctrl * ctrl = get_ctrl();
    DIR * dir = opendir( ctrl->cwd );

    if ( dir != NULL ) {
        struct dirent * dir_entry = readdir( dir );
        while ( dir_entry != NULL ) {
            if ( strcmp( ".", dir_entry->d_name ) != 0
              && strcmp( "..", dir_entry->d_name ) != 0 )
            {
                const Atr * atr = get_atr_for( dir_entry->d_name );

                output_padded(
                    usr_file_name_from_sys_file_name( dir_entry->d_name ), 20 );
                output_char( '\t' );

                output_char( get_mark_for( atr ) );
                output_char( '\t' );

                output_size( atr->size );
                output_char( '\t' );

                output( str_from_time( atr->mdf_time ) );
                output_char( '\n' );
            }

            dir_entry = readdir( dir );
        }
    } else {
        output( fmt_error( Error, "accesing directory: '" ));
        output( ctrl->cwd );
        output_char( '\'' );
        output_char( '\n' );
    }

    closedir( dir );
}

void pwd()
{
    Ctrl * ctrl = get_ctrl();

    output( ctrl->cwd );
    output( "\n" );
}

void cd()
{
    Ctrl * ctrl = get_ctrl();

    if ( ctrl->num_args == 1 ) {

    } else {
        output( "Usage: cd <dir>.\n" );
        output( fmt_error( Error,
                            "Invalid number of arguments.\n" ));
        output( fmt_explanation(
                            "Are you missing the directory to change to?\n" ));
    }

    return;
}

void help()
{
    output( "Available commands:\n" );

    for(const char ** help_str = HELP; *help_str != NULL; ++help_str) {
        output( *help_str );
        output( "\n" );
    }

    output( "\n" );
}

bool try_execute(const char *cmd_id)
{
    const char ** id = ID;
    bool toret = false;

    while( *id != NULL ) {
        if ( strcmp( cmd_id, *id ) == 0 ) {
            CMD[ id - ID ]();
            toret = true;
            break;
        }

        ++id;
    }

    return toret;
}

