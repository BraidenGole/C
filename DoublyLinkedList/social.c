/**
 *  FILE            :   social.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-06
 *  DESCRIPTION     :   This is the implementation of a doubly-linked list
 *                      which holds records of a social media post.
 *                      
 *      NOTE: The operator should understand that the program has
 *            the capabilities to add/insert new entries which MUST be
 *            done first before any deleting goes on. The program will allow
 *            you to create one set of users and delete them as well as the
 *            capability of searching for a user in-between that but once
 *            all the users have deleted you will not be able to create anymore.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Header file.
#include "socialDoublyList.h"

int main(void)
{   
    // Create the head of SocialPost.
    struct SocialPost* pSocialhead = NULL;

    // Create the tail end of SocialPost.
    struct SocialPost* pTailEnd = NULL;

    // A variable to hold the name to search for.
    char* psNameToSearchFor = NULL;
    psNameToSearchFor = (char*)malloc(K100BYTES);

    // Do we have enough memory to allocate for the name to search for ?
    if (psNameToSearchFor == NULL) { return 1; }

    int iSelection = 0;
    bool bSocialMenuCondition = true;
    while (bSocialMenuCondition)
    {   
        // Recursive initialization.
        iSelection = 0;

        // -- Menu of operations -- //
        printf(KSOCIALMENUHEADER);
        printf(KSELECTION1);
        printf(KSELECTION2);
        printf(KSELECTION3);
        printf(KSELECTION4);
        printf(KSELECTION5);

        printf(KPROMPT_FOR_SELECTION);
        if ((fscanf(stdin, "%i", &iSelection)) == 0) { fflush(stdin); }
        const char kcReadInNewLine = getchar();

        // Check the selection made and associate it with the proper action.
        switch (iSelection)
        {   
            // Create a social media post.
            case 1:
                pSocialhead = pCreateAStatusUpdate(pSocialhead, pTailEnd);
                break;

            // Search for a existing post within the system.
            case 2:
                // Prompt the user for the name to search for.
                printf(KPROMPT_FOR_SEARCH);
                fgets(psNameToSearchFor, K100BYTES, stdin);
                if ((searchForStatusUpdate(pSocialhead, psNameToSearchFor)) == 1)
                {
                    printf(KNOTFOUND);
                }
                else { printf(KFOUND); }
                break;

            // Output all social media post to the console window.
            case 3:
                displayAllPosts(pSocialhead);
                break;

            // Delete an existing post in the system.
            case 4:
                // Prompt the user for the name associated with a post that we want to delete.
                printf(KPROMPT_FOR_DELETION);
                fgets(psNameToSearchFor, K100BYTES, stdin);
                if ((deleteAStatusUpdate(pSocialhead, pTailEnd, psNameToSearchFor)) == 1)
                {
                    printf(KPOST_NOT_DELETED);
                }
                else { printf(KPOST_IS_DELETED); }
                break;

            // Program termination.
            case 5:
                bSocialMenuCondition = false;
                break;
        }
    }
    // Free system resources.
    freeUpSystemResources(pSocialhead);
    return 0;
}