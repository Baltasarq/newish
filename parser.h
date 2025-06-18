// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#ifndef PARSER_H
#define PARSER_H


#include "ctrl.h"


/** Parses the commands entered by the user.
  * @param input a pointer to the input.
  * @return A pointer to the control struct.
  */
const Ctrl * parse(char *input);


#endif
