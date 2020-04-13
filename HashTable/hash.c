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
    // Declare the hash table.
    struct NamesOfPeople* arspHashTable[KTABLELIMIT];

    // Initialize every position of the hash table.
    initializeHashTable(arspHashTable);

    // Gather the hash keys to pass into the insert function.
    int iHashValue = 0;
    int iReturnValue = 0;
    char arsBuffer[K50BYTES] = {""};

    // Keep looping until the return value of the insert function is equat to 1.
    printf("\n\tKeep entering names unitl loop stops !\n%s", 
    "\t--------------------------------------\n\n");
    do
    {
        printf(KPROMPT_FOR_NAME);
        fgets(arsBuffer, K50BYTES, stdin);
        clearNewLineDelimiter(arsBuffer);

        // Throw each key into the hash function.
        iHashValue = iTheHashFunction(arsBuffer);
        iReturnValue = iInsertPeoplesNames(arspHashTable, arsBuffer, iHashValue);

        // If we ran out of system resources.
        if (iReturnValue == 2) { return 2; }
    } while (iReturnValue != 1);

    // Display peoples names to the console window.
    showTheTableOfNames(arspHashTable);

    // Prompt the user for a name to lookup.
    char arsLookupName[K50BYTES] = {""};
    printf(KPROMPT_FOR_LOOKUPNAME);
    fgets(arsLookupName, K50BYTES, stdin);

    // Send the name to lookup to the search function.
    if ((iHashTableLookup(arspHashTable, arsLookupName)) == 1)
    {
        printf("\n\t[ The name was not found in the system. ]\n");
    }
    else { printf("\n\t[ The name exists ! ]\n"); }

    // Prompt the user fop a name to delete.
    char arsNameToDelete[K50BYTES] = {""};
    printf(KPROMPT_FOR_NAMETODELETE);
    fgets(arsNameToDelete, K50BYTES, stdin);

    // Send the name to delete to the delete function.
    if ((iDeleteAPersonsName(arspHashTable, arsNameToDelete)) == 1)
    {
        printf("\n\t[ The name does not exist ! ]\n");
    }
    else 
    {   
        // Display the table one last time after a name has been deleted.
        showTheTableOfNames(arspHashTable);
        printf("\n\t>>> DELETED: %s", arsNameToDelete); 
    }
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
    if (psFindTheNewLine != NULL) { psFindTheNewLine = NULL; }
}