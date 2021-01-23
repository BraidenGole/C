/**
 * @file pointersExample.h
 * @author Braiden Gole
 * @brief This is our header file where we will store our constants
 *        and our function prototypes.
 * @version 0.1
 * @date 2021-01-22
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _KPOINTERSEXAMPLE
#define _KPOINTERSEXAMPLE "pointersExample.c"

#define K100BYTES 100
#define KLIMIT 10
#define VALUE 9999

struct Node
{
    char name[K100BYTES];
    struct Node* next;
};

// Function prototypes.
void showUsingPointerArithmetic(int* array, const int size);
const bool bEnterDataIntoHead(struct Node** head, const char* data);
struct Node* nEnterDataIntoHead(struct Node* head, const char* data);
void exitAfterFive(int* statusCode);
#endif