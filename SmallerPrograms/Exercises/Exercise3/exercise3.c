/**
 * @file exercise3.c
 * @author Braiden Gole
 * @brief This is the implementation of the KMP Search Algorithm for an exercise.
 * -------------------------------------------------------------------------------------
 * (Learned the KMP algorithm from (GeeksForGeeks))
 * [SOURCE/WEBSITE]: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
 * -------------------------------------------------------------------------------------
 * -------------------------------------------------------------------------------------
 * (Video that helps explain the KMP algorithm (YouTube))
 * [SOURCE/WEBSITE]: https://www.youtube.com/watch?v=GTJr8OvyEVQ
 * -------------------------------------------------------------------------------------
 * @version 0.1
 * @date 2021-04-02
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Header files.
#include "exercise3.h"

// Function prototype.
void knuthMorrisPratt(char* text, char* pattern);

int main(void)
{
    char sequence[K100BYTES] = "XYZXZYXYZXYZ";
    char patternMatch[K100BYTES] = "XYZ";

    // KMP search algorithm.
    knuthMorrisPratt(sequence, patternMatch);
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   knuthMorrisPratt
 *  DESCRIPTION     :   This function represents the arithmetic performed
 *                      for a KMP search algorithm.
 *  PARAMETERS      :   text, pattern
 *  RETURNS         :   None
 */
void knuthMorrisPratt(char* text, char* pattern)
{
    int lengthOfText = strlen(text);
    int lengthOfPattern = strlen(pattern);

    int* collectedCounts = NULL;
    collectedCounts = (int*)malloc(sizeof(int) * K50BYTES);
    if (collectedCounts == NULL)
    {
        return;
    }

    // 0=0, 1=1, 2=2, 3=3, 4=4 (iter=value).

    // We need to collect a count because we need information about
    // how the pattern will matches against the shifts/differences.
    collectedCounts[ZERO] = ZERO;

    int lengthRepresentation = ZERO;
    int letters = ONE;
    while (letters __LSS__ lengthOfPattern)
    {   
        if (pattern[letters] __EQ__ pattern[lengthRepresentation])
        {   
            // For every character matched add 1 to the length and store the
            // total current length in an array.
            ++lengthRepresentation;
            collectedCounts[letters] = lengthRepresentation;
            
            // Increment to the next letter to check for a match.
            ++letters;
        }
        else
        {
            if (lengthRepresentation __EQ__ ZERO)
            {   
                collectedCounts[letters] = ZERO;
                ++letters;
            }
            else
            {   
                // Because we have to store lengths in a specific way so they can be compared
                // and used later, we have to start at 1 because collectedCount[ZERO] has to be
                // equal to ZERO and collectedCount[ONE] = 1, collectedCount[TWO] = 2.
                lengthRepresentation = collectedCounts[lengthRepresentation - ONE];
            }
        }
    }

    int lettersForPattern = ZERO;
    letters = ZERO;
    int position = ZERO;
    while (letters __LSS__ lengthOfText)
    {
        if (pattern[lettersForPattern] __EQ__ text[letters])
        {   
            // Two separate iterable variables to iterate through the
            // two different lengths.
            ++lettersForPattern;
            ++letters;
        }
        
        // We have to be able to output every position found.
        if (lettersForPattern __EQ__ lengthOfPattern)
        {   
            position = letters - lettersForPattern;
            printf("Found at position: %i\n", position);
            lettersForPattern = collectedCounts[lettersForPattern - ONE];
        }
        else
        {
            if (pattern[lettersForPattern] __NEQ__ text[letters])
            {
                if (lettersForPattern __NEQ__ ZERO)
                {   
                    lettersForPattern = collectedCounts[lettersForPattern - ONE];
                }
                else
                {
                    ++letters;
                }
            }
        } 
    }
    free(collectedCounts);
}
