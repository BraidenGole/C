/**
 * @file boyerMoore.c
 * @author Braiden Gole
 * @brief This is a Boyer Moore pattern search implementation.
 * 
 * This implementation also includes a display of all occurences of the mask found in the pattern.
 * --------------------------------------------------------------------------------------------
 * (Learned about the Boyer Moore Algorithm from (GeeksForGeeks))
 * [SOURCE/WEBSITE]: https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
 * --------------------------------------------------------------------------------------------
 * --------------------------------------------------------------------------------------------
 * (Very helpful source for understanding the algorithm Boyer Moore by [Ben Langmead])
 * [SOURCE/WEBSITE]: https://www.youtube.com/watch?v=4Xyhb72LCX4
 * --------------------------------------------------------------------------------------------
 * @version 0.1
 * @date 2021-03-02
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <string.h>

#define ASCIIEXTENDEDLENGTH 256
#define PATTERNLENGTH 100
#define ZERO 0
#define NEGATIVEONE -1
#define ONE 1
#define LIMITONMATCHES 100
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#define __LSS__ <
#define __LRG__ >
#define __LSSEQ__ <=
#define __LRGEQ__ >=
#define __EQ__ ==
#define __NEQ__ !=
#define AND &&

// Function prototypes.
int* boyerMooreSearch(char* mask, char* pattern, int* matchQuantity, int matches[]);
void preprocess(char mask[], const int size, char badHeuristic[]);

int main(void)
{   
    char mask[PATTERNLENGTH] = {"XYZ"};
    char pattern[PATTERNLENGTH] = {"XZZYZXXXYZXYZZXYZYXXZZYZXYZ"};

    // Perform Boyer Moores algorithm.
    int sizeOfMatches = ZERO;
    int unpackMatches[LIMITONMATCHES] = { ZERO };
    int* matches = NULL;

    matches = boyerMooreSearch(mask, pattern, &sizeOfMatches, unpackMatches);

    // Show all of the matching positions indices.
    int amountOfMatches = ZERO;
    while (amountOfMatches __LSS__ sizeOfMatches)
    {
        printf("Found position: %i\n", matches[amountOfMatches]);
        ++amountOfMatches;
    }
    return ZERO;
}

/**     -- Function header commment
 *  FUNCTION        :   boyerMooreSearch
 *  DESCRIPTION     :   This function will perform the arithmetic of the Boyer Moore algorithm
 *                      it will return the set of matches found.
 *  PARAMETERS      :   mask, pattern
 *  RETURNS         :   matches
 */
int* boyerMooreSearch(char* mask, char* pattern, int* matchQuantity, int matches[])
{
    int lengthOfMask = strlen(mask);
    int lengthOfPattern = strlen(pattern);
    int difference = lengthOfPattern - lengthOfMask;

    int shift = ZERO;
    int decMaskLen = ZERO;
    int index = ZERO;
    int badIndex = ZERO;

    int leftSide = ZERO;
    int rightSide = ZERO;
    int indexHeuristic = ZERO;

    int numOfMatches = ZERO;
    char badHeuristic[ASCIIEXTENDEDLENGTH] = {""};
    preprocess(mask, lengthOfMask, badHeuristic);

    do 
    {   
        // Start at the end of the XYZ.
        // While the characters are matching decrement to the adjacent character in the mask.
        decMaskLen = lengthOfMask - ONE;
        while (mask[decMaskLen] __EQ__ pattern[shift + decMaskLen] AND (decMaskLen __LRGEQ__ ZERO))
        {   
            --decMaskLen;
        }

        // We have stopped matching characters or have met -1.
        if (decMaskLen __LRG__ NEGATIVEONE)
        {   
            // Shift the pattern so that the bad character is aligned with the
            // matching occurrence in the pattern.
            badIndex = (int)pattern[shift + decMaskLen];
            index = decMaskLen - badHeuristic[badIndex];

            // Max keeps the shift in the positive direction.
            shift += MAX(ONE, index);
        }
        else
        {   
            // Collect the matches to print.
            matches[numOfMatches] = shift;
            ++numOfMatches;

            leftSide = ((shift + lengthOfMask) __LSS__ lengthOfPattern);

            indexHeuristic = (int)pattern[shift + lengthOfMask];
            rightSide = lengthOfMask - badHeuristic[indexHeuristic];

            if (leftSide __LSS__ ZERO)
            {
                shift += ZERO;
            }
            else
            {   
                shift += ONE;
            }
        }
    } while (shift __LSSEQ__ difference);
    *matchQuantity = numOfMatches;
    return matches;
}

/**     -- Function header commment
 *  FUNCTION        :   preprocess
 *  DESCRIPTION     :   This function is solely responsible for preparing our resources necessary
 *                      to compare for later.
 *  PARAMETERS      :   mask, size
 *  RETURNS         :   None
 */
void preprocess(char mask[], const int size, char badHeuristic[])
{   
    // Mark (-1) because it is not a position.
    // Mark (-1) because we can add or subtract from the value later.
    int characters = ZERO;
    while (characters __LSS__ ASCIIEXTENDEDLENGTH)
    {
        badHeuristic[characters] = NEGATIVEONE;
        ++characters;
    }

    // Store a auto numbering occurence at the index of the ascii value of each character
    // in the mask.
    int asciiValue = ZERO;
    for (int position = ZERO; position __LSS__ size; position++)
    {
        asciiValue = (int)mask[position];
        badHeuristic[asciiValue] = position;
    }
}

