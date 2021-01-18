/**
 * @file environment.c
 * @author Braiden Gole
 * @brief This is going to be a small snippet on environment variables.
 *        --------------------------------------------------------------------------
 *        [SOURCE/BOOK]: AL KELLY, IRA POHL ["A Book on C"] Fourth edition page 521.
 *        --------------------------------------------------------------------------
 *        I have a couple local permanent environment variables that I have created
 *        and used in this (C) application.
 * 
 *        We can set a permanent variable throught the Windows Command-Prompt by
 *        using the (setx) command.
 * 
 *        setx NAME "BRAIDEN"
 *        setx LASTNAME "GOLE"
 * 
 * NOTE: We must use "<stdlib.h>" as the getenv() function is defined in that header.
 * 
 * @version 0.1
 * @date 2021-01-04
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>

// Function prototypes.
void displayUserInformation();

int main (int argc, char* argv[], char* env[])
{   
    // Output all environment variables.
    int variables = 0;
    while (env[variables] != NULL)
    {   
        printf("%s\n", env[variables]);
        ++variables;
    }

    // Display some custom information.
    displayUserInformation(env);
    return 0;
}

/**     -- Function header comment
 *  FUNCTION        :   displayUserInformation
 *  DESCRIPTION     :   This function will display some environment
 *                      variable information.
 *  PARAMETERS      :   None
 *  RETURNS         :   None
 */
void displayUserInformation()
{
    printf("\n  -- System Information --\n");
    printf("\tName: %s\n", getenv("NAME"));
    printf("\tLast name: %s\n", getenv("LASTNAME"));
    printf("\tUsername: %s\n", getenv("USERNAME"));
    printf("\tSession name: %s\n", getenv("SESSIONNAME"));
}
