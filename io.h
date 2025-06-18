// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#ifndef IO_H
#define IO_H


#include <stdio.h>
#include <stdlib.h>


#define MAX_INPUT_BUFFER 8192


/** @return a pointer to an internal buffer with the user's input. */
const char * input();

/** Shows the prompt on cfg->out. */
void show_prompt();

/** Shows a string on cfg->out. */
void output(const char *);

/** Shows a padded string on cfg->out.
  * @param column_size 0 if you don't want a postfix of spaces
  *                      to complete a column size, a natural otherwise.
  */
void output_padded(const char *, int column_size);

/** Shows a char on cfg->out. */
void output_char(char);

/** Shows a size (a kind of unsigned integer) on cfg->out. */
void output_size(size_t);

/** Shows an int on cfg->out. */
void output_int(int);


#endif
