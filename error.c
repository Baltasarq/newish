// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#include "error.h"

#include <stdlib.h>
#include <stdio.h>


#define MAX_ERROR_BUFFER 8191
#define MAX_ERROR_LEVEL_BUFFER 6

static char ErrorBuffer[MAX_ERROR_BUFFER + 1];

// Labels "[ERR] " are of length 6.
static const char SpacesErrorLevelLength[] = "      ";

const char * StrErrorLevel[] = {
    "NFO",
    "DBG",
    "WRN",
    "ERR"
};

char StrErrorLevelBuffer[] = "      ";


void panic(Panic panic, const char * msg_error)
{
    printf( fmt_error( Error, msg_error ), stderr );
    exit( panic );
}

const char * fmt_error_level(ErrorLevel level)
{
    snprintf( StrErrorLevelBuffer,
              MAX_ERROR_LEVEL_BUFFER,
              "[%s] ",
              StrErrorLevel[ level ] );

    return StrErrorLevelBuffer;
}

const char * fmt_error(ErrorLevel level, const char * msg_error)
{
    snprintf( ErrorBuffer,
              MAX_ERROR_BUFFER,
              "%s%s",
              fmt_error_level( level ),
              msg_error );

    return ErrorBuffer;
}

const char * fmt_explanation(const char * msg_error)
{
    snprintf( ErrorBuffer,
              MAX_ERROR_BUFFER,
              "%s%s",
              SpacesErrorLevelLength,
              msg_error );

    return ErrorBuffer;
}
