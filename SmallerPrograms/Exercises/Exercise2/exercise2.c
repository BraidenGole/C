/**
 * @file exercise2.c
 * @author Braiden Gole
 * @brief This is an exercise for myself.
 * 
 * [IMPORTANT]: The answers have been comapred with online calculators and the variance and standard deviation vary slightly with some.
 *              A online calculator that matches the answers is sourced below !
 * ---------------------------------------------------------------------------------------------------------------------------------------------------
 * (Calculator.net Standard Deviation Calculator)
 * [SOURCE/WEBSITE]: https://www.calculator.net/standard-deviation-calculator.html?numberinputs=3%2C+4%2C+10%2C+19%2C+26%2C+29%2C+55&ctype=p&x=81&y=19
 * ---------------------------------------------------------------------------------------------------------------------------------------------------
 * @version 0.1
 * @date 2021-04-01
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <math.h>

// Header files.
#include "exercise2.h"

#define SWAP(tmp, x, y) {tmp=x, x=y, y=tmp;}

// Function prototypes.
double calculateMean(int* setOfNumbers, int size);
const int calculateMedian(int* setOfNumbers, int size);
const double calculateMode(int* setOfNumbers, int size);
double calculateVariance(int* setOfNumbers, int size);
const double calculateStandardDeviation(int* setOfNumbers, int size);

int main(void)
{   
    int testSet[LIMIT] = { 3, 4, 10, 19, 26, 29, 55 };
    //int testSet[LIMIT] = { 9, 40, 89, 10, 11, 11, 11 };
    // int testSet[LIMIT] = { 101, 105, 106, 107, 109, 110, 111 };
    // int testSet[LIMIT] = { 10, 99, 79, 13, 85, 39, 89 };

    printf("Mean: %.1lf\n", calculateMean(testSet, LIMIT));
    printf("Mode: %.1lf\n", calculateMode(testSet, LIMIT));
    printf("Median: %i\n", calculateMedian(testSet, LIMIT));
    printf("Variance: %.1lf\n", calculateVariance(testSet, LIMIT));
    printf("Standard Deviation: %.1lf", calculateStandardDeviation(testSet, LIMIT));
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   calculateMean
 *  DESCRIPTION     :   This function will calculate the mean.
 *  PARAMETERS      :   setOfNumbers, size
 *  RETURNS         :   mean
 */
double calculateMean(int* setOfNumbers, int size)
{   
    double sum = ZERO;
    for (int nums = ZERO; nums __LSS__ size; nums++)
    {
        sum += setOfNumbers[nums];
    }
    double mean = sum / (double)size;
    return mean;
}

/**     -- Function header comment
 *  FUNCTION        :   calculateMedian
 *  DESCRIPTION     :   This function will calculate the median.
 *  PARAMETERS      :   setOfNumbers, size
 *  RETURNS         :   setOfNumbers[calculateMiddleIndex]
 */
const int calculateMedian(int* setOfNumbers, int size)
{   
    int temp = ZERO;
    for (int nums = ZERO; nums __LSS__ size; nums++)
    {
        for (int sort = ZERO; sort __LSS__ size; sort++)
        {
            if (setOfNumbers[sort] __LRGEQ__ setOfNumbers[sort + ONE])
            {
                SWAP(temp, setOfNumbers[sort], setOfNumbers[sort + ONE])
            }
        }
    }
    int calculateMiddleIndex = (size + ONE) / TWO - ONE;
    return setOfNumbers[calculateMiddleIndex];
}

/**     -- Function header comment
 *  FUNCTION        :   calculateMode
 *  DESCRIPTION     :   This function will calculate the mode.
 *  PARAMETERS      :   setOfNumbers, size
 *  RETURNS         :   mode
 */
const double calculateMode(int* setOfNumbers, int size)
{   
    int countFreq = ZERO;
    int mostFreq = ZERO;
    int mode = ZERO;
    for (int nums = ZERO; nums __LSS__ size; nums++)
    {
        for (int check = ZERO; check __LSS__ size; check++)
        {
            // Check for when we find two of the same matching numbers.
            if (setOfNumbers[check] __EQ__ setOfNumbers[nums])
            {
                ++countFreq;
            }
        }
        // Keep adding most frequent numbers to a spare variable.
        if (countFreq __LRG__ mostFreq)
        {   
            // Handles the most frequent count.
            mostFreq = countFreq;

            // Capture the element that appeared more than once.
            mode = setOfNumbers[nums];
        }
    }
    return mode;
}

/**     -- Function header comment
 *  FUNCTION        :   calculateVariance
 *  DESCRIPTION     :   This function will calculate the variance.
 *  PARAMETERS      :   setOfNumbers, size
 *  RETURNS         :   calculateVariance
 */
double calculateVariance(int* setOfNumbers, int size)
{
    double mean = calculateMean(setOfNumbers, size);
    double squareDifference = ZERO;
    for (int nums = ZERO; nums __LSS__ size; nums++)
    {   
        squareDifference += pow((setOfNumbers[nums] - mean), TWO);
    }
    double variance = squareDifference / (double)size;
    return variance;
}

/**     -- Function header comment
 *  FUNCTION        :   calculateStandardDeviation
 *  DESCRIPTION     :   This function will calculate the standard deviation.
 *  PARAMETERS      :   setOfNumbers, size
 *  RETURNS         :   standardD
 */
const double calculateStandardDeviation(int* setOfNumbers, int size)
{
    double standardD = sqrt(calculateVariance(setOfNumbers, size));
    return standardD;
}
