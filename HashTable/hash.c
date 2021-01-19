/**
 *  FILE            :   hash.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-12
 *  DESCRIPTION     :   This is the implementation of a hash table algorithm
 *                      and we will be dealing with collisions using the
 *                      wrap around method.
 */
#include <stdio.h>
#include <string.h>

// Header file.
#include "hashTable.h"

// Function prototype.
void clearNewLineDelimiter(char* psInputWithNewline);

int main(void)
{
    struct NamesOfPeople* arspHashTable[KTABLELIMIT];
    initializeHashTable(arspHashTable);

    int iHashValue = 0;
    int iReturnValue = 0;
    char arsBuffer[K50BYTES] = {""};

    printf("\n\tKeep entering names unitl loop stops !\n%s", 
    "\t--------------------------------------\n\n");
    do
    {
        printf(KPROMPT_FOR_NAME);
        fgets(arsBuffer, K50BYTES, stdin);
        clearNewLineDelimiter(arsBuffer);

        iHashValue = iTheHashFunction(arsBuffer);
        iReturnValue = iInsertPeoplesNames(arspHashTable, arsBuffer, iHashValue);

        // If we ran out of system resources.
        if (iReturnValue == 2) 
        { 
            return 2;
        }
    } while (iReturnValue != 1);

    showTheTableOfNames(arspHashTable);

    char arsLookupName[K50BYTES] = {""};
    printf(KPROMPT_FOR_LOOKUPNAME);
    fgets(arsLookupName, K50BYTES, stdin);

    if ((iHashTableLookup(arspHashTable, arsLookupName)) == 1)
    {
        printf("\n\t[ The name was not found in the system. ]\n");
    }
    else 
    { 
        printf("\n\t[ The name exists ! ]\n");
    }

    char arsNameToDelete[K50BYTES] = {""};
    printf(KPROMPT_FOR_NAMETODELETE);
    fgets(arsNameToDelete, K50BYTES, stdin);

    if ((iDeleteAPersonsName(arspHashTable, arsNameToDelete)) == 1)
    {
        printf("\n\t[ The name does not exist ! ]\n");
    }
    else 
    {   
        showTheTableOfNames(arspHashTable);
        printf("\n\t>>> DELETED: %s", arsNameToDelete); 
    }
    clearTheNames(arspHashTable);
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   clearNewLineDelimiter
 *  DESCRIPTION     :   This function will take in the input with a
 *                      new-line appended/inserted to the end of input
 *                      for a input function call to fgets.
 *  PARAMETERS      :   psInputWithNewLine
 *  RETURNS         :   None
 */
void clearNewLineDelimiter(char* psInputWithNewline)
{
    char* psFindTheNewLine = strchr(psInputWithNewline, '\n');
    if (psFindTheNewLine != NULL) 
    { 
        psFindTheNewLine = NULL;
    }
}
