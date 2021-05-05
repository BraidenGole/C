/**
 * @file exercise5.c
 * @author Braiden Gole
 * @brief Difficulty: easy.
 * @version 0.1
 * @date 2021-05-05
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define K100BYTES 100
#define SIX 6

// Function prototypes.
int searchForMatch(char* pattern, char* text);
void printArrayInReverse(int* array, int size);
void copy(char* destination, char* source);
int len(char* input);

int main(void)
{
    char pattern[K100BYTES] = {"XYZ"};
    char text[K100BYTES] = {"XXXZZYXXYYYXXYZXXZZY"};

    printf("A match has been found at: %i\n", searchForMatch(pattern, text));

    int numbers[SIX] = { 1, 2, 3, 4, 5, 6 };
    printArrayInReverse(numbers, SIX);

    char input[K100BYTES] = {"Braiden"};
    char result[K100BYTES] = {""};

    copy(result, input);
    printf("\nThe contents have been copied to the `result` variable: %s", result);

    char test[K100BYTES] = {"Braiden"};
    printf("\nThe length of the word is: %i", len(test));
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   searchForMatch
 *  DESCRIPTION     :   This function is a demonstration on how to move a pattern until a match.
 *  PARAMETERS      :   pattern, text
 *  RETURNS         :   position
 */
int searchForMatch(char* pattern, char* text)
{
    int lengthOfPattern = strlen(pattern);
    int lengthOfText = strlen(text);

    int shift = 0;
    for (int position = 0; position <= lengthOfText - lengthOfPattern; position++)
    {
        while (shift < lengthOfPattern)
        {
            if (text[position + shift] != pattern[shift])
            {
                break;
            }
            ++shift;
        }

        if (shift == lengthOfPattern)
        {
            return position;
        }
    }
    return -1;
}


/**     -- Function header comment
 *  FUNCTION        :   printArrayInReverse
 *  DESCRIPTION     :   This function will print the array in reverse using
 *                      pointers.
 *  PARAMETERS      :   array, size
 *  RETURNS         :   None
 */
void printArrayInReverse(int* array, int size)
{   
    int* numbers = NULL;
    numbers = &array[size - 1];
    for (int reverse = size; reverse > 0; reverse--)
    {
        printf("%i ", *numbers);
        numbers--;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   copy
 *  DESCRIPTION     :   This will copy the contents of one string to another using pointers.
 *  PARAMETERS      :   destination, source
 *  RETURNS         :   destination
 */
void copy(char* destination, char* source)
{
    while (*source)
    {
        *destination = *source;
        ++source;
        ++destination;
    }
    *destination = '\0';
}

/**     -- Function header comment
 *  FUNCTION        :   len
 *  DESCRIPTION     :   This will calculate the length of a string using pointers.
 *  PARAMETERS      :   input
 *  RETURNS         :   length
 */
int len(char* input)
{
    int length = 0;
    while (*input != '\0')
    {
        ++input;
        ++length;
    }
    return length;
}