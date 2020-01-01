/*
    FILE            :   multiDimensionalBubbleSort.cpp
    PROJECT         :   None
    PROGRAMMER      :   Braiden Gole
    FIRST VERSION   :   2020-01-01
    DESCRIPTION     :   This program demonstrates the use of multidimensional arrays
                        while integrating the algorithm bubble sort.
*/
#include <stdio.h>

#define KMULTIROWLIMIT 8
#define KMULTICOLUMNLIMIT 8
#define KTOTALMULTISIZE (KMULTIROWLIMIT * KMULTICOLUMNLIMIT)

int main(void)
{
    int multiDiamensional[KMULTIROWLIMIT][KMULTICOLUMNLIMIT] = 
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

    // Sort the two dimensional array.
    short sortUntilFinished = 0; short rows = 0; short columns = 0; short tempLocation = 0;
    for (sortUntilFinished; sortUntilFinished < KTOTALMULTISIZE; ++sortUntilFinished)
    {
        for (rows = 0; rows < KMULTIROWLIMIT; ++rows)
        {
            for (columns = 0; columns < KMULTICOLUMNLIMIT; ++columns)
            {
                if (multiDiamensional[rows][columns] > multiDiamensional[rows][columns + 1])
                {
                    tempLocation = multiDiamensional[rows][columns];
                    multiDiamensional[rows][columns] = multiDiamensional[rows][columns + 1];
                    multiDiamensional[rows][columns + 1] = tempLocation;
                }
            }
        }
    }

    // Display the 2D array.
    short sortedRows = 0; short sortedColumns = 0;
    while (sortedRows < KMULTIROWLIMIT)
    {   
        sortedColumns = 0;
        while (sortedColumns < KMULTICOLUMNLIMIT)
        {
            printf("%i ", multiDiamensional[sortedRows][sortedColumns]);
            ++sortedColumns;
        }
        ++sortedRows;
    }
    return 0;
}