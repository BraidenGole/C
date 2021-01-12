/**
 * @file computeLogOfBase2.c
 * @author Braiden Gole
 * @brief This is a small program that computes a logarithm of base 2.
 * @version 0.1
 * @date 2021-01-11
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>

#define KSPEEDYDIV(x, y) { x /= y; }
#define KTWO 2

// Function prototypes.
const unsigned int logOfBase2(unsigned int number);

int main(void)
{   
    const unsigned int KINPUT = 64;
    printf("Evaluation: %u", logOfBase2(KINPUT));
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   logOfBase2
 *  DESCRIPTION     :   This will calculate the log of base 2. This function
 *                      will not produce the 
 *  PARAMETERS      :   number
 *  RETURNS         :   logBase2
 */
const unsigned int logOfBase2(unsigned int number)
{   
    int logBase2 = 0;
    if (number <= 0)
    {
        return 0;
    }

    logBase2 = (-1);
    while (number != 0)
    {
        KSPEEDYDIV(number, KTWO);
        ++logBase2;
    }
    return logBase2;
}