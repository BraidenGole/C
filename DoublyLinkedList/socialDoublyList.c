/**
 *  FILE            :   socialDoublyList.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-06
 *  DESCRIPTION     :   This file will hold the bulk of the functionality
 *                      that is required to run the doubly-linked list
 *                      filled of social media posts.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Header file.
#include "socialDoublyList.h"

// Function prototypes.
void socialPostDataCollection(struct SocialPost* pNewSocialPost);

/**     -- Function header comment
 *  FUNCTION        :   pCreateAStatusUpdate
 *  DESCRIPTION     :   This function will create a new social
 *                      media post.
 *  PARAMETERS      :   pHeadOfPosts, pTailEndOfPosts
 *  RETURNS         :   pHeadOfPosts
 */
struct SocialPost* pCreateAStatusUpdate(struct SocialPost* pHeadOfPosts,
struct SocialPost* pTailEndOfPosts)
{
    struct SocialPost* pNewStatusUpdate = NULL;
    pNewStatusUpdate = (struct SocialPost*)malloc(sizeof(struct SocialPost));
    if (pNewStatusUpdate == NULL)
    {
        pHeadOfPosts = pNewStatusUpdate;
        return pHeadOfPosts;
    }
    else
    {
        // We have memory for a new social media posting.
        socialPostDataCollection(pNewStatusUpdate);

        // Are there any entries in the system currently ?
        if (pHeadOfPosts == NULL)
        {   
            pHeadOfPosts = pNewStatusUpdate;
            return pHeadOfPosts;
        }
        else if ((strcmp(pHeadOfPosts->psAuthorsFirstName,
        pNewStatusUpdate->psAuthorsFirstName)) >= 0)
        {
            pNewStatusUpdate->pNextPost = pHeadOfPosts;
            pHeadOfPosts->pPreviousPost = pNewStatusUpdate;
            pHeadOfPosts = pNewStatusUpdate;
        }
        else
        {
            struct SocialPost* pPreviousSocialPost = NULL;
            struct SocialPost* pNextSocialPost = NULL;

            // Assign the first previous and next elements before starting.
            pPreviousSocialPost = pHeadOfPosts;
            pNextSocialPost = pHeadOfPosts->pNextPost;

            while (pNextSocialPost != NULL)
            {   
                // Compare the first entry with the one we are currently
                // writing to.
                if ((strcmp(pNextSocialPost->psAuthorsFirstName,
                pNewStatusUpdate->psAuthorsFirstName)) >= 0) 
                {
                    break; 
                }

                // As we are passing through the entries, record the
                // previous and then push to the next field.
                pPreviousSocialPost = pNextSocialPost;
                pNextSocialPost = pNextSocialPost->pNextPost;
            }
            // Assign the previous entry to the previous struct to keep track.
            // Then assign the next entry to the next struct to keep track.
            // Finally give the next post more space.
            pNewStatusUpdate->pPreviousPost = pPreviousSocialPost;
            pNewStatusUpdate->pNextPost = pNextSocialPost;
            pPreviousSocialPost->pNextPost = pNewStatusUpdate;
            
            // Sanity check to see if we are at the end/tail, if so insert at tail.
            if (pNextSocialPost == NULL) { pTailEndOfPosts = pNewStatusUpdate; }
            else { pNextSocialPost->pPreviousPost = pNewStatusUpdate; }
        }
    }
    return pHeadOfPosts;
}

/**     -- Function header comment
 *  FUNCTION        :   socialPostDataCollection
 *  DESCRIPTION     :   This function will allow the user/developer
 *                      to enter in the social media post details.
 *  PARAMETERS      :   pNewSocialPost
 *  RETURNS         :   None
 */
void socialPostDataCollection(struct SocialPost* pNewSocialPost)
{
    // Allocate the social post structure fields to then be written in.
    pNewSocialPost->psAuthorsFirstName = (char*)malloc(K100BYTES);
    pNewSocialPost->psAuthorsLastName = (char*)malloc(K100BYTES);
    pNewSocialPost->psTitleOfPost = (char*)malloc(K100BYTES);
    pNewSocialPost->psMessageBody = (char*)malloc(K1200BYTES);
    pNewSocialPost->psDateOfSubmission = (char*)malloc(K100BYTES);
    
    if (pNewSocialPost->psAuthorsFirstName == NULL) { exit(1); }
    if (pNewSocialPost->psAuthorsLastName == NULL) { exit(1); }
    if (pNewSocialPost->psTitleOfPost == NULL) { exit(1); }
    if (pNewSocialPost->psMessageBody == NULL) { exit(1); }
    if (pNewSocialPost->psDateOfSubmission == NULL) { exit(1); }
    // End system check.

    printf(KENTRYHEADER);

    printf(KPROMPT_FOR_FIRSTNAME);
    fgets(pNewSocialPost->psAuthorsFirstName, K100BYTES, stdin);
    destroyNewLineCharacter(pNewSocialPost->psAuthorsFirstName);

    printf(KPROMPT_FOR_LASTNAME);
    fgets(pNewSocialPost->psAuthorsLastName, K100BYTES, stdin);
    destroyNewLineCharacter(pNewSocialPost->psAuthorsLastName);

    printf(KPROMPT_FOR_TITLE);
    fgets(pNewSocialPost->psTitleOfPost, K100BYTES, stdin);
    destroyNewLineCharacter(pNewSocialPost->psTitleOfPost);

    printf(KPROMPT_FOR_MESSAGEBODY);
    fgets(pNewSocialPost->psMessageBody, K1200BYTES, stdin);
    destroyNewLineCharacter(pNewSocialPost->psMessageBody);

    // Collect the date of the post.
    time_t date;
    time(&date);

    struct tm* dateData;
    dateData = localtime(&date);

    const int kiOneThousandNineHundred = 1900;
    sprintf(pNewSocialPost->psDateOfSubmission, "%i/%.2i/%.2i",
    dateData->tm_year + kiOneThousandNineHundred, dateData->tm_mon + 1,
    dateData->tm_mday);
    // End date collection.

    pNewSocialPost->pPreviousPost = pNewSocialPost->pNextPost = NULL;
}