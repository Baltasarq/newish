// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *sys_file_name_from_usr_file_name(char *usr_file_name)
{
    for(char * ptr = usr_file_name; *ptr != '\0'; ++ptr) {
        if ( *ptr == ' ' ) {
            *ptr = '_';
        }
    }

    return usr_file_name;
}

char *usr_file_name_from_sys_file_name(char *sys_file_name)
{
    for(char * ptr = sys_file_name; *ptr != '\0'; ++ptr) {
        if ( *ptr == '_' ) {
            *ptr = ' ';
        }
    }

    return sys_file_name;
}
