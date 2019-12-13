/*
    FILE            :   reverseName.cpp
    PROJECT         :   None
    PROGRAMMER      :   Braiden Gole
    FIRST VERSION   :   2019-12-12
    DESCRIPTION     :   This program will take in a word
                        as user input and it will reverse it.
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{   
    // Check for command line arguments.
    if (argc < 2)
    {
        fprintf(stderr, "No <WORD> supplied !\n");
    }
    else
    {
        // A <WORD> was supplied, perform operations.
        char* wordStream = argv[1];
        size_t lengthOfWord = strlen(wordStream) - 1;

        char temp = ' '; short characters = 0;
        while (characters < lengthOfWord)
        {
            temp = wordStream[characters];
            wordStream[characters] = wordStream[lengthOfWord];
            wordStream[lengthOfWord] = temp;

            ++characters;
            --lengthOfWord;
        }

        // Output the <WORD> in reverse.
        printf("%s\n", wordStream);
    }
    return 0;
}