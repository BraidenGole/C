/**
 *  FILE            :   main.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-03-09
 *  DESCRIPTION     :   This is the implementation of a linked list.
 */
#include <stdio.h>
#include <stdlib.h>

// Header file.
#include "linkedList.h"

// Local function prototypes.
void outputUsersToConsole(struct User* pUsersToOutput);
void freeTheHeap(struct User* pUsersToFree);

int main(void)
{
    // Create a head pointer that points to User.
    struct User* pHead = NULL;

    // Introduction message.
    printf(KINTRODUCTION);

    int iProgramTermination = 0;
    while (iProgramTermination == 0)
    {
        pHead = pCreateUser(pHead, &iProgramTermination);
    }

    // Output the linked-list to the console.
    outputUsersToConsole(pHead);

    // Free all of the dynamically allocated memory.
    freeTheHeap(pHead);
    return 0;
}

/**
 *  FUNCTION        :   outputUsersToConsole
 *  DESCRIPTION     :   This will output all of the users
 *                      in the linked-list to the console window.
 *  PARAMETERS      :   pUsersToOutput
 *  RETURNS         :   None
 */
void outputUsersToConsole(struct User* pUsersToOutput)
{   
    struct User* pOutputToConsole = NULL;
    pOutputToConsole = pUsersToOutput;

    printf("===========================================================\n");
    printf("  [ Registered Users ]\n\n");
    while (pOutputToConsole != NULL)
    {
        printf("\tName            :   %s\n", pOutputToConsole->psName);
        printf("\tLast name       :   %s\n", pOutputToConsole->psLastName);
        printf("\tEmail           :   %s\n\n", pOutputToConsole->psEmail);
        pOutputToConsole = pOutputToConsole->pNext;
    }
    printf("===========================================================\n");
}

/**
 *  FUNCTION        :   freeTheHeap
 *  DESCRIPTION     :   This frees up every instance of
 *                      dynamically allocated memory within the program.
 *  PARAMETERS      :   pUsersToFree
 *  RETURNS         :   None
 */
void freeTheHeap(struct User* pUsersToFree)
{
    struct User* pCurrentUser = NULL;
    struct User* pNextUser = NULL;

    pCurrentUser = pUsersToFree;
    while (pCurrentUser != NULL)
    {
        pNextUser = pCurrentUser->pNext;
        free(pCurrentUser);
        pCurrentUser = pNextUser;
    }
}