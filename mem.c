// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#include "mem.h"
#include "error.h"

#include <stdlib.h>
#include <string.h>


void * alloc_mem(size_t numBytes)
{
    void * mem = malloc( numBytes );

    if ( mem == NULL ) {
        panic( PANIC_NOT_ENOUGH_MEMORY, "allocating memory" );
    }

    return mem;
}

void free_mem(void **p)
{
    free( *p );
    *p = NULL;
}

char *copy_str(const char *s)
{
    char * toret = strdup( s );

    if ( toret == NULL ) {
        panic( PANIC_NOT_ENOUGH_MEMORY, "copying string" );
    }

    return toret;
}
