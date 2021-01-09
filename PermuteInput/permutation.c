/**
 * @file permutation.c
 * @author Braiden Gole
 * @brief [CREDITING SOURCE BELOW !] Geeks For Geeks.
 * 
 *     This is a program that draws out all the combinations possible
 *     in the sequence in order.
 * 
 * NOTE: This program was very hard I had to look off of another program to write
 *       my own custom implementation. "I would like to credit the source" "Geeks for Geeks" for
 *       having a sample solution readily available to test. I learned that trying to permute
 *       input is very difficult but still managed to come up with something uniquely different.
 *       
 *       [Differences]:
 *          1. We swap using a macro with arguments "KSWAP(tmp, x, y)"
 *          2. We do not use a pointer function or pointers to swap my implementation
 *             swaps by value using a macro with arguments.
 *          3. We do not use pointer arithmetic when swapping that values because they are swapped
 *             differently.
 *          4. The interface build around handling the operation of permuting a string is different
 *             for example where we handle specific check are written in different spots and checked
 *             at different times because of the change in structure.
 *          5. Uses a while loop instead of for loop.
 * -----------------------------------------------------------------------------------------------------------------
 * [SOURCE: (GEEKS FOR GEEKS)]: https://www.geeksforgeeks.org/c-program-to-print-all-permutations-of-a-given-string/
 * -----------------------------------------------------------------------------------------------------------------
 * @version 0.1
 * @date 2021-01-07
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KFIRSTARGUMENT 1
#define KSWAP(tmp, x, y) { tmp=x, x=y, y=tmp; }

// Function protoypes.
void generateOrderlyCombinations(char* input, int tracer, const int lengthOfInput);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "\n\tNo command-line arguments !\n");
        return 1;
    }
    else
    {
        // We have a command-line argument.
        const int KLENGTH = strlen(argv[KFIRSTARGUMENT]);
        char* commandLineArg = argv[KFIRSTARGUMENT];

        // Generate the permuted string input.
        generateOrderlyCombinations(commandLineArg, 0, KLENGTH);
    }
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   generateOrderlyCombinations
 *  DESCRIPTION     :   This function will output all of the orderly combinations
 *                      of the input supplied.
 *  PARAMETERS      :   input, tracer, lengthOfInput
 *  RETURNS         :   None
 */
void generateOrderlyCombinations(char* input, int tracer, const int lengthOfInput)
{   
    int temp = 0;
    int letters = 0;

    letters = tracer;
    while (letters < lengthOfInput)
    {   
        KSWAP(temp, input[letters], input[tracer]);
        if (tracer == lengthOfInput - 1)
        {
            printf("%s\n", input);
        }
        else
        {
            generateOrderlyCombinations(input, tracer + 1, lengthOfInput);
            KSWAP(temp, input[letters], input[tracer]);
        }
        ++letters;
    }
}
