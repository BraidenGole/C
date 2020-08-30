/**
 *  FILE            :   doublyList.h
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-08-16
 *  DESCRIPTION     :   This is our header file to hold all of our function prototypes and
 *                      other data necessary for our program.
 */
#ifndef _KDOUBLYLIST
#define _KDOUBLYLIST "doublyList.h"

// Global string constants.

// Global numeric constants.
#define KMAXTAGLENGTH 100

struct GamerTag {
    char arsTagName[KMAXTAGLENGTH];
    struct GamerTag* pPrev;
    struct GamerTag* pNext;
};

// Function prototypes.
const bool create(struct GamerTag** ppHead, struct GamerTag** ppTail);
void delete(struct GamerTag** ppHead, struct GamerTag** ppTail, char* psTagToDelete);
void showTags(struct GamerTag* pHead);
void showTagsInReverseOrder(struct GamerTag* ppTail);
void removeNewLine(char* psStrWithNewLine);
void freeDynamicMem(struct GamerTag* ppHead);
#endif