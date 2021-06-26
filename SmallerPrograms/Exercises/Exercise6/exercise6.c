/**
 * @file exercise6.c
 * @author Braiden Gole
 * @brief This is exercise 6.
 * @version 0.1
 * @date 2021-06-24
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// Function prototypes.
int lowestCommonMultiple(int valueOne, int valueTwo);
int greatestCommonFactor(int valueOne, int valueTwo);
void pascalsTriangle(int numberOfRows);
int calculateAngleOfClock(double hour, double minute);
bool isFibonacci(int potentialFibNumber);
bool checkSquare(int potentialSquare);

int main(void)
{
    int lcd = lowestCommonMultiple(5, 10);
    printf("The LCM is: %i", lcd);

    int gcd = greatestCommonFactor(5, 10);
    printf("\nThe GCF is: %i\n", gcd);

    // Print pascals triangle.
    pascalsTriangle(10);

    int angleOfHourAndMinute = calculateAngleOfClock(10, 30);
    printf("\n\nThe angle of the hour and minute hand is: %i ", angleOfHourAndMinute);

    int potentialNumber = 377;
    bool isAFibonacciNumber = isFibonacci(potentialNumber);
    if (isAFibonacciNumber == true)
    {
        printf("\n\n%d is a fibonacci number !", potentialNumber);
    }
    else
    {
        printf("\n\n%d is NOT a fibonacci number !", potentialNumber);
    }
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   greatestCommonFactor
 *  DESCRIPTION     :   This function is responsible for calculating the greatest common
 *                      denominator.
 *  PARAMETERS      :   valueOne, valueTwo
 *  RETURNS         :   answer
 */
int greatestCommonFactor(int valueOne, int valueTwo)
{   
    int checkOne = 0;
    int checkTwo = 0;
    int answer = 0;
    for (int index = 1; index <= valueOne && index <= valueTwo; index++)
    {
        checkOne = valueOne % index;
        checkTwo = valueTwo % index;
        if (checkOne == 0 && checkTwo == 0)
        {
            answer = index;
        }
    }
    return answer;
}

/**     -- Function header comment
 *  FUNCTION        :   lowestCommonMultiple
 *  DESCRIPTION     :   This function is responsible for calculating the lowest common denominator.
 *  PARAMETERS      :   valueOne, valueTwo
 *  RETURNS         :   answer
 */
int lowestCommonMultiple(int valueOne, int valueTwo)
{
    int answer = (valueOne * valueTwo) / greatestCommonFactor(valueOne, valueTwo);
    return answer;
}

/**     -- Function header comment
 *  FUNCTION        :   pascalsTriangle
 *  DESCRIPTION     :   This function will print pascals triangle up to the number of rows
 *                      supplied.
 *  PARAMETERS      :   numberOfRows
 *  RETURNS         :   None
 */
void pascalsTriangle(int numberOfRows)
{
    int coefficient = 1;
    int rows = 0;
    int space;
    int iter;
    while (rows < numberOfRows)
    {   
        space = 0;
        while (space <= numberOfRows - rows)
        {
            printf("  ");
            ++space;
        }
        iter = 0;
        while (iter <= rows)
        {
            if (rows == 0 || iter == 0)
            {
                coefficient = 1;
            }
            else 
            {   
                coefficient = coefficient * (rows - iter + 1) / iter;
            }
            printf("%4i", coefficient);
            ++iter;
        }
        ++rows;
        printf("\n");
    }
}

/**     -- Function header comment
 *  FUNCTION        :   calculateAngleOfClock
 *  DESCRIPTION     :   This function calculates the angle of the hour and minute hand. 
 *  PARAMETERS      :   hour, minute
 *  RETURNS         :   angle
 */
int calculateAngleOfClock(double hour, double minute)
{   
    if (hour < 0 || hour > 12)
    {
        return -1;
    }
    if (minute < 0 || minute > 60)
    {
        return -1;
    }

    if (hour == 12)
    {
        hour = 0;
    }

    if (minute == 60)
    {
        minute = 0;
        hour += 1;
        if (hour > 12)
        {
            hour -= 12;
        }
    }
    double hourAngle = 0.5 * (hour * 60 + minute);
    double minuteAngle = 6 * minute;
    double angle = abs(hourAngle - minuteAngle);
    angle = MIN(360 - angle, angle);
    return angle;
}

/**     -- Function header comment
 *  FUNCTION        :   checkSquare
 *  DESCRIPTION     :   This checks the square to see if it is a perfect square.
 *  PARAMETERS      :   potentialSquare
 *  RETURNS         :   true, false
 */
bool checkSquare(int potentialSquare)
{
    int squareRoot = sqrt(potentialSquare);
    if ((squareRoot * squareRoot) == potentialSquare)
    {
        return true;
    }
    return false;
}

/**     -- Function header comment
 *  FUNCTION        :   isFibonacci
 *  DESCRIPTION     :   This function checks the given number to see if it is a fibonacci number.
 *  PARAMETERS      :   potentialFibNumber
 *  RETURNS         :   true false
 */
bool isFibonacci(int potentialFibNumber)
{   
    int arithmeticOne = 5 * potentialFibNumber * potentialFibNumber + 4;
    int arithmeticTwo = 5 * potentialFibNumber * potentialFibNumber - 4;

    bool squareOne = checkSquare(arithmeticOne);
    bool squareTwo = checkSquare(arithmeticTwo);
    if (squareOne == true)
    {
        return true;
    }
    if (squareTwo == true)
    {
        return true;
    }
    return false;
}