/**
 *  FILE            :   jumpSearch.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-19
 *  DESCRIPTION     :   This is the implementation of a jump search
 *                      algorithm.
 */
#include <stdio.h>
#include <math.h>

// Global string constants.
#define KINTRODUCTION "\n\t[ Type (-1) to QUIT ! ]\n\n"
#define KPROMPT_FOR_LOOKUPNUMBER "Enter in a lookup number: "
#define KFOUND "\nThe number to search was (FOUND) in the system !\n"
#define KNOTFOUND "\nThe number to look for was NOT found !\n"

// Global numeric constants.
#define KSEARCHINGLIMIT 16

// Declare the set of elements to work with.
const int ariSearchingSet[KSEARCHINGLIMIT] = 
{ 1, 1, 5, 6, 8, 12, 18, 20, 24, 26, 29, 49, 52, 55, 60, 90 };

// Function prototypes.
const int iJumpSearchingSet(int iNumberToDiscover);

int main(void)
{   
    // Introduction statement.
    printf(KINTRODUCTION);

    // Prompt the user for the number to lookup.
    int iLookupNumber = 0;
    do
    {   
        // Recursive initialization.
        iLookupNumber = -2;

        printf(KPROMPT_FOR_LOOKUPNUMBER);
        if ((fscanf(stdin, "%i", &iLookupNumber)) == 0) { fflush(stdin); }

        // Send the number to lookup into the jump sort function.
        if ((iJumpSearchingSet(iLookupNumber)) == 1) { printf(KNOTFOUND); }
        else { printf(KFOUND); }
    } while (iLookupNumber != -1);
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   iJumpSearchingSet
 *  DESCRIPTION     :   This function will perform the duties of a jump
 *                      sort algorithm while comparing elements to the
 *                      number to find.
 *  PARAMETERS      :   iNumberToDiscover
 *  RETURNS         :   0, 1
 */
const int iJumpSearchingSet(int iNumberToDiscover)
{   
    int iJump = 0; 
    int iJumpedTooFar = 0;
    int iBackTracking = 0;

    // Calculate the first jump to include the last jump for our loop.
    const int kiJumpAddition = sqrt(KSEARCHINGLIMIT);

    // Cycle through the set of elements and include the last jump.
    while (iJump < KSEARCHINGLIMIT + kiJumpAddition)
    {   
        // Go to the point where we have jumped too far.
        if (ariSearchingSet[iJump] > iNumberToDiscover)
        {
            iJumpedTooFar = iJump;
            iBackTracking = iJump - sqrt(KSEARCHINGLIMIT);

            // We have gone too far we need to decrement and check for a
            // matching lookup number in the set to search from, backtracking
            // only as far as the previous jump.
            while (iJumpedTooFar >= iBackTracking)
            {
                if (ariSearchingSet[iJumpedTooFar] == iNumberToDiscover)
                {
                    return 0;
                }
                --iJumpedTooFar;
            }
        }
        iJump += sqrt(KSEARCHINGLIMIT);
    }
    return 1;
}