/**
 *  FILE            :   interpolationSearch.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-27
 *  DESCRIPTION     :   This is the implementation of a interpolation search.
 */
#include <stdio.h>

// Global string constants.
#define KPROMPT_FOR_LOOKUPNUMBER "Enter in a number to lookup: "

// Global numeric constants.
#define KNUMBERSLIMIT 10

// Function prototypes.
const int interpolationSearch(int ariNumbers[KNUMBERSLIMIT], int* piLookupNumber, int iLow, int iHigh);

int main(void)
{   
    // Declare the numbers to work with.
    int ariNumbers[KNUMBERSLIMIT] = { 0, 3, 6, 13, 19, 33, 56, 78, 89, 94 };

    int iNumberToLookup = 0;
    int iReturnValue = 0;

    do
    {   
        printf(KPROMPT_FOR_LOOKUPNUMBER);
        iReturnValue = fscanf(stdin, "%i", &iNumberToLookup);
        if (iReturnValue == 0) 
        { 
            fflush(stdin);
        }
    } while (iReturnValue == 0);

    // We have a number, passing in data to interpolation function.
    int iLowPoint = 0; int iHighPoint = KNUMBERSLIMIT - 1;
    if ((interpolationSearch(ariNumbers, &iNumberToLookup, iLowPoint, iHighPoint)) == 1)
    {
        printf("Not found !");
        return 0;
    }
    else 
    { 
        printf("Found");
    }
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   interpolationSearch
 *  DESCRIPTION     :   This function will perform the duties of
 *                      a interpolation search and will search for
 *                      the given number to lookup in the array.
 *  PARAMETERS      :   ariNumbers[KNUMBERSLIMIT], iLookupNumber, iLow, iHigh
 *  RETURNS         :   0, 1
 */
const int interpolationSearch(int ariNumbers[KNUMBERSLIMIT], int* piLookupNumber, int iLow, int iHigh)
{   
    int iPosition = 0;
    while (iLow <= iHigh)
    {   
        // Calculate the position.
        iPosition = iLow + ((*piLookupNumber - ariNumbers[iLow]) * (iHigh - iLow) / (ariNumbers[iHigh] - ariNumbers[iLow]));

        // Check the calculated position for a matching element.
        if (ariNumbers[iPosition] == *piLookupNumber) 
        { 
            return 0;
        }

        if (ariNumbers[iPosition] >= *piLookupNumber) 
        { 
            iHigh = iPosition - 1;
        }
        else 
        { 
            iLow = iPosition + 1;
        }
    }
    return 1;
}
