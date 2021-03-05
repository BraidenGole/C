/**
 * @file recursiveFunctions.h
 * @author Braiden Gole
 * @brief This file is used to store more recursive functions.
 * @version 0.1
 * @date 2021-03-04
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef RECURSIVEFUNCTIONS 
#define RECURSIVEFUNCTIONS "recursiveFunctions.h"

#define K100BYTES 100
#define SIZEOFFILTER 10
#define ONE 1
#define ZERO 0
#define TWO 2
#define TEN 10
#define SWAP(tmp, x, y) { tmp=x, x=y y=tmp; }

#define __EQ__ ==
#define __NEQ__ !=
#define __LSS__ <
#define __LRG__ >
#define __LSSEQ__ <=

// Function prototypes.
void countDigits(long numberToBreak, int* numberOfDigits);
void filterNumbers(int array[], const int size, int iter);
void calculatePower(int* base, int exponent, int copy, int count);
#endif