/**
 *  FILE            :   linkedList.h
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-03-09
 *  DESCRIPTION     :   This contains our structure that we will work
 *                      with throughout the linked-list.
 */
#ifndef _KLINKED_LIST
#define _KLINKED_LIST "linkedList.h"

// Global string constants.
#define KINTRODUCTION "\n  (Users linked-list): Ouput to console = 'x'\n \
 -------------------------------------------\n"
#define KPROMPT_FOR_NAME "\n\tPlease enter in your name: "
#define KPROMPT_FOR_LASTNAME "\tPlease enter in your last name: "
#define KPROMPT_FOR_EMAIL "\tPlease enter in your email: "
#define KPROMPT_FOR_PHONENUMBER "\tPlease enter in your phone number: "
#define KINVALID_USER_INPUT "\n\t[ Invalid user input ! ]\n"

// Global numeric constants.
#define KINPUT_LIMIT 51
#define KONEHUNDRED 100

// This is our user object that is being represented.
struct User
{
    char* psName;
    char* psLastName;
    char* psEmail;

    struct User* pNext;
};

// Function prototypes.
struct User* pCreateUser(struct User* pHeadOfUsers, int* piStatusTermination);
#endif