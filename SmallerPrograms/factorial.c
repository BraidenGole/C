/**
 *  FILE            :   factorial.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-29
 *  DESCRIPTION     :   This is a program that gets a number from
 *                      the user and will calculate up to that number as
 *                      a factorial.
 */
#include <stdio.h>
#include <stdbool.h>

// Global string constants.
#define KPROMPT_FOR_NUMBER "Please enter in a number: "

// Global numeric constants.
#define KFACTORIALLIMIT 17

int main(void)
{
    unsigned int iMultiUpTo = 0;
    bool bInputCondition = true;
    do
    {
        printf(KPROMPT_FOR_NUMBER);
        if ((fscanf(stdin, "%i", &iMultiUpTo)) == 0) { fflush(stdin); }
        if (iMultiUpTo >= 1 && iMultiUpTo < KFACTORIALLIMIT) { break; }
    } while (bInputCondition != false);
    
    unsigned int iFactorial = 1;
    unsigned int iNumbers = 1;
    while (iNumbers <= iMultiUpTo)
    {
        iFactorial *= iNumbers;
        ++iNumbers;
    }

    // Display the calculated result.
    printf("Factorial [%i]: ", iFactorial);
    return 0;
}