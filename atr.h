// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#ifndef ATR_H
#define ATR_H


#include <stdbool.h>
#include <time.h>


typedef struct _atr {
    size_t size;
    const char * name;
    bool is_dir;
    bool is_link;
    time_t mdf_time;
} Atr;


/** @return the attributes for file of name fn. */
const Atr * get_atr_for(const char *fn);

/** @return a char "mark" for a given file. */
const char get_mark_for(const Atr *);

/** @return an ISO-formatted string with local time. */
const char * str_from_time(time_t);


#endif
