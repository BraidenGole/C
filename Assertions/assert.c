/**
 * @file assert.c
 * @author Braiden Gole
 * @brief This is a sample on assertions in the C programming language.
 * @version 0.1
 * @date 2021-02-18
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define NUMERICLIMIT 50
#define STRINGLIMIT 500
#define ERROR -1
#define ZERO 0
#define ONE 1
#define TWO 2
#define __NOT__ !

// Function prototypes.
void numericAssertion(int numbers[]);
void stringAssertion(char* stringArray);
void ctrlcHandler(int signalCode);

// Global variables.
bool ctrlcStatus = true;

int main(void)
{   
    int numericArray[NUMERICLIMIT] = { ZERO };
    char stringArray[STRINGLIMIT] = {""};

    int selection = ZERO;
    printf("1. Numeric Assertion.\n");
    printf("2. String Assertion.\n");
    printf("\n\tAssertion: ");

    if ((fscanf(stdin, "%i", &selection)) == ZERO)
    {
        fprintf(stderr, "\n\tNo characters !\n");
        fflush(stdin);
        return ERROR;
    }
    else
    {   
        // Eat the spare newline character so it does not effect our string assertion function.
        getchar();
        if (selection == ONE)
        {
            numericAssertion(numericArray);
        }
        else if (selection == TWO)
        {
            stringAssertion(stringArray);
        }
    }
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   numericAssertion
 *  DESCRIPTION     :   This function will demonstrate a numeric
 *                      assertion.
 *  PARAMETERS      :   numbers
 *  RETURNS         :   None
 */
void numericAssertion(int numbers[])
{   
    // Active signal to check to see if user presses ctrl + c.
    if ((signal(SIGINT, ctrlcHandler)) == SIG_ERR)
    {
        fprintf(stderr, "\n\tSignal could not be set at this moment.\n");
        return;
    }
    else
    {   
        int amountOfNumbers = ZERO;
        bool gatherNumericInput = true;
        while (gatherNumericInput)
        {
            printf("\n\tEnter in a number or [CTRL + C]: ");
            if ((fscanf(stdin, "%i", &numbers[amountOfNumbers])) == ZERO)
            {
                fprintf(stderr, "\n\tNo characters !\n");
                fflush(stdin);
            }
            else
            {   
                // Assertion failure if the user enters in a negative number.
                assert(numbers[amountOfNumbers] >= ZERO);
                printf("\n\tYour number [%i] is positive !\n", numbers[amountOfNumbers]);
            }
            ++amountOfNumbers;
        }
    }
}

/**     -- Function header comment
 *  FUNCTION        :   stringAssertion
 *  DESCRIPTION     :   This function will demonstrate a string
 *                      assertion.
 *  PARAMETERS      :   stringArray
 *  RETURNS         :   None
 */
void stringAssertion(char* stringArray)
{   
    // Active signal to check to see if user presses ctrl + c.
    if ((signal(SIGINT, ctrlcHandler)) == SIG_ERR)
    {
        fprintf(stderr, "\n\tSignal could not be set at this moment.\n");
        return;
    }
    else
    {   
        int numberOfWords = ZERO;
        bool gatherStringInput = true;
        while (gatherStringInput)
        {   
            printf("\n\tEnter in a word or [CTRL + C]: ");
            fgets(stringArray, STRINGLIMIT, stdin);

            // If any of the words are a punctuation character raise assertion.
            assert(__NOT__(ispunct(stringArray[numberOfWords])));
        }
    }
}

/**     -- Function header comment
 *  FUNCTION        :   ctrlcHandler
 *  DESCRIPTION     :   This function will represent a signal handler
 *                      for the specific event
 *  PARAMETERS      :   signalCode
 *  RETURNS         :   None
 */
void ctrlcHandler(int signalCode)
{
    ctrlcStatus = false;
    printf("\n\n\tPRESSED [CTRL + C]\n");
    exit(ZERO);
}
