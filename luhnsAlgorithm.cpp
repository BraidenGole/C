/*
    FILE            :   luhnsAlgorithm.cpp
    PROJECT         :   None
    PROGRAMMER      :   Braiden Gole
    FIRST VERSION   :   2020-02-28
    DESCRIPTION     :   This is the implementation of luhns algorithm

        [ TEST NUMBER ] : 4003600000000014 is currently valid and will
        have a sum __eq__ to 20 which means there is a 0 on the end
        indicating that the credit card number was valid.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Global string constants.
#define KPROMPT_FOR_CARDNUMBER "Please enter in a credit card number: "
#define KVALID_CREDITCARD "\n\tYour credit card is VALID.\n"
#define KINVALID_CREDITCARD "\n\tYour credit card is invalid !\n\t \
Please try again...\n\n"
#define KOUT_OF_MEMORY "\n\tOut of memory !"
#define KINVALID_INPUT "\n\tInvalid input !"

// Global numeric constants.
#define KONEHUNDREDBYTES 100
#define KITHIRTEEN 13
#define KIFIFTEEN 15
#define KISIXTEEN 16

// [ Macros with parameters ]
#define KmwpQUICKDIVISION(x, y) { x /= y; }
#define KmwpMULTIBYTWO(x) { x * 2 }

// Function prototypes.
bool bLuhnsDetermination(int64_t llCardNumber, const int iAmountOfDigits);

int main(void)
{
    int64_t* pllCreditNumber = NULL;
    pllCreditNumber = (int64_t*)malloc(KONEHUNDREDBYTES);

    // Check the system for available memory.
    if (pllCreditNumber == NULL)
    { 
        printf(KOUT_OF_MEMORY);
        return 1; 
    }

    // Prompt the user to get the credit card number.
    do
    {
        printf(KPROMPT_FOR_CARDNUMBER);
        if ((fscanf(stdin, "%I64i", pllCreditNumber)) == 0)
        {
            printf(KINVALID_INPUT);
            fflush(stdin);
        }
    } while (pllCreditNumber <= 0);

    // Validate the length of the credit card.
    int iNumberOfDigits = 0; const int kiTen = 10;

    // Reference to the credit card value for parameter.
    int64_t llReferenceCardNumber = *pllCreditNumber;
    while (*pllCreditNumber != 0)
    {   
        KmwpQUICKDIVISION(*pllCreditNumber, kiTen);
        ++iNumberOfDigits;
    }
    const int kiCardLength = iNumberOfDigits;

    // Checking to see if the credit card length is [ NOT ] 13, 15, or 16.
    if ((kiCardLength != KITHIRTEEN) &&
     (kiCardLength != KIFIFTEEN) && (kiCardLength != KISIXTEEN))
    {
        printf(KINVALID_CREDITCARD);
        main();
    }
    else
    {   
        // The credit card is of the proper length, continue.
        if ((bLuhnsDetermination(llReferenceCardNumber, kiCardLength)) != true)
        {
            printf(KINVALID_CREDITCARD);
            main();
        }
        else { printf(KVALID_CREDITCARD); }
    }
    
    // Free the dynamically allocated memory from the variable.
    free(pllCreditNumber);
    return 0;
}

/*
    FUNCTION        :   bLuhnsDetermination
    DESCRIPTION     :   This function will "determine" whether a 0
                        was found on the end of the total sum of
                        products and elements if so, then the
                        credit card is considered valid.
    PARAMETERS      :   llCardNumber, kiAmountOfDigits
    RETURNS         :   true, false
*/
bool bLuhnsDetermination(int64_t llCardNumber, const int kiAmountOfDigits)
{   
    int ariSingleDigits[kiAmountOfDigits] = { 0 };

    int iTempDigit = 0;
    int iDigits = 0; const int kiTen = 10;
    while (llCardNumber != 0)
    {   
        /*
            Break off each single digit and insert the credit card digits
            into an array to then be unpacked.
        */
        iTempDigit = llCardNumber % kiTen;
        ariSingleDigits[iDigits] = iTempDigit;
        KmwpQUICKDIVISION(llCardNumber, kiTen);
        ++iDigits;
    }

    // [NOTE]: Credit card number is inserted in reverse.
    int iSumOfBrokenNum = 0;
    int iCardDigits = 0; int iCheckDigit = 0;
    int iTotalSum = 0; int iEvenSum = 0; int iOddSum = 0;
    while (iCardDigits < kiAmountOfDigits)
    {   
        // Filter every even indice.
        if ((iCardDigits % 2) == 1)
        {   
            // Check each digit to see if it is not LARGER THAN 9.
            iCheckDigit = KmwpMULTIBYTWO(ariSingleDigits[iCardDigits]);
            if (iCheckDigit > 9)
            {
                // Break the number LARGER THAN 10 and split it 10 = (1 + 0).
                iSumOfBrokenNum += iCheckDigit % kiTen;
                iSumOfBrokenNum += iCheckDigit / kiTen;
                iEvenSum += iSumOfBrokenNum;
            }
            else { iEvenSum = iCheckDigit; }
            // end check.
        }
        else
        {   
            iOddSum += ariSingleDigits[iCardDigits];
            iOddSum += iEvenSum;
        }
        ++iCardDigits;
    }
    iTotalSum = iEvenSum + iOddSum;
    
    // Check the total for a 0 at the end of the sum.
    if ((iTotalSum % kiTen) == 0) { return true; }
    else { return false; }
    return false;
}