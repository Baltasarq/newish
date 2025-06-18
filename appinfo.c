// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#include "appinfo.h"


#include <stdio.h>


const char * APP_NAME = "newiSH";
const char * APP_VERSION = "0.1";
const char * APP_SERIAL = "20240801";


const char * get_app_banner()
{
    static char buffer[80] = "";

    if ( buffer[ 0 ] == 0 ) {
        sprintf( (char *) buffer, "%s v%s %s\n",
                        APP_NAME,
                        APP_VERSION,
                        APP_SERIAL );
    }

    return buffer;
}
