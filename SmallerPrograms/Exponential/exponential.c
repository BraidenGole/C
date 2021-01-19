/**
 *  FILE            :   exponential.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-29
 *  DESCRIPTION     :   This program will calculate a number raised by another.
 */
#include <stdio.h>
#include <stdbool.h>

// Header file.
#include "operations.h"

// Declare the menu selections.
enum MenuSelection{ KCHANGEBASE = 1, KCHANGEEXPONENT = 2, KPRINTRESULT = 3, KENDPROGRAM = 4 };

int main(void)
{
    unsigned int iSelection = 0;
    bool bSelectionCondition = true;
    bool bProgramCondition = true;

    int iBase = 0; 
    int iExponent = 0;
    int iResult = 0;

    while (bProgramCondition)
    {   
        // Output the menu options.
        displayMenuOptions();

        do
        {
            printf(KPROMPT_FOR_SELECTION);
            if ((fscanf(stdin, "%i", &iSelection)) == 0) 
            { 
                fflush(stdin);
            }
            if (iSelection >= 1 && iSelection <= KENDPROGRAM) 
            { 
                bSelectionCondition = false;
            }
        } while (bSelectionCondition != false);

        switch (iSelection)
        {
            case KCHANGEBASE:
                iBase = 1;
                iBase = iChangeBase(iBase);
                break;
            case KCHANGEEXPONENT:
                iExponent = 1;
                iExponent = iChangeExponent(iExponent);
                break;
            case KPRINTRESULT:
                iResult = calculatePower(iBase, iExponent);
                printf("\n\t>> RESULT: [%i]\n\n", iResult);
                break;
            case KENDPROGRAM:
                bProgramCondition = false;
                break;
        }
    }
    return 0;
}
