/**
 * @file summationOfPowers.c
 * @author Braiden Gole
 * @brief This is a small program on summations.
 *  This program will raise each number raised to the power
 *  of a constant of a specific range (start) and (end) can
 *  be specified.
 * @version 0.1
 * @date 2021-01-10
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

// Function prototypes.
const double summationOfPowers(const double (*func)(double, double), 
                               int start, const int end, const double raise);
const double power(double value, double raisedTo);

int main(void)
{   
    double result = 0;
    result = summationOfPowers(power, 2, 4, 2);
    printf("%.lf", result);
    return 0;
}

/**     -- Function header commment
 *  FUNCTION        :   summationOfPowers
 *  DESCRIPTION     :   This function will produce a summationOfPowers of the function
 *                      provided given the range of start to end.
 *  PARAMETERS      :   func(double, double), start, end, raise
 *  RETURNS         :   result
 */
const double summationOfPowers(const double (*func)(double, double), int start, const int end, const double raise)
{   
    double result;
    result = 0;
    for (int cycles = start; cycles < end; cycles++)
    {
        result += func(cycles, raise);
    }
    return result;
}

/**     -- Function header commment
 *  FUNCTION        :   power
 *  DESCRIPTION     :   This is my custom power function where it will
 *                      return a constant safe copy of the value calculated.
 *  PARAMETERS      :   value, raisedTo
 *  RETURNS         :   result
 */
const double power(double value, double raisedTo)
{   
    double result = 1;
    for (int exponent = 0; exponent < raisedTo; exponent++)
    {
        result *= value;
    }
    return result;
}