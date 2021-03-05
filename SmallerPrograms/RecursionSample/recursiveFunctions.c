/**
 * @file recursiveFunctions.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-04
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

// Header files.
#include "recursiveFunctions.h"

/**     -- Function header comment
 *  FUNCTION        :   countDigits
 *  DESCRIPTION     :   This will break a number down and
 *                      count its corresponding digits.
 *  PARAMETERS      :   numberToBreak, numberOfDigits
 *  RETURNS         :   None
 */
void countDigits(long numberToBreak, int* numberOfDigits)
{
    if (numberToBreak __LSSEQ__ ZERO)
    {
        return;
    }
    else
    {
        numberToBreak /= TEN;
        *numberOfDigits = *numberOfDigits + ONE;
        countDigits(numberToBreak, numberOfDigits);
    }
}

/**     -- Function header comment
 *  FUNCTION        :   filterNumbers
 *  DESCRIPTION     :   This function will filter the even from the 
 *                      odd numbers using recursion.
 *  PARAMETERS      :   array, size, iter
 *  RETURNS         :   None
 */
void filterNumbers(int array[], const int size, int iter)
{
    if (iter __EQ__ size)
    {
        return;
    }
    else
    {   
        int evaluateDigit = array[iter];
        if (evaluateDigit % TWO __EQ__ ZERO)
        {
            printf("\n\tEVEN: %i", array[iter]);
        }
        else
        {
            printf("\n\tODD: %i", array[iter]);
        }
    }
    filterNumbers(array, size, iter + ONE);
}

/**     -- Function header comment
 *  FUNCTION        :   calculatePower
 *  DESCRIPTION     :   This function will calculate the power using recursion.
 *  PARAMETERS      :   base, exponent, copy, count
 *  RETURNS         :   None
 */
void calculatePower(int* base, int exponent, int copy, int count)
{   
    if (count __EQ__ (exponent))
    {
        return;
    }
    *base *= copy;
    calculatePower(base, exponent, copy, count + 1);
}