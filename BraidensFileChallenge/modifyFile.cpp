/*
    FILE            :   modifyFile.cpp
    PROJECT         :   None
    PROGRAMMER      :   Braiden Gole
    FIRST VERSION   :   2019-12-29
    DESCRIPTION     :   This is a demonstration of the use of files. I have created
                        a small exercise for myself so I can meet some sort of set
                        of requirements in the case I get asked to perform some 
                        operations on a file I will already have a good idea as to
                        what I am doing.

    INSTRUCTIONS:

        Step #1: After the file is opened, control the output to 90 characters '\n'.
        Step #2: Double-space every line of the file.
        Step #3: Count the number of upperCase & lowerCase characters.
        Step #4: Switch any upperCase letter to a lowerCase vice versa.
        Step #5: Count the occurrences of each symbol listed here: 
        | ',' | '.' | '?' | '!' | '#' | '%' |.

        Step #6: If a symbol is [ NOT ] in the list of symbols, then store this
        character as a "Garbage character". "Garbage characters" are to be stored
        in a garbageCharacters[] array, followed by a macro called [KALOTOFGARBAGE 50].

        Step #7: Print all of the garbage symbols with a set of [%c] square brackets
        around it.

        Step #8: Display a "File Summary:" of all the counts of characters that were
        found. NOTE: Keep the display of the "Garbage Characters" at the bottom and
        separated with one '\n' from all of the other results.

        Step #9: Close the <inputFile> and end the program.

        ======================
            GENERAL NOTE
        ======================

        EXTRA: Feel free to add your own personal twist on the <outputFile> to make the
        contents more readable or presentable, try to keep this logical.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KALOTOFGARBAGE 50
#define KLIMITOFSYMBOLS 7

int main(int argc, char* argv[])
{   
    // Check to see if the user supplied a <inputFile>.
    if (argc < 2)
    {
        fprintf(stderr, "\nNo <inputFile> supplied !\n");
        return 1;
    }
    else
    {
        // A <inputFile> is present, open the file(s).

        //=========================== <inputFile> ==================================
        FILE* pCmdLineArgument = fopen(argv[1], "r");
        //=========================== <outputFile> =================================
        FILE* pFileToWriteTo = fopen("writeToMe.txt", "w+");

        // Check to see if the file opened.
        if (pCmdLineArgument == NULL || pFileToWriteTo == NULL)
        {
            fprintf(stderr, "\nFile could [ NOT ] be open at this time.\n");
            return 1;
        }
        else
        {
            // The <inputFile> is opened, ready to modify.
            // The <outputFile> is opened, ready to modify.

            // Read the contents of the <inputFile>.
            short contentsOfFile = 0; short kBreakEveryNinety = 89; 
            
            // Count variables.
            short numberOfCharacters = 0; short numberOfTotalSymbols = 0;
            short numberOfUpperCaseChars = 0; short numberOfLowerCaseChars = 0;
            short numberOfCommas = 0; short numberOfPeriods = 0; 
            short numberOfQuestionMarks = 0; short numberOfExclamationMarks = 0;
            short numberOfHashes = 0; short numberOfPercentSymbols = 0;
            short numberOfGarbageChars = 0;

            // Declare the garbageCharacters[] array.
            char garbageCharacters[KALOTOFGARBAGE] = {""};

            fprintf(pFileToWriteTo, "\n%s", ">>> File Contents Below\t[ MODIFIED ]: \n");
            fprintf(pFileToWriteTo, "%s%s", "==================================",
            "======================================================================\n\n");
            while ((contentsOfFile = (fgetc(pCmdLineArgument))) != EOF)
            {
                // [ Step #1 ]

                // New-line every 90 characters.
                if (numberOfCharacters > kBreakEveryNinety)
                {
                    // Start the count over so we can count to 90 again '\n'.
                    numberOfCharacters = 0;

                    // [ Step #2 ]

                    // Double-space the contents of the file.
                    fprintf(pFileToWriteTo, "%s", "\n\n");
                }

                // [ Step #3 ] & [ Step #4 ]

                // Count the number of uppercase characters.
                if (isupper(contentsOfFile) > 0)
                {   
                    // Write the converted lowercase characters to the <outputFile>.
                    fprintf(pFileToWriteTo, "%c", tolower(contentsOfFile));
                    ++numberOfUpperCaseChars;
                }
                else if (islower(contentsOfFile) > 0)
                {   
                    // Write the converted uppercase characters to the <outputFile>.
                    fprintf(pFileToWriteTo, "%c", toupper(contentsOfFile));
                    ++numberOfLowerCaseChars;
                }
                else if (isspace(contentsOfFile) != 0)
                {
                    // Write any spaces to the <outputFile>.
                    fprintf(pFileToWriteTo, "%c", contentsOfFile);
                }
                else if (ispunct(contentsOfFile) != 0)
                {   
                    // [ Step #5 ]

                    // Search for the matching symbols.
                    ++numberOfTotalSymbols;

                    // [ Step #6 ]

                    // Collect the garbage characters.
                    switch (contentsOfFile)
                    {
                        case ',':
                            ++numberOfCommas;
                            fprintf(pFileToWriteTo, "%c", contentsOfFile);
                            break;
                        case '.':
                            ++numberOfPeriods;
                            fprintf(pFileToWriteTo, "%c", contentsOfFile);
                            break;
                        case '!':
                            ++numberOfExclamationMarks;
                            fprintf(pFileToWriteTo, "%c", contentsOfFile);
                            break;
                        case '?':
                            ++numberOfQuestionMarks;
                            fprintf(pFileToWriteTo, "%c", contentsOfFile);
                            break;
                        case '#':
                            ++numberOfHashes;
                            fprintf(pFileToWriteTo, "%c", contentsOfFile);
                            break;
                        case '%':
                            ++numberOfPercentSymbols;
                            fprintf(pFileToWriteTo, "%c", contentsOfFile);
                            break;

                        // [ Step #7 ]

                        // Garbage characters below.
                        default:
                            garbageCharacters[++numberOfGarbageChars] = contentsOfFile;
                            fprintf(pFileToWriteTo, "[%c]", garbageCharacters[numberOfGarbageChars]);
                            break;
                    }
                }
                ++numberOfCharacters;

                // FOR-END-OF-FILE = break, to print the "File Summary".
                if (feof(pCmdLineArgument)) { break; }
            }

            // [ Step #8 ]

            // File Summary.
            fprintf(pFileToWriteTo, "%s%s", "\n\n==================================",
            "======================================================================");
            fprintf(pFileToWriteTo, "%s", "\nFile Summary :\n\t");
            fprintf(pFileToWriteTo, "%s[%i]", "\n\tNumber of (Commas): ", numberOfCommas);
            fprintf(pFileToWriteTo, "%s[%i]", "\n\tNumber of (Periods): ", numberOfPeriods);
            fprintf(pFileToWriteTo, "%s[%i]", "\n\tNumber of (Question Marks): ", numberOfQuestionMarks);
            fprintf(pFileToWriteTo, "%s[%i]", "\n\tNumber of (Exclamation Marks): ", numberOfExclamationMarks);
            fprintf(pFileToWriteTo, "%s[%i]", "\n\tNumber of (Hashes): ", numberOfHashes);
            fprintf(pFileToWriteTo, "%s[%i]", "\n\tNumber of (Remainders): ", numberOfPercentSymbols);
            fprintf(pFileToWriteTo, "%s[%i]", "\n\nGarbage characters: ", numberOfGarbageChars);
            fprintf(pFileToWriteTo, "%s[%i]", "\n\t\t\t\t\t\t\t[ Amount of symbols ] = ", numberOfTotalSymbols);
            fprintf(pFileToWriteTo, "%s%s", "\n==================================",
            "======================================================================");
            fprintf(pFileToWriteTo, "%s", "\n\nEdited by = [ BRAIDEN GOLE ]");
            // End file summary.

            // [ Step #9 ]
        }
        if (fclose(pFileToWriteTo) == EOF)
        {
            fprintf(stderr, "\n<outputFile> did not close properly.\n");
            return 1;
        }
        //======================= End <outputFile> =================================
        if (fclose(pCmdLineArgument) == EOF)
        {
            fprintf(stderr, "\n<inputFile> did not close properly.\n");
            return 1;
        }
        //======================= End <inputFile> ==================================
    }
    return 0;
}