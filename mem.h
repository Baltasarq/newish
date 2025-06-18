// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#ifndef MEM_H
#define MEM_H


#include <stddef.h>


/** Allocates memory.
  * Immediately fails if no memory is available.
  * @param numBytes the number of bytes to allocate.
  * @return A pointer to the new memory.
  */
void * alloc_mem(size_t numBytes);


/* Liberates memory previously allocated.
 * @param p a pointer to a pointer to the allocated memory.
 */
void free_mem(void **p);


/** Copies a string into another one in the heap.
  * @param s a string.
  * @return a pointer to the copy
  */
char *copy_str(const char *s);


#endif
