/**
 *  FILE            :   quickSort.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-21
 *  DESCRIPTION     :   This is the implementation of a quick sort algorithm.
 */
#include <stdio.h>

// Global numeric constants.
#define KNUMBERLIMIT 10
#define KHALFOFNUMERS (KNUMBERLIMIT / 2)
#define KmwpSORT(tmp, x, y) { tmp=x, x=y, y=tmp; }

// Function prototypes.
int iPivotPlacement(int ariNumbers[KNUMBERLIMIT], int* piCenter);
void quickSort(int ariSort[KNUMBERLIMIT], int* piPivotIndex);
void displayNumbers(int ariSortedNumbers[KNUMBERLIMIT]);

int main(void)
{
    // Declare the set of numbers to sort.
    int ariNumbers[KNUMBERLIMIT] = { 1, 5, 9, 4, 7, 3, 8, 2, 6, 9 };

    // Declare the pivot element, in this case it will be the number in the center.
    int* piCenter = (int*)(&ariNumbers[KHALFOFNUMERS - 1]);

    // Place the pivot into the correct position by partitioning the numbers.
    int iPivotPosition = 0;
    iPivotPosition = iPivotPlacement(ariNumbers, piCenter);
    
    printf("\n\tPivot Index: [%i]\n", iPivotPosition);
    printf("\tPivot Element: [%i]\n\n", ariNumbers[iPivotPosition]);

    // Sort the remaining elements on each side.
    quickSort(ariNumbers, &iPivotPosition);

    // Display the sorted numbers to the user.
    displayNumbers(ariNumbers);
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   iPivotPlacement
 *  DESCRIPTION     :   This function will take in the set of items to
 *                      partition off of and the partition element which
 *                      happens to be the center element.
 *  PARAMETERS      :   ariNumbers[KNUMBERLIMIT], piCenter
 *  RETURNS         :   iLeftSide
 */
int iPivotPlacement(int ariNumbers[KNUMBERLIMIT], int* piCenter)
{
    int iAllNumbers = 0; 
    int iLeftSide = 0; int iRightSide = KNUMBERLIMIT - 1; int iTemp = 0;
    for (iAllNumbers; iAllNumbers < KNUMBERLIMIT; iAllNumbers++)
    {   
        // Is the current number (less than) the pivot ? If so ++inc.
        if (ariNumbers[iLeftSide] <= *piCenter) { ++iLeftSide; }

        // Is the current number (larger than) the pivot ? If so --dec.
        if (ariNumbers[iRightSide] > *piCenter) { --iRightSide; }

        // Perform a check to make sure we are in valid length.
        if (iLeftSide < iRightSide)
        {
            KmwpSORT(iTemp, ariNumbers[iLeftSide], 
            ariNumbers[iRightSide]);
        }
    }
    KmwpSORT(iTemp, ariNumbers[iLeftSide + 1], ariNumbers[iLeftSide]);
    return iLeftSide;
}

/**     -- Function header comment
 *  FUNCTION        :   quickSort
 *  DESCRIPTION     :   This function will take the elements to sort as
 *                      well as the index at which the pivot element sits
 *                      in the array.
 *  PARAMETERS      :   ariSort[KNUMBERLIMIT], piPivotIndex
 *  RETURNS         :   None
 */
void quickSort(int ariSort[KNUMBERLIMIT], int* piPivotIndex)
{
    int iTempNumber = 0;
    int iSortUntilComplete = 0;
    int iLeftSide = 0; int iPreviousNumber = 1;
    int iRightSide = *piPivotIndex + 1; int iNumberBefore = 0;

    // This loop allows for enough cycles to completely sort both sides
    // of the set of numbers to sort, sorting each "side" one at a time.
    while (iSortUntilComplete < KNUMBERLIMIT)
    {   
        /*
            Sort the left side of the set of numbers up until the
            pivot elements position after the initial placement.
        */
        iLeftSide = 0;
        while (iLeftSide <= *piPivotIndex)
        {   
            if (ariSort[iLeftSide] >= ariSort[iLeftSide + 1])
            {
                KmwpSORT(iTempNumber, ariSort[iLeftSide],
                ariSort[iLeftSide + 1]);
            }
            ++iLeftSide;
        }
        
        /*
            Start sorting the right side separately by starting a loop
            just after the pivot elements position after it has been originally placed.
        */
        iRightSide = *piPivotIndex + 1;
        while (iRightSide < KNUMBERLIMIT)
        {   
            if (ariSort[iRightSide] >= ariSort[iRightSide + 1])
            {
                KmwpSORT(iTempNumber, ariSort[iRightSide],
                ariSort[iRightSide + 1]);
            }
            ++iRightSide;
        }
        ++iSortUntilComplete;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   displayNumbers
 *  DESCRIPTION     :   This function will take in the set of sorted
 *                      numbers and it will display them to the console
 *                      window.
 *  PARAMETERS      :   ariSortedNumber[KNUMBERLIMIT]
 *  RETURNS         :   None
 */
void displayNumbers(int ariSortedNumbers[KNUMBERLIMIT])
{
    int iNumbers = 0;
    for (iNumbers; iNumbers < KNUMBERLIMIT; iNumbers++)
    {
        printf("%i ", ariSortedNumbers[iNumbers]);
    }
}