/**
 *  FILE            :   stack.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-06-29
 *  DESCRIPTION     :   This is the implementation of a stack algorithm.
 */
#include <stdio.h>
#include <stdbool.h>

// Header file.
#include "stackAlgorithm.h"

// Function prototypes.
const bool bIsFull(int* piTop);
const bool bIsEmpty(int* piTop);

/**
 *  FUNCTION        :   push
 *  DESCRIPTION     :   This function will push a number into the stack.
 *  PARAMETERS      :   ariStack[], iData, piTop
 *  RETURNS         :   ariStack[piTop]
 */
const int push(int ariStack[], int iData, int* piTop)
{
    // When adding an entry we must check for fullness of the stack.
    if ((bIsFull(piTop)) == true) { return -1; }
    
    *piTop = *piTop + 1;
    ariStack[*piTop] = iData;
    return ariStack[*piTop];
}

/**
 *  FUNCTION        :   pop
 *  DESCRIPTION     :   This function will pop an number from the stack.
 *  PARAMETERS      :   piTop
 *  RETURNS         :   iDelete, 1
 */
const int pop(int ariStack[], int* piTop)
{
    if ((bIsEmpty(piTop)) == true) { return -1; }
    int iDelete = 0;

    ariStack[*piTop] = 0;
    *piTop = *piTop - 1;
    return iDelete;
}

/**
 *  FUNCTION        :   peek
 *  DESCRIPTION     :   This function will show the number at the very
 *                      top of the stack.
 *  PARAMETERS      :   ariStack, piTop
 *  RETURNS         :   ariStack[piTop]
 */
const int peek(int ariStack[], int* piTop) { return ariStack[*piTop]; }

/**
 *  FUNCTION        :   showStack
 *  DESCRIPTION     :   This function will show the stack to the console window. 
 *  PARAMETERS      :   ariStack[]
 *  RETURNS         :   None
 */
const int showStack(int ariStack[], int* piTop)
{   
    // Is the list empty ?
    if ((bIsEmpty(piTop)) == true) { return -1; }

    printf(KSTACKHEADER);
    int iNumbers = 0;
    for (iNumbers = 0; iNumbers < KSTACKSIZE; iNumbers++)
    {   
        if (ariStack[iNumbers] != 0)
        {
            printf("\t%i\n", ariStack[iNumbers]);
        }
    }
    printf("\n");
    return 0;
}

/**
 *  FUNCTION        :   bIsEmpty
 *  DESCRIPTION     :   This function checks the stack to see if it
 *                      has any entries in it.
 *  PARAMETERS      :   piTop
 *  RETURNS         :   true, false
 */
const bool bIsEmpty(int* piTop)
{
    if (*piTop == -1) { return true; }
    return false;
}

/**
 *  FUNCTION        :   bIsFull
 *  DESCRIPTION     :   This will check the stack to see if it is full.
 *  PARAMETERS      :   piTop
 *  RETURNS         :   true, false
 */
const bool bIsFull(int* piTop)
{
    if (*piTop == KSTACKSIZE - 1) { return true; }
    return false;
}