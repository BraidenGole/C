/*
    FILE            :   creditCard.cpp
    PROJECT         :   None
    PROGRAMMER      :   Braiden Gole
    FIRST VERSION   :   2019-12-17
    DESCRIPTION     :   This is the application of luhns algorithm. This does not entirely
                        validate a credit card because you would need more information in
                        order to complete full validation. This program justs outlines
                        the algorithm, just a way to practice (C).

*/
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Check to see if the user supplied a <CREDIT CARD NUMBER>.
    if (argc < 2)
    {
        fprintf(stderr, "There was not <CREDIT CARD NUMBER> supplied !\n");
        return 1;
    }
    else
    {
        // We have a <CREDIT CARD NUMBER>, perform operations.
        const short amountOfDigits = strlen(argv[1]);

        // Check the length of the <CREDIT CARD NUMBER>.
        if ((amountOfDigits != 13) && (amountOfDigits != 15) && (amountOfDigits != 16))
        {
            fprintf(stderr, "Invalid <CREDIT CARD NUMBER>, please try again...\n");
            return 1;
        }
        else
        {   
            // The <CREDIT CARD NUMBER> has a valid length, continue.
            long long creditCardNumber = 0;

            // Parse the command line argument to type (long long).
            if (sscanf(argv[1], "%lli", &creditCardNumber) == EOF)
            {
                fprintf(stderr, "The command line argument did not parse.\n");
                return 1;
            }
            else
            {
                // The command line argument is of type (long long).

                // Store the command line argument in a digit array.
                int digitArr[amountOfDigits] = { 0 };  short digits = 0;
                while (creditCardNumber != 0)
                {   
                    // This stores the digits in reverse.
                    digitArr[digits++] = creditCardNumber % 10;
                    creditCardNumber /= 10;
                }

                /*
                    Iterating through the <CREDIT CARD NUMBER> in a regular direction
                    but digits were inserted into the "digitArr[]" in reverse.
                */
                short singleInts = 0; int multiByTwo[amountOfDigits] = { 0 };
                short temp = 0; short evenSum = 0; short oddSum = 0; int total = 0;
                for (singleInts; singleInts < amountOfDigits; singleInts++)
                {   
                    // Filter the even decimal places.
                    if (singleInts % 2 == 0)
                    {   
                        evenSum += digitArr[singleInts];
                    }
                    // Filter the odd decimal places.
                    else
                    {   
                        // Multiply each digit by two then add the products.
                        temp = digitArr[singleInts] * 2;

                        /*
                            Check each product to ensure that it does not have more
                            than one decimal place for a single digit.

                            Example: 2 x 6 = (12), take (12) and split to [1 + 2].
                        */
                        if (temp > 9)
                        {   
                            multiByTwo[singleInts] += temp / 10;
                            multiByTwo[singleInts] += temp % 10;
                        }
                        else
                        {
                            multiByTwo[singleInts] = temp;
                        }

                        oddSum += multiByTwo[singleInts];
                    }
                }

                // Assign the total of the sum.
                total = oddSum + evenSum;

                // Check the sum to see if there is a 0 at the end of the number.
                if (total % 10 != 0)
                {
                    fprintf(stderr, "Sorry this is not a valid <CREDIT CARD NUMBER>.\n");
                    return 1;
                }
                else
                {   
                    // The <CREDIT CARD NUMBER> is valid, continue.

                    /*
                        Get the first two digits to compare. The first two digits of
                        a <CREDIT CARD NUMBER> determine what bank firm a specific user
                        is associated with.   
                    */
                    int firstDigit = digitArr[amountOfDigits - 1];
                    int secondDigit = digitArr[amountOfDigits - 2];

                    short iter = 0;

                    int mastrCard[KMAX_SIZEOF_ARRAY] = { 1, 2, 3, 4, 5, 222100-272099 };

                    // =======================  VISA  ========================
                    if (firstDigit == 4)
                    {
                        printf("VISA\n");
                        return 0;
                    }
                    // ==================== MASTERCARD =======================
                    else if ((firstDigit == 5))
                    {   
                        for (iter; iter < KMAX_SIZEOF_ARRAY; ++iter)
                        {
                            if (secondDigit == iter)
                            {
                                printf("MASTERCARD\n");
                                return 0;
                            }
                        }
                    }
                    // ================== AMERICAN EXPRESS ===================
                    else if (firstDigit == 3)
                    {
                        if ((secondDigit == 4) || (secondDigit == 7))
                        {
                            printf("AMERICAN EXPRESS\n");
                            return 0;
                        }
                    }
                    else
                    {
                        fprintf(stderr, "This credit card type is not supported !\n");
                        return -1;
                    }
                }
            }
        }
    }
    return 0;
}
