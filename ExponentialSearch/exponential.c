/**
 * @file exponential.c
 * @author Braiden Gole
 * @brief This is the implementation of a exponential search algorithm.
 * 
 *        NOTE: Trying to change my programming style to give variance from
 *              program to program.
 * 
 *        NOTE: The program will recusively continue until one value is found, as
 *              soon as a value has been found then the program ends.
 * @version 0.1
 * @date 2021-01-17
 * @copyright Copyright (c) Briaden Gole 2021
 */
#include <stdio.h>
#include <stdbool.h>

// Header files.
#include "exponentialSearch.h"

// Function prototypes.
const bool exponentialSearch(int* data, const int max, const int value);

int main(void)
{   
    // Create the data to search from.
    int searchPool[SEARCHLIMIT] = { -845, -1, 6, 7, 9, 106, 113, 119, 121, 125, 129, 131, 134, 138 };

    int searchValue = ZERO;
    int inputCode = ONE;
    bool foundOrNot = false;
    do
    {   
        printf(KENTERINVALUE);
        inputCode = fscanf(stdin, _INT_FORMAT, &searchValue);
        if (inputCode __EQ__ ZERO) 
        {   
            fprintf(stderr, KNOCHARS);
            fflush(stdin);
        }

        // Send the value to find into the search function.
        foundOrNot = exponentialSearch(searchPool, SEARCHLIMIT, searchValue);
        if (foundOrNot __EQ__ true)
        {   
            // Showing a different way on showing output ! fprintf 
            fprintf(stdout, KFOUND);
        }
        else
        {
            fprintf(stdout, KNOTFOUND);
        }
    } while (NOT(foundOrNot));
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   exponentialSearch
 *  DESCRIPTION     :   This is the function that performs the exponential
 *                      search.
 *  PARAMETERS      :   data, max, value
 *  RETURNS         :   found
 */
const bool exponentialSearch(int* data, const int max, const int value)
{   
    // Did we find the value at the first index ?
    bool found = false;
    if (data[ZERO] __EQ__ value)
    {   
        found = true;
        return found;
    }
    else
    {   
        // This is a different interface/use for a function for a change.
        // Instead of returning the result we will fill in a variable
        // through a int_ptr parameter with the value.
        int powIndex = ONE;
        generatePowIndex(data, max, value, &powIndex);
        
        // Feed in the calculated index into the binary search function.
        int manipMax = max;
        found = binarySearch(data, powIndex __DIV__ TWO, MIN(powIndex, manipMax), value);
        if (found __EQ__ true)
        {
            found = true;
            return found;
        }
    }
    return found;
}