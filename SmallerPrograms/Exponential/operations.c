/**
 *  FILE            :   operations.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-29
 *  DESCRIPTION     :   This file will hold functionality for each menu selection that exists.
 */
#include <stdio.h>
#include <stdbool.h>

// Header file.
#include "operations.h"

/**     -- Function header comment
 *  FUNCTION        :   iChangeBase
 *  DESCRIPTION     :   This function will change the value
 *                      of the base.
 *  PARAMETERS      :   iBase
 *  RETURNS         :   iNewBase
 */
const int iChangeBase(int iBase)
{
    // Prompt the user for a new base.
    int iNewBase = 0;
    bool bBaseCondition = true;
    do
    {
        printf(KPROMPT_FOR_BASE);
        if ((fscanf(stdin, "%i", &iNewBase)) == 0) { fflush(stdin); }
        else { bBaseCondition = false; }
    } while (bBaseCondition != false);
    return iNewBase;
}

/**     -- Function header comment
 *  FUNCTION        :   iChangeExponent
 *  DESCRIPTION     :   This function will change the value
 *                      of the exponent.
 *  PARAMETERS      :   iPower
 *  RETURNS         :   iNewExponent
 */
const int iChangeExponent(int iPower)
{
    int iNewExponent = 0;
    bool bExponentCondition = true;
    do
    {
        printf(KPROMPT_FOR_EXPONENT);
        if ((fscanf(stdin, "%i", &iNewExponent)) == 0) { fflush(stdin); }
        else { bExponentCondition = false; }
    } while (bExponentCondition != false);
    return iNewExponent;
}

/**     -- Function header comment
 *  FUNCTION        :   calculatePower
 *  DESCRIPTION     :   This function will calculate the power of the base
 *                      raised to the exponenet.
 *  PARAMETERS      :   iBase, iExponent
 *  RETURNS         :   iCalculation
 */
const int calculatePower(int iBase, int iExponent)
{
    int iRaising = 0; 
    int iCalculation = 1;

    while (iRaising < iExponent)
    {
        iCalculation *= iBase;
        ++iRaising;
    }
    return iCalculation;
}

/**     -- Function header comment
 *  FUNCTION        :   displayMenuOptions
 *  DESCRIPTION     :   This will display the available selections
 *                      that the program has to offer.
 *  PARAMETERS      :   None
 *  RETURNS         :   None
 */
void displayMenuOptions(void)
{
    printf(KMENUHEADER);
    printf(KSELECTION1);
    printf(KSELECTION2);
    printf(KSELECTION3);
    printf(KSELECTION4);
}