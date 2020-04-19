/**
 *  FILE            :   binarySearch.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-19
 *  DESCRIPTION     :   This is the implementation of a binary search
 *                      algorithm.
 */
#include <stdio.h>

// Global string constants.
#define KPROMPT_FOR_SEARCHNUMBER "Enter in a positive number to search: "

// Global numeric constants.
#define KDATAPOOLROWS 8
#define KDATAPOOLCOLS 8
#define KHALFDATAPOOLROWS (KDATAPOOLROWS / 2)
#define KHALFDATAPOOLCOLS (KDATAPOOLCOLS / 2)

// Declare the set to search from.
const int ariDataPool[KDATAPOOLROWS][KDATAPOOLCOLS] =
{
    { 192, 200, 205, 208, 230, 221, 222, 225 },
    { 240, 244, 245, 251, 255, 260, 279, 282 },
    { 303, 310, 311, 320, 321, 324, 328, 333 },
    { 360, 361, 389, 402, 420, 490, 501, 520 },
    { 550, 559, 562, 589, 592, 599, 600, 654 },
    { 675, 678, 688, 698, 704, 710, 711, 718 },
    { 756, 777, 789, 790, 795, 798, 801, 802 },
    { 850, 860, 870, 876, 881, 885, 901, 1000 },
};

// Function prototypes.
const int iBinarySearch(int iValueToSearch, int* piRow, int* piCol);

int main(void)
{
    // Create a variable to hold the value of the number to search.
    int iNumberToSearch = 0;

    int iFoundRowPosition = 0;
    int iFoundColPosition = 0;
    int iReturnValue = 0;

    do
    {
        printf(KPROMPT_FOR_SEARCHNUMBER);
        if ((fscanf(stdin, "%i", &iNumberToSearch)) == 0) { fflush(stdin); }

        // Pass the numbered entered by the user to the binary search function.
        iReturnValue = iBinarySearch(iNumberToSearch, &iFoundRowPosition,
        &iFoundColPosition);

        // If we have a return value __eq__ to 1 then the number was not found.
        if (iReturnValue == 1)
        { 
            printf("\n-- NOT FOUND --\n");
            iNumberToSearch = 0;
        }
    } while (iReturnValue != 0);

    // Output the 2D position at which that found number sits.
    printf("\nFound at (arr[%i][%i])", iFoundRowPosition,
    iFoundColPosition);
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   iBinarySearch
 *  DESCRIPTION     :   This function will take in the value to search
 *                      and will filter the numbers to search by comparing
 *                      both ends of the center value.
 *  PARAMETERS      :   iValueToSearch, piRow, piCol
 *  RETURNS         :   0, 1
 */
const int iBinarySearch(int iValueToSearch, int* piRow, int* piCol)
{   
    int iSearchRows = 0;
    int iSearchCols = 0;

    int* iCenter = (int*)(&ariDataPool[KHALFDATAPOOLROWS][KHALFDATAPOOLCOLS]);

    // Cycle through the rows and columns to search each number for the value to search.
    for (iSearchRows; iSearchRows < KDATAPOOLROWS; iSearchRows++)
    {
        for (iSearchCols = 0; iSearchCols < KDATAPOOLCOLS; iSearchCols++)
        {   
            // Compare the center value to the numbers being cycled over.
            if (ariDataPool[iSearchRows][iSearchCols] < *iCenter)
            {
                if (ariDataPool[iSearchRows][iSearchCols] == iValueToSearch)
                {   
                    // Pass the position of the row and column to the parameters.
                    *piRow = iSearchRows;
                    *piCol = iSearchCols;
                    return 0;
                }
            }
            else
            {
                if (ariDataPool[iSearchRows][iSearchCols] == iValueToSearch)
                {   
                    // Pass the position of the row and column to the parameters.
                    *piRow = iSearchRows;
                    *piCol = iSearchCols;
                    return 0;
                }
            }
        }
    }
    return 1;
}