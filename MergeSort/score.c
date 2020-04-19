/**
 *  FILE            :   score.c 
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-18
 *  DESCRIPTION     :   This is the implementation of a merge sort
 *                      algorithm.
 */
#include <stdio.h>
#include <stdlib.h>

// Header file.
#include "scoreSort.h"

// Declare the scores to work with.
int ariScores[KSCOREROWS][KSCORECOLS] =
{
    { 99, 1, 15, 64, 54, 22, 10, 9 },
    { 66, 77, 12, 11, 20, 89, 0, 10 },
    { 10, 3, 32, 78, 45, 19, 93, 20 },
    { 76, 34, 22, 69, 33, 99, 25, 33 },
    { 44, 88, 40, 78, 44, 99, 22, 11 },
    { 9, 66, 32, 90, 12, 89, 48, 0 },
    { 77, 42, 22, 90, 94, 96, 12, 99 },
    { 40, 23, 55, 89, 44, 12, 40, 98 },
};

int main(void)
{   
    // Declare the two 1D halves to hold half of the scores.
    int* piHalf = NULL;
    int* piOther = NULL;

    piHalf = (int*)malloc(sizeof(int) * KSCORELIMIT);
    piOther = (int*)malloc(sizeof(int) * KSCORELIMIT);

    // Sanity check for system resources.
    if (piHalf == NULL) { return 1; }
    if (piOther == NULL) { return 1; }
    // End check, we have memory !

    // Partition the set of numbers into the 1D arrays.
    partitionScores(ariScores, piHalf, piOther);

    // Sort each half to then be merged.
    sortEachHalfOfScores(piHalf);
    sortEachHalfOfScores(piOther);

    // Merge the two sorted halves into the final set of scores.
    int* piFinalScores = NULL;
    piFinalScores = (int*)malloc(sizeof(int) * KSCORELIMIT);
    if (piFinalScores == NULL) { return 1; }
    else
    {   
        // We have memory for the final set of scores.
        mergeScores(piFinalScores, piHalf, piOther);
    }

    // Display the final set of sorted scores to the console.
    showAllScores(piFinalScores);
    
    // Free the system resources.
    free(piHalf);
    free(piOther);
    free(piFinalScores);
    return 0;
}