/*
    FILE               :    bubbleSort.cpp
    PROJECT            :    None
    PROGRAMMER         :    Braiden Gole
    FIRST VERSION      :    2019-12-20
    DESCRIPTION        :    This is one of the simplest sorting algorithms called
                            "bubble sort."
*/
#include <stdio.h>

#define KMAXSORTLENGTH 10

int main(void)
{   
    // Initialize an array to sort.
    int arrayToSort[KMAXSORTLENGTH] = { 4, 6, 8, 2, 4, 1, 7, 4, 14, 56 };
    short bubble = 0; short reverseSwap = 0; short valueToSwap = 0;
    while (bubble < KMAXSORTLENGTH - 1)
    {   
        reverseSwap = KMAXSORTLENGTH - 1;
        while (reverseSwap > bubble)
        {   
            if (arrayToSort[reverseSwap - 1] > arrayToSort[reverseSwap])
            {
                valueToSwap = arrayToSort[reverseSwap - 1];
                arrayToSort[reverseSwap - 1] = arrayToSort[reverseSwap];
                arrayToSort[reverseSwap] = valueToSwap;
            }
            --reverseSwap;
        }
        ++bubble;
    }

    // Display the array of sorted elements.
    short sortedItems = 0;
    while (sortedItems < KMAXSORTLENGTH)
    {
        printf("%i ", arrayToSort[sortedItems]);
        ++sortedItems;
    }
    return 0;
}