/**
 *  FILE            :   linkedList.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-03-09
 *  DESCRIPTION     :   This file holds the functionality of the linked
 *                      list.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Header file.
#include "linkedList.h"

// Local function prototypes.
int enterUserData(struct User* pHeadToWriteTo);
void removeNewLineDelimiter(char* psInputWithNewLine);

/**
 *  FUNCTION        :   pCreateUser
 *  DESCRIPTION     :   This function will create a new instance
 *                      of struct User.
 *  PARAMETERS      :   pHeadOfUsers
 *  RETURNS         :   pHeadOfUsers
 */
struct User* pCreateUser(struct User* pHeadOfUsers, int* piStatusTermination)
{   
    struct User* pNewUserBlock = NULL;
    pNewUserBlock = (struct User*)malloc(sizeof(struct User));

    // Check our system for sufficient memory.
    if (pNewUserBlock == NULL) { return pHeadOfUsers; }
    else
    {   
        // Enter in the user data.
        int iCompareReturnValue = 0;
        iCompareReturnValue = enterUserData(pNewUserBlock);

        // If enterUserData returns 2, we ran out of memory.
        if (iCompareReturnValue == 2)
        { 
            pHeadOfUsers = pNewUserBlock;
            *piStatusTermination = 2;
            return pHeadOfUsers;
        }
        // If enterUserData returns 1, user entered 'x'(termination).
        else if (iCompareReturnValue == 1)
        {
            *piStatusTermination = 1;
            return pHeadOfUsers;
        }
    
        // Link the list to the head of User.
        if (pHeadOfUsers == NULL)
        {
            pHeadOfUsers = pNewUserBlock;
            return pHeadOfUsers;
        }
        else
        {
            struct User* pReferenceHeadOfUsers = NULL;
            pReferenceHeadOfUsers = pHeadOfUsers;
            while (pReferenceHeadOfUsers->pNext != NULL)
            {
                pReferenceHeadOfUsers = pReferenceHeadOfUsers->pNext;
            }
            pReferenceHeadOfUsers->pNext = pNewUserBlock;
        }
    }
    return pHeadOfUsers;
}

/**
 *  FUNCTION        :   enterUserData
 *  DESCRIPTION     :   This function will allow the developer
 *                      to give input based on the representation of
 *                      a User object.
 *  PARAMETERS      :   pHeadToWriteTo
 *  RETURNS         :   None
 */
int enterUserData(struct User* pHeadToWriteTo)
{
    // We have memory for a new instance of type User.
    pHeadToWriteTo->psName = (char*)malloc(KINPUT_LIMIT);
    pHeadToWriteTo->psLastName = (char*)malloc(KINPUT_LIMIT);
    pHeadToWriteTo->psEmail = (char*)malloc(KINPUT_LIMIT);

    if (pHeadToWriteTo->psName == NULL) { return 2; }
    if (pHeadToWriteTo->psLastName == NULL) { return 2; }
    if (pHeadToWriteTo->psEmail == NULL) { return 2; }

    printf(KPROMPT_FOR_NAME);
    fgets(pHeadToWriteTo->psName, KINPUT_LIMIT, stdin);
    removeNewLineDelimiter(pHeadToWriteTo->psName);

    // >>> [ Program termination ]
    const char kcTerminationCharacter = 'x';
    if ((strchr(pHeadToWriteTo->psName, kcTerminationCharacter)) != NULL)
    {
        return 1;
    }

    printf(KPROMPT_FOR_LASTNAME);
    fgets(pHeadToWriteTo->psLastName, KINPUT_LIMIT, stdin);
    removeNewLineDelimiter(pHeadToWriteTo->psLastName);

    printf(KPROMPT_FOR_EMAIL);
    fgets(pHeadToWriteTo->psEmail, KINPUT_LIMIT, stdin);
    removeNewLineDelimiter(pHeadToWriteTo->psEmail);

    // End the entry once all data we need is collected.
    pHeadToWriteTo->pNext = NULL;
    return 0;
}

/**
 *  FUNCTION        :   removeNewLineDelimiter
 *  DESCRIPTION     :   This function will take in the input with
 *                      a new-line and remove it from a (C) input function.
 *  PARAMETERS      :   psInputWithNewLine
 *  RETURNS         :   None
 */
void removeNewLineDelimiter(char* psInputWithNewLine)
{   
    // Create a variable to hold the position of that character
    // to the be replaced by a (null) terminating character.
    const char kcNewLineCharacter = '\n';
    char* psFindTheNewLine = strchr(psInputWithNewLine, kcNewLineCharacter);

    // If a new-line was found replace it with null termination.
    if (psFindTheNewLine != NULL) { *psFindTheNewLine = '\0'; }
}
