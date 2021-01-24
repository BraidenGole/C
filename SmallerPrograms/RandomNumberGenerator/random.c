/**
 * @file random.c
 * @author Braiden Gole
 * @brief This is a small sample on the "Random Number Generator" in
 *        the (C) programming language.
 * @version 0.1
 * @date 2021-01-24
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KRANDOMRANGE 100
#define KMAXSIZE 10

int main(void)
{   
    // A call to "srand" will produce different numbers
    // everytime unlike a call to just rand().

    // ALways fill in the time() parameter as time(NULL)
    // This is the proper way on how to start the random number
    // generator.
    srand(time(NULL));

    printf("First set:\n");
    int nums;
    for (nums = 0; nums < KMAXSIZE; nums++)
    {
        printf("%i ", rand() % KRANDOMRANGE);
    }

    printf("\n\n");

    printf("Second set:\n");
    int again = 0;
    for (again = 0; again < KMAXSIZE; again++)
    {
        printf("%i ", rand() % KRANDOMRANGE);
    }

    printf("\n\n\tDifferent numbers produced everytime !\n");
    return 0;
}