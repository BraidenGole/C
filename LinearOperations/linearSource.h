/**
 * @file linearOperations.h
 * @author Braiden Gole
 * @brief This is a project that consist of basic linear operations.
 * @version 0.1
 * @date 2020-12-26
 * @copyright Copyright (c) 2020
 * 
 *  [FORMULAS]:
 *      DISTANCE: d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
 *      MID POINT: M = ((x1 + x2 / 2), (y1 + y2 / 2))
 *      SLOPE: (y2 - y1) / (x2 - x1)
 *      
 */
#ifndef _KLINEARSOURCE
#define _KLINEARSOURCE "linearSource.c"

// Global string constants.
#define KSELECTION1 "\n\t1. Calculate Distance."
#define KSELECTION2 "\n\t2. Calculate Midpoint."
#define KSELECTION3 "\n\t3. Calculate Slope."
#define KQUIT "\n\t4. Quit.\n"
#define KSELECTOP "\n\tEnter in a selection: "
#define KNOCHARACTERS "\n\tNo characters ! Numbers only."

// Global numeric constants.
#define KFOUR 4
#define KTWO 2
#define KXANDY 3
#define K100BYTES 100

struct Points
{
    double x1;
    double y1;
    double x2;
    double y2;
    double xCoord;
    double yCoord;
};

// Function prototypes.
const double calculateDistance(struct Points *points);
struct Points* calculateMidpoint(struct Points *points);
const double calculateSlope(struct Points *points);
void collectPoints(struct Points **points);
#endif