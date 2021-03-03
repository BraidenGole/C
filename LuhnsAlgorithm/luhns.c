/**
 * @file luhns.c
 * @author Braiden Gole
 * @brief This is the implementation of luhns algorithm.
 * @version 0.1
 * @date 2021-03-03
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define ZERO 0
#define ONE 1
#define TEN 10
#define THIRTEEN 13
#define FIFTEEN 15
#define SIXTEEN 16
#define TWO 2
#define NINE 9

#define __NOT__ !
#define __NEQ__ !=
#define __EQ__ ==
#define __LSS__ <
#define __LRG__ >
#define AND &&

// Function header comment
void digitCounter(int64_t numberToBreakDown, int* digitQuantity);
const bool luhnsAlgorithm(int64_t creditCard);

int main(void)
{   
    int numOfDigits = ZERO;
    bool collectNumber = true;
    int64_t cardNumber = ZERO;
    do
    {
        printf("Please enter in your credit card number: ");
        if ((fscanf(stdin, "%I64d", &cardNumber)) __EQ__ ZERO)
        {   
            fprintf(stderr, "\nNo characters !\n");
            fflush(stdin);
        }
        else
        {
            collectNumber = false;
        }
    } while (collectNumber);

    digitCounter(cardNumber, &numOfDigits);
    if ((numOfDigits __NEQ__ THIRTEEN) AND (numOfDigits __NEQ__ FIFTEEN) AND (numOfDigits __NEQ__ SIXTEEN))
    {
        fprintf(stderr, "\nCard length invalid... Try again !\n");
        numOfDigits = ZERO;
        cardNumber = ZERO;
        main();
    }
    else
    {
        bool validCreditCard = luhnsAlgorithm(cardNumber);
        if (validCreditCard __EQ__ true)
        {
            fprintf(stdout, "\n\tValid !");
            return ZERO;
        }
        else
        {
            fprintf(stdout, "\n\tInvalid !\n");
            return ONE;
        }
    }
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   digitCounter
 *  DESCRIPTION     :   This function will take a number and break its digits
 *                      apart, each digit broken off of the original number gets
 *                      counted.
 *  PARAMETERS      :   numberToBreakDown
 *  RETURNS         :   amountOfDigits
 */
void digitCounter(int64_t numberToBreakDown, int* digitQuantity)
{   
    while (numberToBreakDown __NEQ__ ZERO)
    {
        numberToBreakDown /= TEN;
        *digitQuantity = *digitQuantity + 1;
    }
}

/**     -- Function header comment
 *  FUNCTION        :   luhnsAlgorithm
 *  DESCRIPTION     :   This function will perform the steps to luhns algorithm.
 *  PARAMETERS      :   creditCard
 *  RETURNS         :   true, false
 */
const bool luhnsAlgorithm(int64_t creditCard)
{   
    int everyOther = ZERO;
    int singleDigit = ZERO;

    int evenSum = ZERO;
    int oddSum = ZERO;
    while (creditCard __NEQ__ ZERO)
    {
        singleDigit = creditCard % TEN;

        creditCard /= TEN;
        ++everyOther;

        if (everyOther == TWO)
        {   
            everyOther = ZERO;

            singleDigit *= TWO;
            if (singleDigit __LRG__ NINE)
            {
                int one = singleDigit / TEN;
                int two = singleDigit % TEN;

                int oneSingleNumber = one + two;

                evenSum += oneSingleNumber;
            }
            else
            {
                evenSum += singleDigit;
            }
        }
        else
        {
            oddSum += singleDigit;
        }
    }

    const int totalSum = evenSum + oddSum;

    // Check the last digit in the card if it is a 0 it is valid !
    int lastDigit = totalSum % TEN;
    if (lastDigit __EQ__ ZERO)
    {
        return true;
    }
    return false;
}