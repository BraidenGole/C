/**
 * @file dateTime.c
 * @author Braiden Gole
 * @brief This is an example of timing a process in the (C) programming language.
 * 
 * [IMPORTANT:] The example below shows how to properly time your code but I want
 *              to say that I learned you need an "estimated" array size of one-hundred thousand
 *              at least in order accumulate any time on the clock.
 * 
 * [IMPORTANT:] However, this will accumulate time because of the display for loop
 *              in-between the time tracker and ending time tracker.
 * @version 0.1
 * @date 2021-01-24
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <time.h>

#define KLIMIT 9
#define KROWS 16
#define KCOLS 16
#define KTOTAL (KROWS * KCOLS)
#define SWAP(tmp, x, y) { tmp=x, x=y, y=tmp; }

void x();

// Function header comments.
void bubbleSort(int set[KROWS][KCOLS], const int rows, const int cols);

int main(void)
{   
    // Create a large load to accumalte potential time for the clock.
    int array[KROWS][KCOLS] = 
    {
        { 3, 994, 54, 32, 87, 1, 5, 7, 7, -23, 12, 4, 66, -12, 44 },
        { 774, 332, 54, 32, -487, 1, 40, 7, 7, -8, 22, 4, 66, -12, 44 },
        { 190, -674, 54, 32, 87, 1, 535, 157, 7, -23, 12, 4, 66, -12, 246 },
        { 343, 453, 54, 32, 87, 1, -4955, 7, 7, -23, 12, 4, 66, -12, 204 },
        { 356, 166, 9354, 32, 587, 1, -35, 7, 7, -33, 1222, 464, 66, -1992, -404 },
        { 355, 184, 2354, 32, 87, 98, 5, 7, -2047, 73, 132, 4, -66, -12, 434 },
        { 384, 555, 14, 32, 87, 63, 5, 8372, 7, -23, 1002, 985, 66, -53, 142 },
        { 221, 470, 543, 32, 87, 873, 5, 7, 7, -23, 1012, 653, 66, -362, 44 },
        { 656, 690, 1254, 32, 87, 145, 5, 1012, 7, -2103, 12, 4, 66, -1872, 44 },
        { 3756, 4, 543, 32, 87, 651, 2542, 1732, 7, -23, 12, 4102, 66, -132, 44 },
        { -1000, 780, 54, 32, 87, 31, 5, 7, 7, -35, 12, 4, 66, -12, 44 },
        { 453, 4, 54, 312, 87, 1, 165, 7, -97, -23, 142, 4, 66, -12, 44 },
        { 6664, 2223, 2564, 32, 87, 1, 8335, -597, 7, -23, 12, 4, 66, -12, 424 },
        { 3561, 1434, 5364, 32, 87, 451, 5315, 117, 227, -23, 12, 4, 66, -12, 414 },
        { 3321, 7548, 5584, 32, 783, 1, 5, 2847, 7, -23, 12, 4, 66, -12, 44 },
        { 1234, 4443, 5434, 32, -99, -9999, -394, 4904, 7, -23, 12, 4, 66, -12, 44 }, 
    };

    clock_t trackTimeToDisplay;
    clock_t endTimeToDisplay;

    // Track to see how long it taks to sort the set and display it.
    int undoRows = 0;
    int undoCols = 0;

    // Start
    trackTimeToDisplay = clock();

    // The bubble sort function is so fast that the elapsed time
    // calculated will be 0.0000 but since the for loop is insde as
    // well it will count for the time it takes to display.
    bubbleSort(array, KROWS, KCOLS);
    
    for (undoRows = 0; undoRows < KROWS; undoRows++)
    {
        for (undoCols = 0; undoCols < KCOLS; undoCols++)
        {
            printf("%i ", array[undoRows][undoCols]);
        }
    }
    endTimeToDisplay = clock();
    // end.
    
    double timeElapsed = 0;
    double timeDifference = 0;

    timeDifference = (double)endTimeToDisplay - trackTimeToDisplay;
    timeElapsed = timeDifference / (double)CLOCKS_PER_SEC;
    printf("\n\n\tTime to display: %lf", timeElapsed);
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   bubbleSort
 *  DESCRIPTION     :   This is a bubble sort algorithm incased in a
 *                      function we are just creating this function
 *                      so we have a function to time to see how long
 *                      did it take to sort the elements.
 *  PARAMETERS      :   set, size
 *  RETURNS         :   None
 */
void bubbleSort(int set[KROWS][KCOLS], const int maxRows, const int maxCols)
{   
    int temp;
    int rows; 
    int cols;
    int sortUntilComplete = 0;
    
    while (sortUntilComplete < KTOTAL)
    {   
        rows = 0;
        while (rows < maxRows)
        {   
            cols = 0;
            while (cols < maxCols)
            {
                if (set[rows][cols] >= set[rows][cols + 1])
                {   
                    // Call to a macro with parameters.
                    SWAP(temp, set[rows][cols], set[rows][cols + 1])
                }
                ++cols;
            }
            ++rows;
        }
        ++sortUntilComplete;
    }
}
