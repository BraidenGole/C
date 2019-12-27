/*  
    FILE            :   mergeSort.cpp
    PROJECT         :   None
    PROGRAMMER      :   Braiden Gole
    FIRST VERSION   :   2019-12-16
    DESCRIPTION     :   This is the implementation of "Merge Sort" algorithm.
                        This program is not recursive has a fixed array of
                        randomly generated values between the range of 1 -
                        100.
*/
#include <stdio.h>
#include <stdlib.h>

#define KRANDOMVALUESLIMIT 101
#define KHALFOFRANDOMVALUES (KRANDOMVALUESLIMIT / 2)

int main(void)
{   
    // Declare an array of randomValues[].
    int randomValues[KRANDOMVALUESLIMIT] = { 0 }; short randomize = 0;
    const short KrandomUpToOneHundred = 100; short newLineReset = 0;
    int partOne[KHALFOFRANDOMVALUES] = { 0 }; int partTwo[KHALFOFRANDOMVALUES] = { 0 };

    printf("\nBEFORE:\n\n");
    while (randomize < KRANDOMVALUESLIMIT)
    {
        // Assign 100 randomValues[], generating numbers KrandomUpToOneHundred.
        randomValues[randomize] = (rand() % KrandomUpToOneHundred);

        // Output the list of values.
        printf("%i ", randomValues[randomize]);

        // Line Break to show the difference BEFORE & AFTER.
        if (newLineReset > 19)
        {
            newLineReset = 0;
            printf("\n");
        }

        // Initially slice the randomValue[]'s array in / 2.
        if (randomize < KHALFOFRANDOMVALUES)
        {
            partOne[randomize] = randomValues[randomize];
        }
        else if ((randomize >= KHALFOFRANDOMVALUES) && (randomize < KRANDOMVALUESLIMIT))
        {
            partTwo[randomize] = randomValues[randomize];
        }
        ++randomize;
        ++newLineReset;
    }

    // Sort each part separately.
    short sortParts = 0; short reverseSwap = 0;
    short partSwitch = 0; int sortedValues[KRANDOMVALUESLIMIT] = { 0 };
    while (sortParts < KHALFOFRANDOMVALUES)
    {   
        reverseSwap = KRANDOMVALUESLIMIT - 1;
        while (reverseSwap > sortParts)
        {   
            // Sort Part #1
            if (partOne[reverseSwap - 1] > partOne[reverseSwap])
            {
                partSwitch = partOne[reverseSwap - 1];
                partOne[reverseSwap - 1] = partOne[reverseSwap];
                partOne[reverseSwap] = partSwitch;
            }

            // Sort Part #2
            if (partTwo[reverseSwap - 1] > partTwo[reverseSwap])
            {   
                partSwitch = partTwo[reverseSwap - 1];
                partTwo[reverseSwap - 1] = partTwo[reverseSwap];
                partTwo[reverseSwap] = partSwitch;
            }

            // Collect the sortedValues[] to display.
            sortedValues[reverseSwap] = partOne[reverseSwap];
            --reverseSwap;
        }
        ++sortParts;
    }

    // Display the sortedItems.
    printf("\nAFTER:\n\n");
    short sortedItems = 0; short controlOutput = 0;
    while (sortedItems < KRANDOMVALUESLIMIT)
    {
        printf("%i ", sortedValues[sortedItems]);
        ++sortedItems;
        ++controlOutput;

        // Line break every 20 lines.
        if (controlOutput > 19)
        {
            controlOutput = 0;
            printf("\n");
        }
    }
    return 0;
}