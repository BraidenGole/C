/**
 * @file quickSort.h
 * @author Braiden Gole
 * @brief This is where we will store our macro constants and our function
 *        prototypes.
 * @version 0.1
 * @date 2021-01-15
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _KQUICKSORT
#define _KQUICKSORT "quickSort.h"
#define KLIMIT 9
#define KONE 1
#define KZERO 0

#define KEXCHANGE(tmp, x, y) { tmp=x, x=y, y=tmp; }
#define PLUS +
#define MINUS -
#define INC ++
#define LESSTHAN <
#define LARGERTHAN >
#define ASSIGN =
#define PNTR *

// Function prototypes.
int part(int PNTR array, int start, const int end, int pivotIndex);
#endif