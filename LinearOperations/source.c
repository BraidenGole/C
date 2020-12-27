/**
 * @file source.c
 * @author Braiden Gole
 * @brief This is a project that consist of basic linear operations just a
 *        basic calculator that carries out small duties. The small calculator
 *        is not a system it is not tested like a system. This program requires
 *        some knowledge from the user on what numbers are being subbed in and what
 *        numbers are comming out.
 * @version 0.1
 * @date 2020-12-26
 * @copyright Copyright (c) 2020
 * 
 *  [FORMULAS]:
 *      DISTANCE: d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
 *      MID POINT: M = (x1 + x2 / 2, y1 + y2/2)
 *      SLOPE: y2 - y1 / x2 - x1
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Header files.
#include "linearSource.h"

int main(void) 
{   
    /***************************
      [SAMPLE INPUT SUBJECTS]
    ***************************/
    // 1. (x1 = 1, y1 = 3), (x2 = -6, y2 = -5) = 10.63.
    // 2. (x1 = 2, y1 = 5), (x2 = -4, y2 = 8) = 6.5
    // 3. (x1 = 1, y1 = 2), (x2 = 3, y2 = 4) = 1

    int selection = 0;
    struct Points *myPoints = NULL;

    double distance = 0;
    double slope = 0;

    bool executeLinearOp = true;
    while (executeLinearOp)
    {
        printf(KSELECTION1);
        printf(KSELECTION2);
        printf(KSELECTION3);
        printf(KQUIT);
        printf(KSELECTOP);
        if ((fscanf(stdin, "%i", &selection)) == 0)
        {   
            fprintf(stderr, KNOCHARACTERS);
            fflush(stdin);
        }

        if (selection == 4)
        {
            // Be sure to free the memory passed by the temp dynamically allocated struct.
            // to the myPoints structure.
            free(myPoints);
            executeLinearOp = false;
            break;
        }

        // Call the function to collect (x1, y1) & (x2, y2).
        collectPoints(&myPoints);

        switch (selection)
        {
            case 1:
                distance = calculateDistance(myPoints);
                printf("\n\tThe distance calculated is: %.2lf\n", distance);
                break;
            case 2:
                myPoints = calculateMidpoint(myPoints);
                printf("\n\tThe midpoint: (%.1lf, %.1lf)\n", myPoints->xCoord, myPoints->yCoord);
                break;
            case 3:
                slope = calculateSlope(myPoints);
                printf("\n\tThe slope of the line is: %.1lf\n", slope);
                free(myPoints);
                break;
        }
    }
    return 0;
}