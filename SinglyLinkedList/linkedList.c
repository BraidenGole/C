/**
 *  FILE            :   linkedList.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-09-03 - Updated (2020-11-11)
 *  DESCRIPTION     :   This file holds the functions for our singly linked list.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Header files.
#include "linkedList.h"

// Function prototypes.
const bool gradeRangeCheck(int iGrade);

/**     -- Function header comment
 *  FUNCTION        :   submitAGrade
 *  DESCRIPTION     :   This function allows the teacher to enter in a grade manually.
 *                      The grade is automaically linked to the head if that grade is an
 *                      integer between the range of [0-100].
 *  PARAMETERS      :   ppHead, psStudent, iPercent, iStatus
 *  RETURNS         :   true, false
 */
const bool submitAGrade(struct Grade** ppHead, char* psStudent, int iPercent, int* iStatus)
{
    struct Grade* pNewGrade = NULL;
    pNewGrade = (struct Grade*)malloc(sizeof(struct Grade));
    if (pNewGrade == NULL) { *iStatus = -1; }

    // Fill in the grade field with the percented represented as an integer.
    if ((gradeRangeCheck(iPercent)) == false) { *iStatus = -2; }

    // Enter the information.
    strcpy(pNewGrade->arsStudent, psStudent);
    pNewGrade->iGrade = iPercent;
    pNewGrade->pNext = NULL;

    // Check to see if the head is empty.
    if (*ppHead == NULL)
    {
        *ppHead = pNewGrade;
        return true;
    }
    pNewGrade->pNext = *ppHead;
    *ppHead = pNewGrade;
    return true;
}

/**     -- Function header comment
 *  FUNCTION        :   deleteGrade
 *  DESCRIPTION     :   This function is designed to delete one grade out
 *                      of the list of grades to delete from.
 *  PARAMETERS      :   ppHead, iGradeToDelete
 *  RETURNS         :   true, false
 */
const bool deleteGrade(struct Grade** ppHead, char* psStudent)
{
    struct Grade* pHeadRef = *ppHead;
    struct Grade* pPrev = NULL;

    // Is the item to delete at the head of the list ?
    if (*ppHead != NULL && ((strcmp((*ppHead)->arsStudent, psStudent)) == 0))
    {
        *ppHead = (*ppHead)->pNext;
        free(ppHead);
        return true;
    }

    // If it is not directly at the head of the list traverse the list to find the potential item.
    while (pHeadRef != NULL && (((strcmp(pHeadRef->arsStudent, psStudent)) != 0)))
    {
        pPrev = pHeadRef;
        pHeadRef = pHeadRef->pNext;
    }
    
    // If the there are no student names equal to the one supplied return false.
    if (pHeadRef == NULL) { return false; }

    pPrev->pNext = pHeadRef->pNext;
    free(pHeadRef);
    return true;
}

/**     -- Function header comment
 *  FUNCTION        :   studentNameValidator
 *  DESCRIPTION     :   This function ensures that the data to be filled
 *                      in will be in the correct format and will contain only
 *                      the students name and not any other characters.
 *  PARAMETERS      :   psStudentsName, KiLength
 *  RETURNS         :   true, false
 */
const bool studentNameValidator(char* psStudentsName, const int KiLength)
{   
    int iLetters = 0;
    while (iLetters <= KiLength)
    {   
        if ((isdigit(psStudentsName[iLetters])) > 0) { return false; }
        else if ((ispunct(psStudentsName[iLetters])) != 0) { return false; }
        ++iLetters;
    }
    return true;
}

/**     -- Function header comment
 *  FUNCTION        :   gradeRangeCheck
 *  DESCRIPTION     :   This function will test to see if the grade
 *                      supplied fits in the range of [0-100].
 *  PARAMETERS      :   iGrade
 *  RETURNS         :   true, false
 */
const bool gradeRangeCheck(int iGrade)
{
    if (iGrade >= KMIN && iGrade <= KMAX) { return true; }
    return false;
}

/**     -- Function header comment
 *  FUNCTION        :   printGrades
 *  DESCRIPTION     :   This function will output the grades to 
 *                      the console window.
 *  PARAMETERS      :   ppHead
 *  RETURNS         :   true, false
 */
const bool printGrades(struct Grade* ppHead)
{   
    if (ppHead == NULL) { return false; }
    struct Grade* pHeadRef = NULL;

    pHeadRef = ppHead;
    printf("\n\t\t-- Grades --\n");
    while (pHeadRef != NULL)
    {
        printf("\t\t\t%s: %i%%\n", pHeadRef->arsStudent, pHeadRef->iGrade);
        pHeadRef = pHeadRef->pNext;
    }
    printf("\n");
    return true;
}

/**     -- Function header comment
 *  FUNCTION        :   removeNewLine
 *  DESCRIPTION     :   This function will remove a new line character
 *                      from the fgets function.
 *  PARAMETERS      :   psInput
 *  RETURNS         :   None
 */
void removeNewLine(char* psInput)
{
    char* psSearchForNewLine = strchr(psInput, '\n');
    if (psSearchForNewLine != NULL) { *psSearchForNewLine = '\0';}
}

/**     -- Function header comment
 *  FUNCTION        :   releaseDynamicMemory
 *  DESCRIPTION     :   This function will release every grade that was
 *                      ever entered into the list.
 *  PARAMETERS      :   ppHead
 *  RETURNS         :   None
 */
void releaseDynamicMemory(struct Grade** ppHead)
{
    struct Grade* pHeadRef = *ppHead;
    struct Grade* pThisGrade = NULL;

    while (pHeadRef != NULL)
    {   
        pThisGrade = pHeadRef;
        free(pThisGrade);
        pHeadRef = pHeadRef->pNext;
    }
}