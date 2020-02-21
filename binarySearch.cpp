/*
    FILE            :   binarySearch.cpp
    PROJECT         :   None
    PROGRAMMER      :   Braiden Gole
    FIRST VERSION   :   2020-02-20
    DESCRIPTION     :   This is the implementation of a binary search
                        algorithm.
*/
#include <stdio.h>
#include <string.h>

// Global string constants.
#define KPROMPT_FOR_NUMBERTOFIND "  Please enter in the number to find: "
#define KNOTFOUND "\n  The system could [ NOT ] find your number.\n"
#define KFOUND "\n  The system has found a (match) !\n"
#define KWOULD_YOU_LIKE_TO_QUIT "Would you like to quit? (Y) Or (N): "
#define KCONTINUE "\n\t>>> Continue...\n\n"
#define KGOODBYE "\n  [ GoodBye ! ]\n"
#define KINVALID_INPUT "\n  Invalid input !\n"

// Global numeric constants.
#define KSORTED_NUMBERS_LIMIT 10
#define KHALF_OF_SORTED_NUMBERS (KSORTED_NUMBERS_LIMIT / 2)

// Function prototypes.
bool bBinarySearch(int ariSortedSet[], int* piTheNumberToFind, int* piMatchingIndex);
bool bWouldYouLikeToQuit(void);

int main(void)
{
    int ariSortedNumbers[KSORTED_NUMBERS_LIMIT] = 
    { 33, 44, 55, 66, 77, 88, 99, 101, 130, 150 };
    
    // Prompt the user for the number to lookup.
    int iTheLookUpNumber = 0;
    do
    {
        printf(KPROMPT_FOR_NUMBERTOFIND);
        if ((fscanf(stdin, "%i", &iTheLookUpNumber)) == 0)
        {
            printf(KINVALID_INPUT);
            fflush(stdin);
        }
    } while (iTheLookUpNumber <= 0);

    int iRecordMatchingLocation = 0;
    if ((bBinarySearch(ariSortedNumbers, &iTheLookUpNumber, &iRecordMatchingLocation)) != true)
    {
        printf(KNOTFOUND);
        main();
    }
    else
    {   
        // If the number was found then display a message and its location.
        printf("%s\n\tLocation: [%i]\n\n", KFOUND, iRecordMatchingLocation);

        // Ask the user if they would like to quit the program.
        if ((bWouldYouLikeToQuit()) == true) { printf(KGOODBYE); return 0; }
        else { printf(KCONTINUE); main(); }
    }    
    return 0;
}

/*
    FUNCTION        :   bBinarySearch
    DESCRIPTION     :   This function takes in the sorted set of
                        numbers as input and will search for
                        the number to find.
    PARAMETERS      :   ariSortedSet[], piTheNumberToFind, piMatchingIndex
    RETURNS         :   true, false
*/
bool bBinarySearch(int ariSortedSet[], int* piTheNumberToFind, int* piMatchingIndex)
{
    // Grab the center element to compare with the rest.
    int* piMiddleElement = (int*)(&ariSortedSet[KHALF_OF_SORTED_NUMBERS]);

    int iAmountOfNumbers = 0;
    while (iAmountOfNumbers < KSORTED_NUMBERS_LIMIT)
    {
        // Filter numbers that are LESS THAN the middle element.
        if (ariSortedSet[iAmountOfNumbers] <= *piMiddleElement)
        {   
            if (ariSortedSet[iAmountOfNumbers] == *piTheNumberToFind)
            {
                *piMatchingIndex = iAmountOfNumbers;
                return true;
            }
        }
        // Filter numbers that are LARGER THAN the middle element.
        else
        {   
            if (ariSortedSet[iAmountOfNumbers] == *piTheNumberToFind)
            {
                *piMatchingIndex = iAmountOfNumbers;
                return true;
            }
        }
        ++iAmountOfNumbers;
    }
    return false;
}

/*
    FUNCTION        :   bWouldYouLikeToQuit
    DESCRIPTION     :   This function handles a recursive prompt
                        the prompt gives the user the option to
                        continue or to quit.
    PARAMETERS      :   None
    RETURNS         :   true, false
*/
bool bWouldYouLikeToQuit(void)
{   
    printf(KWOULD_YOU_LIKE_TO_QUIT);

    // A call to getchar to handle multiple inputs(corrects output).
    getchar();

    // Gather the decision.
    char cUsersDecision = getchar();

    const char kcYes = 'Y'; const char kcNo = 'N';

    // Did the user select "YES" Or "No"?
    if (cUsersDecision == kcYes) { return true; }
    else if (cUsersDecision == kcNo) { return false; }
    else { printf(KINVALID_INPUT); return false; }

    return false;
}