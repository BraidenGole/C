/**
 *  FILE            :   doublyList.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-08-16
 *  DESCRIPTION     :   This file is used to write the functionality of the doubly linked list.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Header files.
#include "doublyList.h"

// Function prototypes.
void removeNewLine(char* psStrWithNewLine);

/**
 *  FUNCTION        :   create
 *  DESCRIPTION     :   This function will create the entry for the
 *                      gamer tag.
 *  PARAMETERS      :   ppHead, ppTail
 *  RETURNS         :   ppHead
 */
const bool create(struct GamerTag** ppHead, struct GamerTag** ppTail) 
{   
    struct GamerTag* pNewTag = NULL;
    pNewTag = (struct GamerTag*)malloc(sizeof(struct GamerTag));
    if (pNewTag == NULL) 
    { 
        return false;
    }

    // Collect the new tag name.
    getchar();
    printf("\n\tGamer Tag: ");
    fgets(pNewTag->arsTagName, KMAXTAGLENGTH, stdin);
    removeNewLine(pNewTag->arsTagName);

    // End the entry.
    pNewTag->pPrev = pNewTag->pNext = NULL;

    // Check the GamerTag list to see if it contains any gamer tags.
    if (*ppHead == NULL) 
    {
        *ppHead = *ppTail = pNewTag;
        return true;
    }
    else if ((strcmp((*ppHead)->arsTagName, pNewTag->arsTagName)) >= 0)
    {
        pNewTag->pNext = *ppHead;
        (*ppHead)->pPrev = pNewTag;
        *ppHead = pNewTag;
        return true;
    }

    struct GamerTag* pLastTag = NULL;
    struct GamerTag* pNextTag = NULL;

    pLastTag = *ppHead;
    pNextTag = (*ppHead)->pNext;

    while (pNextTag != NULL)
    {
        if ((strcmp(pNextTag->arsTagName, pNewTag->arsTagName)) >= 0) 
        {
            break;
        }
        pLastTag = pNextTag;
        pNextTag = pNextTag->pNext;
    }

    pNewTag->pPrev = pLastTag;
    pNewTag->pNext = pNextTag;
    pLastTag->pNext = pNewTag;

    if (pNextTag == NULL) 
    { 
        *ppTail = pNewTag;
    }
    else 
    { 
        pNextTag->pPrev = pNewTag;
    }
    return true;
}

/**
 *  FUNCTION        :   delete
 *  DESCRIPTION     :   This method will delete a single entry. If there happens to be multiple duplicate
 *                      entries this function will delete every duplicate entry when a single user has been
 *                      deleted.
 *  PARAMETERS      :   pHead, pTail, psTagToDelete
 *  RETURNS         :   psTagToDelete
 */
void delete(struct GamerTag** ppHead, struct GamerTag** ppTail, char* psTagToDelete)
{   
    struct GamerTag* pThisTag = NULL;

    pThisTag = *ppHead;

    while (pThisTag != NULL)
    {   
        // Does the gamer tag exists within the system ?
        if ((strcmp(pThisTag->arsTagName, psTagToDelete)) == 0) 
        {
            if ((pThisTag == *ppHead) && (pThisTag == *ppTail))
            {
                *ppHead = NULL;
                *ppTail = NULL;
                free(pThisTag);
                return;
            }
            
            if (pThisTag == *ppHead)
            {   
                struct GamerTag* pSecondTag = pThisTag->pNext;
                *ppHead = pThisTag->pNext;
                pSecondTag->pPrev = NULL;
            }
            else
            {
                if (pThisTag == *ppTail)
                {
                    struct GamerTag* pSecondLastTag = pThisTag->pPrev;
                    *ppTail = pThisTag->pPrev;
                    pSecondLastTag->pNext = NULL;
                }
                else
                {
                    struct GamerTag* pBefore = pThisTag->pPrev;
                    struct GamerTag* pAfter = pThisTag->pNext;

                    pAfter->pPrev = pBefore;
                    pBefore->pNext = pAfter;
                }
            }
            free(pThisTag);
            return;
        }
        pThisTag = pThisTag->pNext;
    }
    return;
}


/**
 *  FUNCTION        :   showTags
 *  DESCRIPTION     :   This function will output all of the registered gamer tags.
 *  PARAMETERS      :   pHead
 *  RETURNS         :   None
 */
void showTags(struct GamerTag* pHead) 
{   
    struct GamerTag* pTagRef = NULL;
    pTagRef = pHead;
    
    printf("\n");
    while (pTagRef != NULL) 
    {   
        printf("\t%s\n", pTagRef->arsTagName);
        pTagRef = pTagRef->pNext;
    }
}

/**
 *  FUNCTION        :   showTagsInReverseOrder
 *  DESCRIPTION     :   This function will display the tags in reverse order.
 *  PARAMETERS      :   pTail
 *  RETURNS         :   None
 */
void showTagsInReverseOrder(struct GamerTag* pTail)
{
    struct GamerTag* pTagRef = NULL;
    pTagRef = pTail;

    printf("\n");
    while (pTagRef != NULL) 
    {
        printf("\t%s\n", pTagRef->arsTagName);
        pTagRef = pTagRef->pPrev;
    }
}

/**
 *  FUNCTION        :   removeNewLine
 *  DESCRIPTION     :   This function will remove the new line that
 *                      gets appened after input from the console.
 *  PARAMETERS      :   psStrWithNewLine
 *  RETURNS         :   None
 */
void removeNewLine(char* psStrWithNewLine)
{
    char* psFindTheNewLine = strchr(psStrWithNewLine, '\n');
    if (psFindTheNewLine != NULL) 
    { 
        *psFindTheNewLine = '\0';
    }
}

/**
 *  FUNCTION        :   freeDynamicMem
 *  DESCRIPTION     :   This function will free all of the doubly linked
 *                      list entries.
 *  PARAMETERS      :   ppHead
 *  RETURNS         :   None
 */
void freeDynamicMem(struct GamerTag* pHead) 
{
    struct GamerTag* pThisGameTag = NULL;
    struct GamerTag* pNextGameTag = NULL;

    pThisGameTag = pHead;
    
    while (pThisGameTag != NULL)
    {
        pNextGameTag = pThisGameTag->pNext;
        free(pThisGameTag);
        pThisGameTag = pNextGameTag;
    }
}

