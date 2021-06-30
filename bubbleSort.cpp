/**
 *  FILE            :   bubbleSort.cpp
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-02-23 - Update (2021-06-30)
 *  DESCRIPTION     :   This is the implementation of a multidimensional bubble sort.
 */
#include <stdio.h>

#define BUBBLEROWS 8
#define BUBBLECOLS 8
#define BUBBLETOTAL (BUBBLEROWS * BUBBLECOLS)

#define SWAP(tmp, x, y) { tmp=x, x=y, y=tmp; }

// Function prototypes.
void outputSortedSet(int multiDimensional[BUBBLEROWS][BUBBLECOLS]);

int main(void)
{   
    int array[BUBBLEROWS][BUBBLECOLS] = 
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

    int temp = 0;
    int sort = 0; 
    int rows = 0; 
    int cols = 0;

    while (sort < BUBBLETOTAL)
    {   
        rows = 0;
        while (rows < BUBBLEROWS)
        {   
            cols = 0;
            while (cols < BUBBLECOLS)
            {
                if (array[rows][cols] >= array[rows][cols + 1])
                {   
                    SWAP(temp, array[rows][cols], array[rows][cols + 1])
                }
                ++cols;
            }
            ++rows;
        }
        ++sort;
    }
    outputSortedSet(array);
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   outputSortedSet
 *  DESCRIPTION     :   This function will take in the multidimensional
 *                      array as input to then be displayed to the
 *                      console window.
 *  PARAMETERS      :   multiDimensional[BUBBLEROWS][BUBBLECOLS]
 *  RETURNS         :   None
 */
void outputSortedSet(int multiDimensional[BUBBLEROWS][BUBBLECOLS])
{   
    int breakAfterLimit = 0; 
    const int newLineLimit = 15;
    int unpackRows = 0; 
    int unpackColumns = 0;

    printf("===========================================================================\n");
    printf("  [ BUBBLE SORT ]\n\n   >>> Output \n\n\t");
    while (unpackRows < BUBBLEROWS)
    {   
        unpackColumns = 0;
        while (unpackColumns < BUBBLECOLS)
        {  
            printf("%i ", multiDimensional[unpackRows][unpackColumns]);
            if (breakAfterLimit == newLineLimit)
            { 
                breakAfterLimit = 0;
                printf("\n\t");
            }
            ++breakAfterLimit;
            ++unpackColumns;
        }
        ++unpackRows;
    }
    printf("\n===========================================================================\n");
}
