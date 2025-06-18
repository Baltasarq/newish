// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#ifndef CTRL_H
#define CTRL_H

#include <stdio.h>
#include <stdbool.h>

#include "io.h"


#define MAX_CWD_BUFFER 8191
#define MAX_CMD_ARGS 100


/** Stores the current configuration of the shell. */
typedef struct _ctrl {
    FILE * in;
    FILE * out;
    char prompt[MAX_CWD_BUFFER + 1];
    bool should_exit;
    unsigned char num_args;
    char cwd[MAX_CWD_BUFFER + 1];
    char cmd[MAX_INPUT_BUFFER + 1];
    char * args[MAX_CMD_ARGS];
} Ctrl;


/** @return Creates and returns the config struct. */
Ctrl * create_ctrl();

/** @return Returns the config struct. */
Ctrl * get_ctrl();


#endif
