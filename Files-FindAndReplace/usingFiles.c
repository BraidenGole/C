/**
 *  FILE            :   usingFiles.c
 *  PROJECT         :   None
 *  PROGRAMMER      :   Braiden Gole
 *  FIRST VERSION   :   2020-04-23  
 *  DESCRIPTION     :   This is a program designed to display the
 *                      use of files in the (C) programming language.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Header file.
#include "fileHandler.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, KDIDNOTSUPPLY);
        return 1;
    }
    else
    {
        // A file was supplied, perform operations.
        const char* kpsCmdLineArg = argv[1];
        const char* kpsFileMode = "r";

        const char* kpsTempFile = "temp.txt";
        const char* kpsTempMode = "w";

        /** -- Opening <inputFile> here -- **/
        FILE* pInputFile = fopen(kpsCmdLineArg, kpsFileMode);
        /** -- Opening <tempFile> up here -- **/
        FILE* pTempFile = fopen(kpsTempFile, kpsTempMode);
        if (pInputFile == NULL || pTempFile == NULL)
        {
            fprintf(stderr, KCOULDNOTOPEN);
            return 1;
        }
        else
        {
            char* psFileContents = NULL;
            psFileContents = (char*)malloc(K3000BYTES);
            if (psFileContents == NULL) 
            { 
                return 1;
            }

            const char* kpsBRAIDENGOLE = "Braiden Gole";
            const char* kpsReplacement = "BRAIDEN GOLE";

            char arsFileBuffer[K3000BYTES] = {""};
            char* psWordToReplace = NULL;
            char* psTempWord = NULL;

            int iPosition = 0;
            const int kiNewWordLen = strlen(kpsReplacement);
            
            while ((psFileContents = fgets(arsFileBuffer, sizeof(arsFileBuffer), pInputFile)) != NULL)
            {   
                // Look for every single occurence of "Braiden Gole".
                if ((psWordToReplace = strstr(arsFileBuffer, kpsBRAIDENGOLE)) != NULL)
                {   
                    psTempWord = arsFileBuffer;

                    // Get the position of the word found.
                    iPosition = psWordToReplace - arsFileBuffer;
                    arsFileBuffer[iPosition] = '\0';

                    // Concatenate the replacements to the file.
                    strcat(arsFileBuffer, kpsReplacement);
                    strcat(arsFileBuffer, (psTempWord + iPosition + kiNewWordLen));
                }
                fprintf(pTempFile, "%s ", arsFileBuffer);
            }
            // Free the dynamically allocated content holder.
            free(psFileContents);
        }
        /** -- Closing <tempFile> here. -- **/
        if ((fclose(pTempFile)) == EOF)
        {
            fprintf(stderr, KCOULDNOTCLOSE);
            return 1;
        }
        /** -- Closing <inputFile> file here -- **/
        if ((fclose(pInputFile)) == EOF)
        {
            fprintf(stderr, KCOULDNOTCLOSE);
            return 1;
        }
        
        int iReturnValue = 0;
        iReturnValue = displayResult(pTempFile, kpsCmdLineArg, kpsFileMode);        

        if (iReturnValue == 2)
        {
            fprintf(stderr, KCOULDNOTOPEN);
            return 2;
        }
        else if (iReturnValue == 1)
        {   
            fprintf(stderr, KCOULDNOTCLOSE);
            return 1;
        }
    }
    return 0;
}
