/**
 *  FILE            :   list.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-09-03 - Update (2020-11-11) 
 *  DESCRIPTION     :   This is an implementation of a linked-list.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Header file
#include "linkedList.h"

int main(void)
{
    struct Grade* pHead = NULL;

    char arsName[KMAX] = { 0 };
    char arsDeleteGrade[KMAX] = { 0 };

    int iSelection = 0;
    int iLengthOfName = 0;
    int iGradeData = 0;
    int iErrorStatus = -3;

    bool bGradeEntry = true;
    bool bKeepEntering = true;
    while (bKeepEntering)
    {
        // -- Menu Selections -- //
        printf(KMENUHEADER);
        printf(KSELECTION1);
        printf(KSELECTION2);
        printf(KSELECTION3);
        printf(KSELECTION4);

        printf(KPROMPTFORSELECTION);
        if ((fscanf(stdin, "%i", &iSelection)) == 0)
        {
            fprintf(stderr, KNOCHARACTERS);
            fflush(stdin);
        }

        switch (iSelection)
        {
            case 1:
                getchar();
                NameEntry:
                printf(KENTERSTUDENTNAME);
                fgets(arsName, KMAX, stdin);
                removeNewLine(arsName);

                // Calculate the length of the students name on every entry.
                iLengthOfName = (strlen(arsName) - 1);
                if ((studentNameValidator(arsName, iLengthOfName)) == false)
                {
                    goto NameEntry;
                }

                GradeEntry:
                printf(KENTERINAGRADE);
                if ((fscanf(stdin, "%i", &iGradeData)) == 0)
                {
                    fflush(stdin);
                    goto GradeEntry;
                }

                // If we ran out of memory end the program.
                bGradeEntry = submitAGrade(&pHead, arsName, iGradeData, &iErrorStatus);

                if (bGradeEntry == true) 
                { 
                    fprintf(stdout, KADDEDTOTHELIST);
                }

                if (iErrorStatus == -1) 
                { 
                    return -1;
                }
                else if (iErrorStatus == -2) 
                { 
                    fprintf(stderr, KOUTOFRANGE);
                    goto GradeEntry;
                }
                break;
            case 2:
                // Display a list of grades to delete from.
                printGrades(pHead);

                Delete:
                printf(KDELETEWHATGRADE);
                if ((fscanf(stdin, "%s", arsDeleteGrade)) == 0)
                {
                    fprintf(stderr, KNOCHARACTERS);
                    fflush(stdin);
                    goto Delete;
                }

                // If a grade was not found in the list of grades presented let the user know.
                if ((deleteGrade(&pHead, arsDeleteGrade)) == false) 
                { 
                    fprintf(stderr, KNOTFOUND);
                }
                else 
                { 
                    printf(KFOUND);
                }
                break;
            case 3:
                // If there are no current entries the list output a empty message.
                if ((printGrades(pHead)) == false) 
                { 
                    fprintf(stderr, KEMPTYLIST);
                }
                break;
            case 4:
                releaseDynamicMemory(&pHead);
                bKeepEntering = false;
        }
    }
    return 0;
}
