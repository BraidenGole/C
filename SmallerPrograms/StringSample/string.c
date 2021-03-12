/**
 * @file string.c
 * @author Braiden Gole
 * @brief This is a sample of string handling in C.
 * @version 0.1
 * @date 2021-03-12
 * @copyright Copyright (c) 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Header files.
#include "stringFunctions.h"

// Function protoypes.
const char* removeAllPunctuation(char* input);

int main(void)
{   
    char input[K100BYTES] = {"B.R.A.I.D.E.N"};
    const char* retVal = NULL;
    retVal = removeAllPunctuation(input);
    printf("%s", retVal);

    int numberOfWords = ZERO;
    char inputLine[K100BYTES] = {"This sentence is for counting words!"};
    numberOfWords = countNumberOfWordsInLine(inputLine);
    printf("\nAmount of words: %i", numberOfWords);

    const char DOT = '.';
    printf("\nNumber of occurrences: %i", countOccurrencesOfCharacter(".B.raiden...", DOT));

    printf("\n");

    printf("\n-- Filtered codes --\n");
    char* codeArray[CODESIZE] =  { "BYTV64XxWj5", "CATBYff3mMb5", "BYTV89RiVN3", "AYTVqQW42KLMJ" };
    filterCodes(codeArray, CODESIZE);

    printf("\n");

    char word[K100BYTES] = {"?!Braiden!?"};
    char keys[K100BYTES] = {"!?"};
    forKeysInInput(word, keys);
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   removeAllPunctuation
 *  DESCRIPTION     :   This will take in the input string and strip all of the
 *                      punctuation characters out.
 *  PARAMETERS      :   input
 *  RETURNS         :   input
 */
const char* removeAllPunctuation(char* input)
{   
    int letters;
    int inner;
    int length = strlen(input);
    for (letters = ZERO; letters __LSS__ length; letters++)
    {
        if ((ispunct(input[letters])) __NEQ__ ZERO)
        {
            for (inner = letters; inner __LSS__ length; inner++)
            {
                input[inner] = input[inner + ONE];
            }
            --length;
            --letters;
        }
    }
    return input;
}
