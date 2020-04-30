/**
 *  FILE            :   operations.h
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-29
 *  DESCRIPTION     :   This file will hold all of the function prototypes.
 */
#ifndef _KOPERATIONS
#define _KOPERATIONS "operations.h"

// Global string constants.
#define KMENUHEADER "\n -- Operations -- \n"
#define KSELECTION1 "\t1. Change base.\n"
#define KSELECTION2 "\t2. Change exponent.\n"
#define KSELECTION3 "\t3. Display the power menu.\n"
#define KSELECTION4 "\t4. End program.\n\n"
#define KPROMPT_FOR_SELECTION "\tPlease enter in a number: "

#define KPROMPT_FOR_BASE "\n\tEnter in a base: "
#define KPROMPT_FOR_EXPONENT "\n\tEnter in a exponent: "

// Function prototypes.
const int iChangeBase(int iBase);
const int iChangeExponent(int iPower);
const int calculatePower(int iBase, int iExponent);
void displayMenuOptions(void);
#endif