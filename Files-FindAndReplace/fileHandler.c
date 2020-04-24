/**
 *  FILE            :   fileHandler.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-23  
 *  DESCRIPTION     :   This file is used to hold the the functions
 *                      that will handle the operations we would like
 *                      to perform.
 */
#include <stdio.h>
#include <string.h>

// Header file.
#include "fileHandler.h"

/**     -- Function header comment
 *  FUNCTION        :   displayResult
 *  DESCRIPTION     :   This function will display the file with the words
 *                      replaced.
 *  PARAMETERS      :   pFileToDisplay, kpsNameOfFile, kpsFileMode
 *  RETURNS         :   0, 1, 2
 */
const int displayResult(FILE* pFileToDisplay, const char* kpsNameOfFile,
const char* kpsFileMode)
{   
    // Open the file.
    const char* kpsMode = "r";
    pFileToDisplay = fopen(kpsNameOfFile, kpsMode);
    if (pFileToDisplay == NULL)
    {
        return 1;
    }
    else
    {   
        // The file is opened, display the contents.
        printf("\n  -- File contents -- \n\n");
        char arsContents[K3000BYTES] = {""};
        while ((fgets(arsContents, sizeof(arsContents), pFileToDisplay)) != NULL)
        {
            printf("\t%s", arsContents);
        }
    }
    // Close the file.
    if ((fclose(pFileToDisplay)) == EOF)
    {
        return 2;
    }
    return 0;
}
