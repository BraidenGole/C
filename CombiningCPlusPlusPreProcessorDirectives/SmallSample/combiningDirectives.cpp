/**
 * @file combiningDirectives.cpp
 * @author Braiden Gole
 * @brief Usually when people write (C) as in the (C) programming language
 *        they write with combined directives. This suggest that we can use
 *        #includes from (C) & (C++) both ways to get more power or maybe you
 *        have a preference of using C++ string functions rather than C string functions.
 * 
 *        Now this is really a C++ file becuase we MUST have the extension as ".cpp"
 *        in order to run C++ preprocessor directives. We MUST also compile (g++):
 *      
 *        g++ -o test combiningDirectives.cpp -Wall
 * 
 *        Instead of
 * 
 *        gcc -o test combiningDirectives.cpp -Wall
 * 
 *        We are really writting just C++ without classes, some people prefer this over just
 *        plain C but I like to keep thing separate for (C) and for C++ I will use some of the
 *        directives that C has to offer because I am more familiar with them at the moment
 *        so this is an advantage we have with using C++ preprocessor directives.
 *        
 *        The main benefit of this is that we get the power of C++ in the C programming
 *        language that is what make C so special.
 * 
 *        Here are some common C and C++ preprocessor directives that you can reference
 *        to when building a console application.
 *        -----------------------------------------------------------------------------
 *        // C Preprocessor directives.
 *        #include <stdio.h>
 *        #include <string.h>
 *        #include <assert.h>
 *        #include <locale.h>
 *        #include <stddef.h>
 *        #include <math.h>
 *        #include <stdint.h>
 *        #include <ctype.h>
 * 
 *        // C++ Preprocessor directives
 *        #include <iostream>
 *        #include <string>
 *        #include <fstream>
 *        #include <iomanip>
 *        #include <vector>
 *        #include <cstring>
 *        #include <cstdio.h>
 *        #include <cstring>
 *        #include <algorithm>
 *        -----------------------------------------------------------------------------
 * @version 0.1
 * @date 2021-02-18
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <iostream>
#include <vector>

// C Preprocessor directives.
#include <stdio.h>

#define __EQ__ ==
#define __LRGEQ__ >=
#define __LSSTH__ <
#define __NOT__ !

#define ZERO 0
#define ERROR -1
#define ONE 1

// Function prototypes.
void cvscppFunc(std::vector<int> dataSet);

int main(void)
{   
    // Lets use C++ vectors.
    std::vector<int> dataPool;
    cvscppFunc(dataPool);

    // C++ style string.
    std::string usersName = "";
    std::string reversedName = "";

    int symbols = ZERO;
    int lengthOfName = ZERO;

    // C++ Input and output.
    std::cout << "\nEnter in your name: ";
    std::cin >> usersName;

    if ((usersName.empty()) __EQ__ true)
    {
        std::cerr << "\n\tName is empty !";
        return ERROR;
    }
    else
    {   
        // Reverse users name.
        lengthOfName = usersName.length();
        printf("\nMax string size: %i ", usersName.max_size());

        for (int letters = lengthOfName - ONE; letters __LRGEQ__ ZERO; letters--)
        {
            reversedName[symbols] = usersName[letters];
            ++symbols;
        }
        // [IMPORTANT]: .c_str() is like a cast it is temporary, for example
        // if we use "return name.c_str()" it will allow you to have a return type of
        // (const char*) but if you try to print the name afterwards you will not have reference to the name.
        printf("\nYour name in reverse: %s\n", reversedName.c_str());
    }
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   cvscppFunc
 *  DESCRIPTION     :   This function demonstrates how to integrate
 *                      C++ into C code.
 *  PARAMETER       :   dataSet
 *  RETURNS         :   None
 */
void cvscppFunc(std::vector<int> dataSet)
{   
    int data = ZERO;
    bool keepAsking = true;
    do
    {
        std::cout << "Enter in a number or (-1) to quit: ";
        if (__NOT__(std::cin >> data))
        {
            std::cerr << "\n\tNo characters !\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else
        {   
            if (data __EQ__ ERROR)
            {
                return;
            }

            // Add to the vector.
            dataSet.push_back(data);
        }
    } while (keepAsking);
}