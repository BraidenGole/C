/**
 * @file linearSource.c
 * @author Braiden Gole
 * @brief This is a project that consist of basic linear operations.
 * @version 0.1
 * @date 2020-12-26
 * @copyright Copyright (c) 2020
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Header file.
#include "linearSource.h"

/**     -- Method header comments
 *  Method          :   calcualteDistance
 *  Description     :   This will calculate the distance between 
 *  Parameters      :   (x1, y1), (x2, y2)
 *  Returns         :   distance
 */
const double calculateDistance(struct Points *points)
{   
    double x2Minusx1 = points->x2 - points->x1;
    double y2Minusy1 = points->y2 - points->y1;

    double powerOfxs = pow(x2Minusx1, KTWO);
    double powerOfys = pow(y2Minusy1, KTWO);

    double addBoth = powerOfxs + powerOfys;
    double distance = sqrt(addBoth);

    return distance;
}

/**     -- Method header comments
 *  Method          :   calculateMidpoint
 *  Description     :   This will calculate the midpoint of a line.
 *  Parameters      :   (x1, y1), (x2, y2)
 *  Returns         :   midpoint[]
 */
struct Points* calculateMidpoint(struct Points *points)
{   
    struct Points *temp = NULL;
    temp = (struct Points*)malloc(sizeof(struct Points));
    if (temp == NULL)
    {
        return NULL;
    }
    double xPoint = ((points->x1 + points->x2) / 2);
    double yPoint = ((points->y1 + points->y2) / 2);
    temp->xCoord = xPoint;
    temp->yCoord = yPoint;
    return temp;
}

/**     -- Method header comments
 *  Method          :   calculateSlope
 *  Description     :   This will calculate the slope of a line.
 *  Parameters      :   (x1, y1), (x2, y2)
 *  Returns         :   slope
 */
const double calculateSlope(struct Points *points)
{
    double slope = (points->y2 - points->y1) / (points->x2 - points->x1);
    return slope;
}

/**     -- Method header comment
 *  Method          :   collectPoints
 *  Description     :   This function will be called to collect the two sets of
 *                      points required for some of the functions.
 *  Parameters      :   pairOne, pairTwo
 *  Returns         :   None
 */
void collectPoints(struct Points **points) 
{   
    struct Points *newPoints = NULL;
    newPoints = (struct Points*)malloc(sizeof(struct Points));
    if (newPoints == NULL)
    {
        return;
    }
    double collectX1 = 0;
    double collectY1 = 0;
    double collectX2 = 0;
    double collectY2 = 0;

    printf("\n-- Enter in 4 numbers, 1 number per line --");
    bool keepGettingPoints = true;
    while (keepGettingPoints)
    {   
        Restartx1:
        printf("\n\tEnter x1: ");
        if ((fscanf(stdin, "%lf", &collectX1)) == 0)
        {   
            fprintf(stderr, KNOCHARACTERS);
            fflush(stdin);
            goto Restartx1;
        }
        Restarty1:
        printf("\tEnter y1: ");
        if ((fscanf(stdin, "%lf", &collectY1)) == 0)
        {
            fprintf(stderr, KNOCHARACTERS);
            fflush(stdin);
            goto Restarty1;
        }
        Restartx2:
        printf("\tEnter x2: ");
        if ((fscanf(stdin, "%lf", &collectX2)) == 0)
        {
            fprintf(stderr, KNOCHARACTERS);
            fflush(stdin);
            goto Restartx2;
        }
        Restarty2:
        printf("\tEnter y2: ");
        if ((fscanf(stdin, "%lf", &collectY2)) == 0)
        {
            fprintf(stderr, KNOCHARACTERS);
            fflush(stdin);
            goto Restarty2;
        }

        // Write the points into the structure.
        newPoints->x1 = collectX1;
        newPoints->y1 = collectY1;
        newPoints->x2 = collectX2;
        newPoints->y2 = collectY2;

        // Write the temp struct to our struct we passed in as a parameter.
        *points = newPoints;
        keepGettingPoints = false;
    }
}