/**
 * @file radixSort.h
 * @author Braiden Gole
 * @brief 
 * @version 0.1
 * @date 2021-03-07
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef RADIXSORT
#define RADIXSORT "radixSort.h"

#define TEN 10
#define ZERO 0
#define ONE 1
#define NEGATIVEONE -1

#define __LSS__ <
#define __LRGEQ__ >=
#define __LRG__ >
#define __NEQ__ !=
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

// Function header comment
const int retrieveMaximum(int* array, const int size);
int* countingSort(int* array, const int size, int digitPlace);
#endif