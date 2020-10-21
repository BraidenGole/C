/**
 *  FILE            :   discardFunction.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-10-20
 *  DESCRIPTION     :   This is an example on how to #undefine a function
 *                      in the (C) programming language. The purpose of this is that you
 *                      can override the standard (C) function and write your own implementation
 *                      of the function.
 */
#include <stdio.h>
#include <ctype.h>

#undef isalpha

int main(void)
{   
    /** -- Testing -- **/
    int inputOne = 'A';
    int inputTwo = 'z';
    int inputThree = '#';
    int inputFour = -1;

    // Ouput the results of each test to the console.
    printf("\n\n-- Returned Results --\n");
    printf("\t[TEST #1]: %i\n", isalpha(inputOne));    // return 0;
    printf("\t[TEST #2]: %i\n", isalpha(inputTwo));    // return 0;
    printf("\t[TEST #3]: %i\n", isalpha(inputThree));  // return 1;
    printf("\t[TEST #4]: %i\n", isalpha(inputFour));   // return 2;
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   isalpha
 *  DESCRIPTION     :   This is my own custom implementation of the isalpha function.
 *                      We will return 0 if the ascii code is in the range of uppercase and
 *                      lowercase characters and a 1 if it is a punctuation character and
 *                      a 2 if the input contains a digit.
 *  PARAMETERS      :   input
 *  RETURNS         :   0, 1, 2
 */
int isalpha(int input)
{   
    if (input >= 97 && input <= 122) { return 0; }
    if (input >= 65 && input <= 90) { return 0; }
    if (input >= 33 && input <= 126) { return 1; }
    return 2;
}