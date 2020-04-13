/**
 *  FILE            :   hashTable.h
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-12
 *  DESCRIPTION     :   This file will hold the structure that
 *                      will be recording the names of people.
 */
#ifndef _KHASHTABLE
#define _KHASHTABLE "hashTable.h"

// Global string constants.
#define KPROMPT_FOR_NAME "\tEnter in a name: "
#define KPROMPT_FOR_LOOKUPNAME "\n\tPlease enter in a name to lookup: "
#define KPROMPT_FOR_NAMETODELETE "\n\tEnter in a name to delete: "

// Global numeric constants.
#define KTABLELIMIT 11
#define K50BYTES 51

// Struct to hold names of people.
struct NamesOfPeople { char arsName[K50BYTES]; };

// Function prototypes.
void initializeHashTable(struct NamesOfPeople* arspHashTable[KTABLELIMIT]);
unsigned int iTheHashFunction(char* psKey);
int iInsertPeoplesNames(struct NamesOfPeople* arspHashTable[KTABLELIMIT],
char* psNameToinsert, int iElementPosition);
void showTheTableOfNames(struct NamesOfPeople* arspHashTable[KTABLELIMIT]);
int iHashTableLookup(struct NamesOfPeople* arsHashTable[KTABLELIMIT], 
char* psTheLookupName);
int iDeleteAPersonsName(struct NamesOfPeople* arspHashTable[KTABLELIMIT],
char* psNameToDelete);
void clearTheNames(struct NamesOfPeople* arspHashTable[KTABLELIMIT]);
#endif