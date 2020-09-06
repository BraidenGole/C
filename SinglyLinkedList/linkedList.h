/**
 *  FILE            :   linkedList.h
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-09-03
 *  DESCRIPTION     :   This file is used to hold the function prototypes and the blueprint
 *                      to our record that we would like to store.
 */
#ifndef _KLINKEDLIST
#define _KLINKEDLIST "linkedList.h"

// Global string constants.
#define KMENUHEADER "\n-- Singly linked list --\n"
#define KSELECTION1 "\n\t1. Enter in a Grade."
#define KSELECTION2 "\n\t2. Delete a Grade."
#define KSELECTION3 "\n\t3. Print Grades."
#define KSELECTION4 "\n\t4. Quit\n"
#define KPROMPTFORSELECTION "\n\tSelect an option: "
#define KENTERINAGRADE "\n\tEnter a Grade: "
#define KENTERSTUDENTNAME "\n\tName of Student: "
#define KDELETEWHATGRADE "\n\tDelete which students grade: "
#define KNOCHARACTERS "\n\tNo characters !\n"
#define KEMPTYLIST "\n\tEmpty List\n"
#define KOUTOFRANGE "\n\tOut of Range !\n"
#define KNOTFOUND "\n\tThis grade was not found !\n"
#define KFOUND "\n\tThis grade was deleted !\n"

// Global numeric constants.
#define KMIN 0
#define KMAX 100

struct Grade
{   
    char arsStudent[KMAX];
    int iGrade;
    struct Grade* pNext;
};

// Function prototypes.
const int submitAGrade(struct Grade** ppHead, char* psStudent, int iPercent);
const bool studentNameValidator(char* psStudentsName, const int KiLength);
const bool gradeRangeCheck(int iGrade);
void removeNewLine(char* psInput);
const bool deleteGrade(struct Grade** ppHead, char* psStudent);
const bool printGrades(struct Grade* pHead);
void releaseDynamicMemory(struct Grade** ppHead);
#endif