/*
    FILE            :   bubble.cpp
    PROJECT         :   None
    PROGRAMMER      :   Braiden Gole
    FIRST VERSION   :   2020-02-23
    DESCRIPTION     :   This is the implementation of a multidimensional bubble sort.
*/
#include <stdio.h>

#define KBUBBLE_ROWS 8
#define KBUBBLE_COLS 8
#define KBUBBLE_TOTAL (KBUBBLE_ROWS * KBUBBLE_COLS)

// [ Efficient swap macro ]
#define KEFFICIENT_SWAP(tmp, x, y) { tmp=x, x=y, y=tmp; }

// Function prototypes.
void outputSortedSet(int ariMultiDimensional[KBUBBLE_ROWS][KBUBBLE_COLS]);

int main(void)
{   
    // Declare an array to sort.
    int ariBubbleSort[KBUBBLE_ROWS][KBUBBLE_COLS] = 
    {
        { 3, 4, 54, 32, 87, 1, 5, 7 },
        { 2, 4, 43, 12, 90, 56, 34, 29 },
        { 100, 300, 200, 110, 101, 111, 13, 14 },
        { 61, 54, 21, 98, 45, 33, 222, 15 },
        { 301, 205, 255, 150, 189, 223, 14, 444 },
        { 121, 141, 151, 161, 76, 43, 23, 0 },
        { 245, 234, 345, 344, 322, 321, 212, 2 },
        { 100, 200, 400, 600, 200, 111, 200, 1000 },
    };

    int iTemp = 0;
    int iSortUntilComplete = 0; int iBubbleRows = 0; int iBubbleCols = 0;
    while (iSortUntilComplete < KBUBBLE_TOTAL)
    {   
        iBubbleRows = 0;
        while (iBubbleRows < KBUBBLE_ROWS)
        {   
            iBubbleCols = 0;
            while (iBubbleCols < KBUBBLE_COLS)
            {
                if (ariBubbleSort[iBubbleRows][iBubbleCols] >=
                 ariBubbleSort[iBubbleRows][iBubbleCols + 1])
                {   
                    // Call to a macro with parameters.
                    KEFFICIENT_SWAP(iTemp, ariBubbleSort[iBubbleRows][iBubbleCols],
                    ariBubbleSort[iBubbleRows][iBubbleCols + 1])
                }
                ++iBubbleCols;
            }
            ++iBubbleRows;
        }
        ++iSortUntilComplete;
    }

    // Output the contents to the console window.
    outputSortedSet(ariBubbleSort);
    return 0;
}

/*
    FUNCTION        :   outputSortedSet
    DESCRIPTION     :   This function will take in the multidimensional array
                        as input to then be outputed to the console window.
    PARAMETERS      :   int ariMultiDimensional[KBUBBLE_ROWS][KBUBBLE_COLS]
    RETURNS         :   None
*/
void outputSortedSet(int ariMultiDimensional[KBUBBLE_ROWS][KBUBBLE_COLS])
{   
    int iBreakAfterLimit = 0; const int kNewLineLimit = 15;
    int iUnpackRows = 0; int iUnpackColumns = 0;

    printf("===========================================================================\n");
    printf("  [ BUBBLE SORT ]\n\n   >>> Output \n\n\t");
    while (iUnpackRows < KBUBBLE_ROWS)
    {   
        iUnpackColumns = 0;
        while (iUnpackColumns < KBUBBLE_COLS)
        {  
            printf("%i ", ariMultiDimensional[iUnpackRows][iUnpackColumns]);
            if (iBreakAfterLimit == kNewLineLimit)
            { 
                iBreakAfterLimit = 0;
                printf("\n\t");
            }
            ++iBreakAfterLimit;
            ++iUnpackColumns;
        }
        ++iUnpackRows;
    }
    printf("\n===========================================================================\n");
}