/**
 *  FILE            :   scoreSort.h
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-18
 *  DESCRIPTION     :   This is where the function prototypes and macros
 *                      will be held to keep our program more modular and
 *                      organized.
 */
#ifndef _KSCORESORT
#define _KSCORESORT "scoreSort.h"

// Global string constants.

// Global numeric constants.
#define KSCOREROWS 8
#define KHALFOFSCOREROWS (KSCOREROWS / 2)
#define KSCORECOLS 8
#define KSCORELIMIT (KSCOREROWS * KSCORECOLS)
#define KHALFOFSCORELIMIT (KSCORELIMIT / 2)

// [ Macros with parameters ]
#define KmwpSORT(tmp, x, y) { tmp=x, x=y, y=tmp; }

// Function prototypes.
void partitionScores(int ariScores[KSCOREROWS][KSCORECOLS],
int* piHalf, int* piOther);
void sortEachHalfOfScores(int* piHalf);
void mergeScores(int* piFinalScores, int* piHalf, int* piOther);
void showAllScores(int* piFinalSet);
#endif