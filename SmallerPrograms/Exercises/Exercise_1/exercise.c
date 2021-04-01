/**
 * @file exercise.c
 * @author Braiden Gole
 * @brief This is a small exercise for myself.
 * @version 0.1
 * @date 2021-03-31
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Header files.
#include "exercises.h"

// Function prototypes.
int* removeDuplicates(int* sortedArray, int* size);
const bool isPalindrome(char* input, const int length);
char* removeDuplicateLetters(char* input, const int length);
long reverseNumber(long number);

int main(void) 
{
    int set[SIZE] = { 1, 11, 11, 44, 44, 55, 55 };
    int size = 7;
    int* newSet = NULL;
    newSet = removeDuplicates(set, &size);

    printf("Removed duplicates: ");
    for (int test = ZERO; test __LSS__ size; test++)
    {
        printf("%i ", newSet[test]);
    }

    char input[K100BYTES] = {"Braiden"};
    int len = strlen(input);
    if ((isPalindrome(input, len)) == false)
    {
        printf("\nIsPalindrome: FALSE");
    }
    else
    {
        printf("\nIsPalindrome: TRUE");
    }

    char* result = NULL;

    // Notice we have double characters and double space !
    char sequence[K100BYTES] = {"Brraideen Joohnn  Goolee"};
    int lengthOfSequence = strlen(sequence);
    result = removeDuplicateLetters(sequence, lengthOfSequence);
    printf("\nRemove duplicate letters: %s", result);

    long numberToReverse = 11119999;
    numberToReverse = reverseNumber(numberToReverse);
    printf("\nNumber in reverse: %ld", numberToReverse);
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   removeDuplicates
 *  DESCRIPTION     :   This function will remove duplicates numbers from the sorted array.
 *  PARAMETERS      :   sortedArray, size
 *  RETURNS         :   None
 */
int* removeDuplicates(int* sortedArray, int* size)
{   
    int* newArray = NULL;
    newArray = (int*)malloc(sizeof(int) * *size);
    if (newArray __EQ__ NULL)
    {
        return NULL;
    }

    int notDuplicate = ZERO;
    int nums;
    for (nums = ZERO; nums __LSS__ *size; nums++)
    {
        if (sortedArray[nums] __NEQ__ sortedArray[nums + ONE])
        {
            newArray[notDuplicate] = sortedArray[nums];
            ++notDuplicate;
        }
    }
    *size = notDuplicate;
    return newArray;
}

/**     -- Function header comment
 *  FUNCTION        :   isPalindrome
 *  DESCRIPTION     :   This function tests to see if a string is a palindrome
 *                      string.
 *  PARAMETERS      :   input, length
 *  RETURNS         :   None
 */
const bool isPalindrome(char* input, const int length)
{   
    int temp = ZERO;
    int start = ZERO;
    int end = length - ONE;

    char* newInput = (char*)malloc(sizeof(char) * length);
    if (newInput __EQ__ NULL)
    {
        return false;
    }

    // Saving a copy to compare.
    strcpy(newInput, input);

    while (start __LSS__ end)
    {
        SWAP(temp, input[start], input[end]);
        --end;
        ++start;
    }
    
    if ((strcmp(newInput, input)) == ZERO)
    {
        return true;
    }
    return false;
}

/**     -- Function header comment
 *  FUNCTION        :   removeDuplicateLetters
 *  DESCRIPTION     :   This will remove all duplicate letters from a string.
 *  PARAMETERS      :   input, length
 *  RETURNS         :   input
 */
char* removeDuplicateLetters(char* input, const int length)
{
    for (int character = 0; character < length; character++)
    {
        for (int characterAhead = character + ONE; characterAhead < length; characterAhead++)
        {
            if (input[characterAhead] == input[character])
            {
                for (int letters = characterAhead; input[letters] __NEQ__ '\0'; letters++)
                {
                    input[letters] = input[letters + ONE];
                }
            }
        }
    }
    return input;
}

/**     -- Function header comment
 *  FUNCTION        :   reverseNumber
 *  DESCRIPTION     :   This function will reverse a number.
 *  PARAMETERS      :   number
 *  RETURNS         :   None
 */
long reverseNumber(long number)
{   
    long reverse = ZERO;
    int leftOver = ZERO;
    while (number __NEQ__ ZERO)
    {
        leftOver = number % TEN;
        reverse = (reverse * TEN) + leftOver;
        number DIV TEN;
    }
    return reverse;
}