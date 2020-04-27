/**
 *  FILE            :   reverseName.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-26
 *  DESCRIPTION     :   This program will reverse a name using pointers.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Global string constants.
#define KPROMPT_FOR_NAME "Enter in a name: "

// Global numeric constants.
#define KNAMELIMIT 51

// Function prototypes.
void switchCharacters(char* cSource, char* cDestination);

int main(void)
{   
    // Get the name from the user.
    char arsNameOfUser[KNAMELIMIT] = {""};
    char* psInput = NULL;
    do
    {
        printf(KPROMPT_FOR_NAME);
        psInput = fgets(arsNameOfUser, KNAMELIMIT, stdin);
    } while (((isdigit(*psInput)) > 0) || ((ispunct(*psInput)) != 0));

    // Gather the length of the name.
    const int kiLengthOfName = strlen(arsNameOfUser) - 2;

    int iStart = 0;
    int iEnd = kiLengthOfName;
    
    while (iStart < iEnd)
    {   
        switchCharacters(&arsNameOfUser[iStart], &arsNameOfUser[iEnd]);
        --iEnd;
        ++iStart;
    }

    // Output the reveresed name to the console.
    printf("%s", arsNameOfUser);
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   switchCharacters
 *  DESCRIPTION     :   This function will swap characters
 *                      when called.
 *  PARAMETERS      :   cSource, cDestination
 *  RETURNS         :   None
 */
void switchCharacters(char* cSource, char* cDestination)
{
    int cTemp = *cSource;
    *cSource = *cDestination;
    *cDestination = cTemp;
}