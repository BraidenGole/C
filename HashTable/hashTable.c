/**
 *  FILE            :   hashTable.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-12
 *  DESCRIPTION     :   This file will be used to hold all of the
 *                      functions that are needed to work with a hash table.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Header file.
#include "hashTable.h"

/**     -- Function header comment
 *  FUNCTION        :   initializeHashTable
 *  DESCRIPTION     :   This function will take in the hash table
 *                      as a parameter and will initialize each position
 *                      will a NULL marker.
 *  PARAMETERS      :   arspHashTable[KTABLELIMIT]
 *  RETURNS         :   None
 */
void initializeHashTable(struct NamesOfPeople* arspHashTable[KTABLELIMIT])
{
    int iPositions = 0;
    while (iPositions < KTABLELIMIT)
    {
        arspHashTable[iPositions] = NULL;
        ++iPositions;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   iTheHashFunction
 *  DESCRIPTION     :   This function will take in every key
 *                      and add up the ascii values of each
 *                      key supplied then get the modulus of
 *                      the numeric value against the size of
 *                      the hash table.
 *  PARAMETERS      :   psKey
 *  RETURNS         :   iTheHashValue % KTABLELIMIT
 */
unsigned int iTheHashFunction(char* psKey)
{
    int iAmountOfCharacters = strlen(psKey);
    int iLetters = 0;

    int iTheHashValue = 0;
    while (iLetters < iAmountOfCharacters)
    {   
        iTheHashValue += psKey[iLetters];
        ++iLetters;
    }
    return iTheHashValue % KTABLELIMIT;
}

/**     -- Function header comment
 *  FUNCTION        :   iInsertPeoplesNames
 *  DESCRIPTION     :   This function will take in the name to insert
 *                      and will check to see if a position is already filled
 *                      if not it will write into the entry and assign that struct
 *                      for the calculated position.
 *  PARAMETERS      :   arspHashTable[KTABLELIMIT], psNameToInsert, kiElementPosition
 *  RETURNS         :   0, 1
 */
int iInsertPeoplesNames(struct NamesOfPeople* arspHashTable[KTABLELIMIT],
char* psNameToinsert, int iElementPosition)
{   
    // Create the temporary structure to hold the name to insert.
    struct NamesOfPeople* pHoldName = NULL;
    pHoldName = (struct NamesOfPeople*)malloc(K50BYTES);
    if (pHoldName == NULL) { return 2; }
    else
    {   
        // Loop, starting with the calculated index position.
        int iCellsVisited = 0;
        while ((arspHashTable[iElementPosition]) != NULL)
        {
            ++iElementPosition;
            ++iCellsVisited;

            // Keep going until the entire table has been search
            // then return 1 indicating that the table is full.
            if (iCellsVisited == KTABLELIMIT) { return 1; }

            // Wrap around the table in the case of a collision.
            iElementPosition %= KTABLELIMIT;
        }   

        // Once navigated to position copy the string into the proper entry.
        strcpy(pHoldName->arsName, psNameToinsert);
        arspHashTable[iElementPosition] = pHoldName;
    }
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   iHasTableLookup
 *  DESCRIPTION     :   This function will take in the hash table
 *                      full of names to then be compared against the
 *                      name to lookup.
 *  PARAMETERS      :   arsHashTable[KTABLELIMIT], psTheNameToLookup
 *  RETURNS         :   0, 1
 */
int iHashTableLookup(struct NamesOfPeople* arsHashTable[KTABLELIMIT], 
char* psTheLookupName)
{   
    int iVisitedCells = 0;
    int iIndex = iTheHashFunction(psTheLookupName);
    while (arsHashTable[iIndex] != NULL)
    {   
        // If all cells were visited and the name was not found return 1.
        if (iVisitedCells == KTABLELIMIT) { return 1; }

        // The position is to be filled and have a string matching the lookup.
        if ((arsHashTable[iIndex] != NULL) && 
        ((strcmp(arsHashTable[iIndex]->arsName, psTheLookupName)) == 0))
        {
            return 0;
        }
        ++iIndex;
        ++iVisitedCells;

        // Wrap around in case of collision when inserted.
        iIndex %= KTABLELIMIT;
    }
    return 1;
}

/**     -- Function header comment
 *  FUNCTION        :   iDeleteAPersonsName
 *  DESCRIPTION     :   This function will take in the table of names
 *                      to delete from and will perform a lookup of the
 *                      name to delete, if found we will re-initialize
 *                      that name with a NULL marker.
 *  PARAMETER       :   arspHashTable[KTABLELIMIT], psNameToDelete
 *  RETURNS         :   0, 1
 */
int iDeleteAPersonsName(struct NamesOfPeople* arspHashTable[KTABLELIMIT],
char* psNameToDelete)
{   
    int iVisitedCells = 0;
    int iIndex = iTheHashFunction(psNameToDelete);
    while (arspHashTable[iIndex] != NULL)
    {   
        // If all cells were visited and the name was not found return 1.
        if (iVisitedCells == KTABLELIMIT) { return 1; }

        if ((arspHashTable[iIndex] != NULL) &&
        ((strcmp(arspHashTable[iIndex]->arsName, psNameToDelete)) == 0))
        {
            arspHashTable[iIndex] = NULL;
            return 0;
        }
        ++iIndex;
        ++iVisitedCells;

        // Wrap around in case of collision when inserted.
        iIndex %= KTABLELIMIT;
    }
    return 1;
}

/**     -- Function header comment
 *  FUNCTION        :   showTheTableOfNames
 *  DESCRIPTION     :   This function will take in the hash table to display
 *                      and will show all names to the console window one line at
 *                      a time.
 *  PARAMETERS      :   arspHashTable[KTABLELIMIT]
 *  RETURNS         :   None
 */
void showTheTableOfNames(struct NamesOfPeople* arspHashTable[KTABLELIMIT])
{   
    printf("\n -- Names to display -- \n\n");
    int iNames = 0;
    while (iNames < KTABLELIMIT)
    {   
        // If the position was not filled then display a blank space.
        if (arspHashTable[iNames] == NULL)
        { 
            printf(" "); 
        }
        else
        { 
            printf("\tName: %s", arspHashTable[iNames]->arsName); 
        }
        ++iNames;
    }
}