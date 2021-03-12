/**
 * @file stringFunctions.h
 * @author Braiden Gole
 * @brief This is a sample on string manipulation in the C programming language.
 * @version 0.1
 * @date 2021-03-12
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef STRINGFUNCTIONS
#define STRINGFUNCTIONS "stringFunctions.h"
#define K100BYTES 100
#define ZERO 0
#define ONE 1
#define CODESIZE 4

#define __LSS__ <
#define  __EQ__ ==
#define __NEQ__ !=

// Function prototypes.
const int countNumberOfWordsInLine(char* line);
const int countOccurrencesOfCharacter(char* input, const char character);
void filterCodes(char* codes[CODESIZE], const int size);
void forKeysInInput(char* input, char* keys);
#endif