/**
 * @file quickSort.h
 * @author Braiden Gole
 * @brief 
 * @version 0.1
 * @date 2021-01-10
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _KQUICKSORT
#define _KQUICKSORT "quickSort.h"

#define KEXCHANGE(tmp, x, y) { tmp=x, x=y, y=tmp; }
#define KLIMIT 9

// Function prototypes.
int part(int* array, int start, int end);
void output(int* array, const int size);
#endif