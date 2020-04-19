/**
 *  FILE            :   scoreSort.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-18
 *  DESCRIPTION     :   This is where we will hold all functions associated
 *                      with a merge sort algorithm.
 */
#include <stdio.h>
#include <stdlib.h>

// Header file.
#include "scoreSort.h"

/**     -- Function header comment
 *  FUNCTION        :   partitionScores
 *  DESCRIPTION     :   This function will take in the scores to
 *                      part and will partition the set of scores
 *                      in each half.
 *  PARAMETERS      :   ariScores[KSCOREROWS][KSCORECOLS],
 *                      piHalf, piOther
 *  RETURNS         :   None
 */
void partitionScores(int ariScores[KSCOREROWS][KSCORECOLS],
int* piHalf, int* piOther)
{   
    int iPartRows = 0;
    int iPartCols = 0;

    // Separate counters to insert the numbers into the 1D temp arrays.
    int iHalfNumbers = 0;
    int iOtherNumbers = 0;

    // Cycle through the multidimensional array to get a copy of the values.
    for (iPartRows; iPartRows < KSCOREROWS; iPartRows++)
    {
        for (iPartCols = 0; iPartCols < KSCORECOLS; iPartCols++)
        {
            // Filter the rows to collect only half of the scores.
            if (iPartRows < KHALFOFSCOREROWS)
            {
                piHalf[iHalfNumbers] = ariScores[iPartRows][iPartCols];
                ++iHalfNumbers;
            }
            else
            {
                piOther[iOtherNumbers] = ariScores[iPartRows][iPartCols];
                ++iOtherNumbers;
            }
        }
    }
}

/**     -- Function header comment
 *  FUNCTION        :   sortEachHalfOfScores
 *  DESCRIPTION     :   This function will take in half of the
 *                      total set of scores to sort from and will
 *                      sort half the scores, which means 2 calls to this
 *                      function is required in order to sort an entire set
 *                      of numbers to be merged.
 *  PARAMETERS      :   piHalf 
 *  RETURNS         :   None
 */
void sortEachHalfOfScores(int* piHalf)
{
    int iSortScores = 0;
    int iScores = 0;

    int iTemp = 0;
    for (iSortScores; iSortScores < KHALFOFSCORELIMIT; iSortScores++)
    {   
        for (iScores = 0; iScores < KHALFOFSCORELIMIT; iScores++)
        {
            if (piHalf[iScores] >= piHalf[iScores + 1])
            {
                KmwpSORT(iTemp, piHalf[iScores], piHalf[iScores + 1]);
            }
        }
    }
}

/**     -- Function header comment
 *  FUNCTION        :   mergeScores
 *  DESCRIPTION     :   This function takes in both sorted halves
 *                      of the entire set of scores and merges the halves
 *                      to the final set of scores to display.
 *  PARAMETERS      :   piFinalScores, piHalf, piOther
 *  RETURNS         :   None
 */
void mergeScores(int* piFinalScores, int* piHalf, int* piOther)
{   
    int iMergedScores = 0;
    int iHalfOfScores = 0;
    int iOtherScores = 0;

    // Cycle through both halves use separate iters variables for each.
    while (iHalfOfScores < KHALFOFSCORELIMIT && iOtherScores < KSCORELIMIT)
    {   
        if (piHalf[iHalfOfScores] < piOther[iOtherScores])
        {
            piFinalScores[iMergedScores] = piHalf[iHalfOfScores];
            ++iHalfOfScores;
        }
        else
        {
            piFinalScores[iMergedScores] = piOther[iOtherScores];
            ++iOtherScores;
        }
        ++iMergedScores;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   showAllScores
 *  DESCRIPTION     :   This function will take in the final set
 *                      of scores to be displayed to the console window
 *                      and will unpack the values in the set.
 *  PARAMETERS      :   piFinalSet
 *  RETURNS         :   None
 */
void showAllScores(int* piFinalSet)
{   
    printf("\n  -- Numbers --  \n\n\t");
    int iUnpackNumbers = 0; int iLineBreak = 0;
    while (iUnpackNumbers < KSCORELIMIT)
    {   
        // Perform a line break after a count of 10.
        if (iLineBreak == 10)
        {   
            iLineBreak = 0;
            printf("\n\t"); 
        }
        else { printf("%i ", piFinalSet[iUnpackNumbers]); }
        ++iLineBreak;
        ++iUnpackNumbers;
    }
    printf("\n");
}