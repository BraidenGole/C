/**
 * @file pigeonHoleSort.h
 * @author Braiden Gole
 * @brief This is the header file that will contain our prototyped
 *        functions and declared macro definitions.
 * @version 0.1
 * @date 2021-01-12
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _KPIGEONHOLESORT
#define _KPIGEONHOLESORT "pigeonHoleSort.h"

#define KSIZE 9
#define KONE 1
#define KZERO 0

// Function prototypes.
int findSmallest(int* array, const int size);
int findLargest(int* array, const int size);
const int findRange(int max, int min);
void initializePigeonHoles(int* holes, const int size);
void fillPigeonHoles(int* array, int* pHoles, int min, const int range);
void showAllHoles(int* array, const int size);
#endif