// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#ifndef CMDS_H
#define CMDS_H


#include <stdio.h>
#include <stdbool.h>


extern const char * ID[];
extern void (*CMD[])();


/** Tries to find the command and executes it, if exists.
  *  @return true if found and executed, false otherwise.
  */
bool try_execute(const char *);

/** Exits the shell. */
void exit_shell();

/** Outputs the files in the current directory. */
void cat();

/** Outputs the current working directory. */
void pwd();

/** Changes the current working directory. */
void cd();

/** Shows help. */
void help();


#endif
