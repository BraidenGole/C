/**
 *  FILE            :   stackAlgorithm.h
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-06-29
 *  DESCRIPTION     :   This file is used to hold the function
 *                      prototypes to make the code more modular and
 *                      organized.
 */
#ifndef _KSTACKALGORITHM
#define _KSTACKALGORITHM "stackAlgorithm.h"

// Global string constants.
#define KMENUHEADER "-- Stack Implementation --\n"
#define KSTACKHEADER "\n-- STACK --\n"
#define KOPTION1 "\t1. push\n"
#define KOPTION2 "\t2. pop\n"
#define KOPTION3 "\t3. peek\n"
#define KOPTION4 "\t4. showStack\n"
#define KOPTION5 "\t5. quit\n\n"
#define KPROMPTFOROPTION "Select an option: "
#define KPROMPTFORPUSH "\nEnter in the number to push: "
#define KNOCHARACTERS "\nNo characters !\n"
#define KSTACKOVERFLOW "STACK OVERFLOW !\n\n"
#define KEMPTY "\nEMPTY !\n"

// Global numeric constants.
#define KSTACKSIZE 8

// Function prototypes.
const int push(int ariStack[], int iData, int* piTop);
const int pop(int ariStack[], int* piTop);
const int peek(int ariStack[], int* piTop);
const int showStack(int ariStack[], int* piTop);
#endif