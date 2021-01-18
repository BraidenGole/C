/**
 * @file exponentialSearch.c
 * @author Braiden Gole
 * @brief This is a exponential search algorithm.
 * @version 0.1
 * @date 2021-01-17
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _KEXPONENTIALSEARCH
#define _KEXPONENTIALSEARCH "exponentialSearch.h"

#define __NEQ__ !=
#define __EQ__ ==
#define __LSS__ <
#define __LSS_EQ__ <=
#define __LRGR_EQ__ >=
#define __LRGR__ >
#define __PLUS__ +
#define __MULTI__ *
#define __MINUS__ -
#define __DIV__ /
#define NOT !
#define AND &&

// RECURPOW() must be used in a loop //
#define TWO 2
#define RECURPOW(x) { x = x __MULTI__ TWO; }
#define MIN(x, y) (((x) < (y) ? (x) : (y)))

// Added protection against your input formats.
#define _INT_FORMAT "%i"
#define _CHAR_FORMAT "%c"

#define SEARCHLIMIT 14
#define SEARCH
#define ZERO 0
#define ONE 1

#define KNOCHARS "\n\t[ No characters ! Only numbers. ]\n\n"
#define KENTERINVALUE "\n\tEnter a value to search for: "
#define KFOUND "\n\t[Found !]\n"
#define KNOTFOUND "\n\t[Not Found !]\n"

// Function prototypes.
const bool binarySearch(int* data, int iter, int size, const int searchTerm);
void generatePowIndex(int* data, const int max, const int value, int* result);
void show(int* data, const int size);
#endif