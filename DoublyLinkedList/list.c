/**
 *  FILE            :   list.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-08-16
 *  DESCRIPTION     :   This is an implementation of a doubly linked list algorithm.
 *                      This list is intends to be filled with gamer tags as example data.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Header files.
#include "doublyList.h"

int main(void) {

    struct GamerTag* pHead = NULL;
    struct GamerTag* pTail = NULL;

    int iSelection = 0;
    char arsDeleteValue[KMAXTAGLENGTH] = { 0 };

    bool bKeepFilling = true;
    while (bKeepFilling)
    {
        printf("\n\t-- Menu --\n");
        printf("\t1. Create tag.\n");
        printf("\t2. Delete tag.\n");
        printf("\t3. Show tags.\n");
        printf("\t4. Show tags in reverse order.\n");
        printf("\t5. Quit\n\n");

        printf("\tChoose a number: ");
        if ((fscanf(stdin, "%i", &iSelection)) == 0) 
        {
            fprintf(stderr, "\n\tNo characters !\n");
            fflush(stdin);
        }

        // Compare the selection against an operation.
        switch (iSelection) 
        {
            case 1:
                // If we ran out of memory end the program.
                if ((create(&pHead, &pTail)) == false) 
                { 
                    return -1;
                }
                break;
            case 2:
                // Output a list of all of the tags so the user can choose a tag to delete.
                showTags(pHead);
                getchar();
                printf("\n\tEnter in the tag to delete: ");
                fgets(arsDeleteValue, KMAXTAGLENGTH, stdin);
                removeNewLine(arsDeleteValue);

                // Send the value to delete into the delete function and display the value deleted !
                delete(&pHead, &pTail, arsDeleteValue);
                break;
            case 3:
                showTags(pHead);
                break;
            case 4:
                showTagsInReverseOrder(pTail);
                break;
            case 5:
                // Free the dynamic memory before quiting the program.
                freeDynamicMem(pHead);
                bKeepFilling = false;
        }
    }    
    return 0;
}
