/**
 *  FILE            :   miscellaneous.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-06
 *  DESCRIPTION     :   This file is used to help with the flow of data in
 *                      our program. In addition to this the file will contain
 *                      extra methods that aid us in the developement for
 *                      our doubly-linked list.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Header file.
#include "socialDoublyList.h"

/**     -- Function header comment
 *  FUNCTION        :   displayAllPosts
 *  DESCRIPTION     :   This function will take in the posts to display
 *                      and will print each instance to the console window.
 *  PARAMETERS      :   pPostsToDisplay
 *  RETUNRS         :   None
 */
void displayAllPosts(struct SocialPost* pPostsToDisplay)
{
    struct SocialPost* pPosts = NULL;

    printf("\n ** Social media post **\n\n");
    pPosts = pPostsToDisplay;
    while (pPosts != NULL)
    {   
        printf("\t%s", pPosts->psAuthorsFirstName);
        printf("\t%s", pPosts->psAuthorsLastName);
        printf("\t%s", pPosts->psTitleOfPost);
        printf("\t%s", pPosts->psMessageBody);
        printf("\t%s\n\n", pPosts->psDateOfSubmission);
        pPosts = pPosts->pNextPost;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   searchForStatusUpdate
 *  DESCRIPTION     :   This function will take in the head of the social
 *                      postings and will traverse the list in order to
 *                      find a potential post in the system.
 *  PARAMETERS      :   pPostsToSearchFrom, psNameToFind
 *  RETURNS         :   0, 1
 */
const int searchForStatusUpdate(struct SocialPost* pPostsToSearchFrom,
char* psNameToFind)
{
    struct SocialPost* pSearchReference = NULL;

    pSearchReference = pPostsToSearchFrom;
    while (pSearchReference != NULL)
    {
        if ((strcmp(pSearchReference->psAuthorsFirstName, psNameToFind)) == 0)
        {
            return 0;
        }
        pSearchReference = pSearchReference->pNextPost;
    }
    return 1;
}

/**     -- Function header comment
 *  FUNCTION        :   deleteAStatusUpdate
 *  DESCRIPTION     :   This will use our search function to find the name
 *                      that associates with the post we would like to
 *                      delete.
 *  PARAMETERS      :   pAllPosts, pEndOfPosts psNameAssociation
 *  RETURNS         :   0, 1
 */
const int deleteAStatusUpdate(struct SocialPost* pAllPosts, 
struct SocialPost* pEndOfPosts, char* psNameAssociation)
{
    struct SocialPost* pHead = NULL;

    pHead = pAllPosts;
    while (pHead != NULL)
    {
        // Check the system for the name associated with the post to delete.
        if ((strcmp(pHead->psAuthorsFirstName, psNameAssociation)) == 0)
        {   
            // Instead of completly deleting the entry we will just
            // reset all the fields so that they are blank.
            pHead->psAuthorsFirstName = "";
            pHead->psAuthorsLastName = "";
            pHead->psTitleOfPost = "";
            pHead->psMessageBody = "";
            pHead->psDateOfSubmission = "";

            free(psNameAssociation);
            return 0;
        }
        pHead = pHead->pNextPost;
    }
    return 1;
}

/**     -- Function header comment
 *  FUNCTION        :   freeUpSystemResources
 *  DESCRIPTION     :   This function will take in the system load to free
 *                      and will free the system of all allocated resources
 *                      before the program terminates.
 *  PARAMETERS      :   pSystemLoad
 *  RETURNS         :   None
 */
void freeUpSystemResources(struct SocialPost* pSystemLoad)
{
    struct SocialPost* pThisPost = NULL;
    struct SocialPost* pNextPost = NULL;

    pThisPost = pSystemLoad;
    while (pThisPost != NULL)
    {
        pNextPost = pThisPost->pNextPost;
        free(pThisPost);
        pThisPost = pNextPost;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   destroyNewLineCharacter
 *  DESCRIPTION     :   This function will take in the input with a new-line
 *                      character appended to the end of input.
 *  PARAMETERS      :   psInputWithNewLine
 *  RETURNS         :   None
 */
void destroyNewLineCharacter(char* psInputWithNewLine)
{
    char* psFindTheNewLine = strchr(psInputWithNewLine, '\n');
    if (psFindTheNewLine != NULL) { psFindTheNewLine = NULL; }
}