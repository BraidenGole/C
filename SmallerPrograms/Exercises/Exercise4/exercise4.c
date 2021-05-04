/**
 * @file exercise4.c
 * @author Braiden Gole
 * @brief Difficulty: easy.
 * @version 0.1
 * @date 2021-05-04
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ASCIILENGTH 255

// Function prototypes.
char* trim(char* input);
const char* reverseName(char* name, int length);
struct Freq* highestLetterFrequency(char* inputLine);
int simpleWordCount(char* fileName);

struct Freq
{
    int character;
    int times;
};

int main(void)
{
    printf("Trimmed input: %s\n", trim("  Braid en"));

    char nameOfPerson[100] = {"Braiden"};
    int lengthOfName = strlen(nameOfPerson);
    
    printf("Reverse name/word: %s", reverseName(nameOfPerson, lengthOfName));

    struct Freq* temp = NULL;
    temp = highestLetterFrequency("Brrraideen");

    printf("\nThe highest frequency character [%c] appeared [%i] times.\n", temp->character, temp->times);

    char* nameOfFile = "input.txt";
    printf("The total word count is %i", simpleWordCount(nameOfFile));
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   trim
 *  DESCRIPTION     :   This will trim all spaces from the input.
 *  PARAMETERS      :   input
 *  RETURNS         :   newInput
 */
char* trim(char* input)
{   
    char* newInput = NULL;
    newInput = (char*)malloc(sizeof(char) * 100);
    if (newInput == NULL)
    {
        return NULL;
    }

    int addLetters = 0;
    for (int letters = 0; letters < strlen(input); letters++)
    {
        if ((isspace(input[letters])) == 0)
        {
            newInput[addLetters] = input[letters];
            ++addLetters;
        }
    }
    return newInput;
}

/**     -- Function header comment
 *  FUNCTION        :   reverseName
 *  DESCRIPTION     :   This function will reverse a word/name using 
 *                      pointers to point at the starting and ending points of
 *                      the word or name that exists.
 *  PARAMETERS      :   name, length
 *  RETURNS         :   name
 */
const char* reverseName(char* name, int length)
{
    char* start = NULL;
    char* end = NULL;

    start = &name[0];
    end = &name[length - 1];

    int letters = 0;

    char temp = ' ';
    while (letters < length / 2)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        
        ++start;
        --end;
        
        ++letters;
    }
    return name;
}

/**     -- Function header comment
 *  FUNCTION        :   highestLetterFrequency
 *  DESCRIPTION     :   This function will determine which character in the
 *                      input line is the most frequently occurring.
 *  PARAMETERS      :   inputLine
 *  RETURNS         :   frequency
 */
struct Freq* highestLetterFrequency(char* inputLine)
{
    int letters = 0;
    int length = strlen(inputLine);

    int frequencies[ASCIILENGTH] = { 0 };
    int asciiValue = 0;

    struct Freq* frequency = NULL;
    frequency = (struct Freq*)malloc(sizeof(struct Freq));
    if (frequency == NULL)
    {
        return NULL;
    }

    while (letters < length)
    {
        asciiValue = (int)inputLine[letters];
        frequencies[asciiValue] += 1;
        ++letters;
    }

    int maxTimes = frequencies[1];
    int highestFrequencyCharacter = 0;
    for (int nums = 0; nums < ASCIILENGTH; nums++)
    {
        if (frequencies[nums] > maxTimes)
        {   
            highestFrequencyCharacter = nums;
            maxTimes = frequencies[nums];

            frequency->character = highestFrequencyCharacter;
            frequency->times = maxTimes;
        }
    }
    return frequency;
}

/**     -- Function header comment
 *  FUNCTION        :   simpleWordCount
 *  DESCRIPTION     :   This function will count the words in a file, this function
 *                      starts counting from 0.
 *  PARAMETERS      :   fileName
 *  RETURNS         :   totalWordCount
 */ 
int simpleWordCount(char* fileName)
{   
    FILE* fileptr = NULL;
    fileptr = fopen(fileName, "r");
    if (fileptr == NULL)
    {
        return -1;
    }
    
    char letters = 0;
    int totalWordCount = 0;
    while ((letters = fgetc(fileptr)) != EOF)
    {   
        if ((isspace(letters)) != 0)
        {
            ++totalWordCount;
        }
    }
    if ((fclose(fileptr)) == EOF)
    {   
        return -1;
    }
    return totalWordCount;
}