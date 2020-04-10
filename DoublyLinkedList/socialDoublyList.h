/**
 *  FILE            :   socialDoublyList.h
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-06
 *  DESCRIPTION     :   This file contains our object to store in our
 *                      doubly-linked list. This will represent a social media post.
 */
#ifndef _KSOCIALDOUBLYLIST
#define _KSOCIALDOUBLYLIST "socialDoublyList.h"

// Global string constants.
#define KSOCIALMENUHEADER "\n  -- Social Post --\n"
#define KSELECTION1 "\t1. Create a new social post.\n"
#define KSELECTION2 "\t2. Search for a existing post.\n"
#define KSELECTION3 "\t3. Output all of the post to the console.\n"
#define KSELECTION4 "\t4. Delete a existing post in the system.\n"
#define KSELECTION5 "\t5. End the program.\n"
#define KPROMPT_FOR_SELECTION "\n\tPlease enter in a number: "

#define KENTRYHEADER "\n -- Social Post Configuration --\n"
#define KPROMPT_FOR_FIRSTNAME "\tEnter in a first name: "
#define KPROMPT_FOR_LASTNAME "\tEnter in a last name: "
#define KPROMPT_FOR_TITLE "\tEnter in a title: "
#define KPROMPT_FOR_MESSAGEBODY "\n\t-- Message -- \n\n\t>>> "

#define KPROMPT_FOR_SEARCH "\n\t> Search by authors name: "
#define KFOUND "\n\t\t(The name entered is \"registered\" in the system.)\n"
#define KNOTFOUND "\n\t\tThe name to search was [NOT] found in the system.\n"

#define KPROMPT_FOR_DELETION "\n\t> Delete a post associated by name: "
#define KPOST_IS_DELETED "\n\t\tYour post has been DELETED !\n"
#define KPOST_NOT_DELETED "\n\t\tThis post is [NOT] \"registered\" in our system.\n"
#define KSOCIALPOSTDELTED "[ DELETED ]"

// Global numeric constants.
#define K100BYTES 101
#define K1200BYTES 1200

/* -- Social Post Object -- */
struct SocialPost
{
    char* psAuthorsFirstName;
    char* psAuthorsLastName;
    char* psTitleOfPost;
    char* psMessageBody;
    char* psDateOfSubmission;

    struct SocialPost* pNextPost;
    struct SocialPost* pPreviousPost;
};

// Function prototypes.
struct SocialPost* pCreateAStatusUpdate(struct SocialPost* pHeadOfPosts,
struct SocialPost* pTailEndOfPosts);
const int searchForStatusUpdate(struct SocialPost* pPostsToSearchFrom,
char* psNameToFind);
const int deleteAStatusUpdate(struct SocialPost* pAllPosts, 
struct SocialPost* pEndOfPosts, char* psNameAssociation);
void displayAllPosts(struct SocialPost* pPostsToDisplay);
void freeUpSystemResources(struct SocialPost* pSystemLoad);
void destroyNewLineCharacter(char* psInputWithNewLine);
#endif