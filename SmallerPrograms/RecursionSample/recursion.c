/**
 * @file recursion.c
 * @author Braiden Gole
 * @brief This is an example on recursion.
 * @version 0.1
 * @date 2021-03-04
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <string.h>

// Header files.
#include "recursiveFunctions.h"

// Function prototypes.
void reverseName(char* name, int iter, const int length);
void calculateFactorial(int factorial, int* answer, int iter);

int main(void)
{   
    // Reverse a name with recursion.
    char name[K100BYTES] = {"Braiden"};
    int length = strlen(name);
    int iterable = length;
    printf("\nYour name in reverse below:\n");
    reverseName(name, iterable, length);

    // Calculate a factorial using recursion.
    int setFactorial = 6;
    int result = ONE;
    iterable = ONE;
    calculateFactorial(setFactorial, &result, iterable);
    printf("\n\nThe factorial of (%i) is: [%i]", setFactorial, result);

    // Break a number down and count its digits.
    long breakMe = 123456789;
    int amountOfDigits = ZERO;
    countDigits(breakMe, &amountOfDigits);
    printf("\nAmount of digits in number: [%i]", amountOfDigits);

    // Filter a set of numbers using recursion.
    int setOfNumbers[SIZEOFFILTER] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    iterable = ZERO;
    printf("\n\n -- List of ODD or EVEN numbers --\n");
    filterNumbers(setOfNumbers, SIZEOFFILTER, iterable);
    printf("\n");

    // Calculate the power using recursion.
    int base = 8;
    int power = 4;
    int count = 1;
    int copyOfNumber = base;
    calculatePower(&base, power, copyOfNumber, count);
    printf("\nPower result: %i", base);
}

/**     -- Function header comment
 *  FUNCTION        :   reverseName
 *  DESCRIPTION     :   This function will reverse a name using recursion.
 *  PARAMETERS      :   name
 *  RETURNS         :   None
 */
void reverseName(char* name, int iter, const int length)
{   
    if (iter __LSSEQ__ ZERO)
    {
        return;
    }
    else
    {
        printf("%c ", name[iter - ONE]);
        reverseName(name, iter - ONE, length);
    }
}

/**     -- Function header comment
 *  FUNCTION        :   calculateFactorial
 *  DESCRIPTION     :   This function will calculate the factorial
 *                      supplied.
 *  PARAMETERS      :   factorial, answer, iter
 *  RETURNS         :   None
 */
void calculateFactorial(int factorial, int* answer, int iter)
{   
    if (iter __EQ__ (factorial + ONE))
    {
        return;
    }
    *answer *= iter;
    calculateFactorial(factorial, answer, iter + ONE);
}