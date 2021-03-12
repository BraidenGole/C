/**
 * @file stringFunctions.c
 * @author Braiden Gole
 * @brief This is string handling in C.
 * @version 0.1
 * @date 2021-03-12
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Header files.
#include "stringFunctions.h"

/**     -- Function header comment
 *  FUNCTION        :   countNumberOfWordsInLine
 *  DESCRIPTION     :   This function will count the number of words
 *                      in a line.
 *  PARAMETERS      :   line
 *  RETURNS         :   wordCount
 */
const int countNumberOfWordsInLine(char* line)
{   
    int wordCount = ZERO;
    int letters = ZERO;
    int lineLength = strlen(line);
    while (letters __LSS__ lineLength)
    {
        if ((isspace(line[letters])) __NEQ__ ZERO)
        {
            ++wordCount;
        }
        ++letters;
    }
    return wordCount + ONE;
}

/**     -- Function header comment
 *  FUNCTION        :   countOccurrencesOfCharacter
 *  DESCRIPTION     :   This function will count the amount of occurrences of the character
 *                      supplied by the user.
 *  PARAMETERS      :   input
 *  RETURNS         :   occurrences
 */
const int countOccurrencesOfCharacter(char* input, const char character)
{   
    int occurrences = ZERO;
    int length = strlen(input);
    for (int symbols = ZERO; symbols __LSS__ length; symbols++)
    {
        if (input[symbols] == character)
        {
            ++occurrences;
        }
    }
    return occurrences;
}

/**     -- Function header comment
 *  FUNCTION        :   filterCodes
 *  DESCRIPTION     :   This function will filter codes using the function strncmp().
 *  PARAMETERS      :   codes, size
 *  RETURNS         :   None
 */ 
void filterCodes(char* codes[CODESIZE], const int size)
{
    for (int entries = ZERO; entries __LSS__ size; entries++)
    {
        if ((strncmp(codes[entries], "BYTV", CODESIZE)) __EQ__ ZERO)
        {
            printf("\t%s\n", codes[entries]);
        }
    }
}

/**     -- Function header comment
 *  FUNCTION        :   forKeysInInput
 *  DESCRIPTION     :   This function will output every occurrence of
 *                      any one of the characters in the keys.
 *  PARAMETERS      :   input, keys
 *  RETURNS         :   None
 */
void forKeysInInput(char* input, char* keys)
{   
    char* foundKey = NULL;
    printf("Keys Found: ");
    foundKey = strpbrk(input, keys);
    while (foundKey __NEQ__ NULL)
    {
        printf("%c ", *foundKey);
        foundKey = strpbrk(foundKey + ONE, keys);
    }
}