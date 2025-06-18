// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "atr.h"


static Atr atr;
static struct stat stats;


const char DIR_MARK = 'd';
const char FILE_MARK = 'f';
const char LINK_MARK = 'l';

const int EPOCH = 1900;         // Supposed to be 1970 ??


const char get_mark_for(const Atr * atr)
{
    char toret = FILE_MARK;
    
    if ( atr->is_link ) {
        toret = LINK_MARK;
    }
    else
    if ( atr->is_dir ) {
        toret = DIR_MARK;
    }
     
    return toret;
}



void setNulAtr(const char *fn)
{
    memset( &atr, 0, sizeof( atr ) );
    atr.name = fn;
}

const Atr * get_atr_for(const char *fn)
{
    if ( stat( fn, &stats ) != 0 ) {
        setNulAtr( fn );
    } else {
        atr.name = fn;
        atr.size = stats.st_size;
        
        // File type
        if ( stats.st_mode & S_IFREG ) {
            atr.is_dir = atr.is_link = false;
        } else {
            atr.is_dir = stats.st_mode & S_IFDIR;
            atr.is_link = stats.st_mode & S_IFLNK;
        }
        
        atr.mdf_time = stats.st_mtime;
    }
    
    return &atr;
}

const char * str_from_time(time_t t)
{
    static char buffer[ 80 ];
    struct tm * loctm = localtime( &t );
    
    sprintf( buffer, "%04d-%02d-%02d %02d:%02d:%02d",
                        EPOCH + loctm->tm_year,
                        loctm->tm_mon + 1,
                        loctm->tm_mday,
                        loctm->tm_hour,
                        loctm->tm_min,
                        loctm->tm_sec );
                        
    return buffer;
}
