/**
 *  FILE            :   stack.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-06-29
 *  DESCRIPTION     :   This is the implementation of a stack algorithm.
 */
#include <stdio.h>
#include <stdbool.h>

// Header file.
#include "stackAlgorithm.h"

int main(void)
{   
    // Declare the stack to work with.
    int ariStack[KSTACKSIZE] = { 0 };

    int iOperation = 0;
    int iTop = -1;

    int iNumber = 0;

    bool bStackCondition = true;
    while (bStackCondition)
    {   
        printf(KMENUHEADER);
        printf(KOPTION1);
        printf(KOPTION2);
        printf(KOPTION3);
        printf(KOPTION4);
        printf(KOPTION5);
        printf(KPROMPTFOROPTION);
        if ((fscanf(stdin, "%i", &iOperation)) == 0)
        {
            fprintf(stderr, KNOCHARACTERS);
            fflush(stdin);
        }

        // Associate the proper option with the correct operation.
        switch (iOperation)
        {
            case 1:
                printf(KPROMPTFORPUSH);
                if ((fscanf(stdin, "%i", &iNumber)) == 0)
                {
                    fprintf(stderr, KNOCHARACTERS);
                    fflush(stdin);
                }

                printf("\n");

                if ((push(ariStack, iNumber, &iTop)) == -1) 
                { 
                    printf(KSTACKOVERFLOW);
                    bStackCondition = false;
                }
                break;
            case 2:
                if ((pop(ariStack, &iTop)) == -1) { printf(KEMPTY); }
                break;  
            case 3:
                printf("\nThe top of the stack: [%i]\n\n", ariStack[iTop]);
                break;
            case 4:
                showStack(ariStack, &iTop);
                break;
            case 5:
                bStackCondition = false;
        }
    }
    // Display the list one last time.
    if ((showStack(ariStack, &iTop)) == -1) { fprintf(stderr, KEMPTY); }
    return 0;
}