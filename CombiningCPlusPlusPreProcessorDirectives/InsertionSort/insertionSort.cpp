/**
 * @file insertionSort.cpp
 * @author Braiden Gole
 * @brief This is an insertion sort in C using C++ directives.
 * @version 0.1
 * @date 2021-02-19
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <iostream>

#define __EQ__ ==
#define __NOT__ !
#define __LSS__ <
#define __LRG__ >
#define __LRGEQ__ >=
#define MINUS -
#define ADD +
#define AND &&

#define ZERO 0
#define ONE 1
#define ERROR -1
#define SPACE ' '
#define LIMIT 20

// Function prototypes.
const double* insertionSort(double set[], const int quantity);
void display(const double set[], const int quantity);

int main(void)
{   
    int data = ZERO;
    int howManyNumbers = ZERO;

    std::cout << "\nHow many numbers would you like to insert?: ";
    if (__NOT__(std::cin >> howManyNumbers))
    {
        std::cerr << "\n\tNo characters, only numbers !\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        return ERROR;
    }

    double numbers[LIMIT] = { ZERO };

    int amountInserted = ZERO;
    bool fillWithNumbers = true;
    do
    {
        std::cout << "Enter in a number:  ";
        if (__NOT__(std::cin >> data))
        {
            std::cerr << "\n\tNo characters, only numbers !\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else
        {
            numbers[amountInserted] = data;
            ++amountInserted;

            if (amountInserted __EQ__ howManyNumbers)
            {
                break;
            }
        }
    } while (fillWithNumbers);
    
    const double* array = NULL;
    array = insertionSort(numbers, howManyNumbers);

    // Display the array.
    display(array, howManyNumbers);
    return ZERO;
}

/**     -- Function header comment
 *  FUNCTION        :   insertionSort
 *  DESCRIPTION     :   This function will perform the arithmetic of a
 *                      insertion sort.
 *  PARAMETERS      :   set, quantity
 *  RETURNS         :   None
 */
const double* insertionSort(double set[], const int quantity)
{   
    int previousIndex = ZERO;
    int currentElement = ZERO;

    for (int sort = ZERO; sort __LSS__ quantity; sort++)
    {
        currentElement = set[sort];
        
        // Collect previous indices to compare for later.
        previousIndex = (sort MINUS ONE);
        while ((set[previousIndex] __LRGEQ__ currentElement) AND (previousIndex __LRGEQ__ ZERO))
        {   
            set[previousIndex ADD ONE] = set[previousIndex];
            --previousIndex;
        }
        set[previousIndex ADD ONE] = currentElement;
    }
    return set;
}

/**     -- Function header comment
 *  FUNCTION        :   display
 *  DESCRIPTION     :   This function will display the vector.
 *  PARAMETERS      :   set
 *  RETURNS         :   None
 */
void display(const double set[], const int quantity)
{   
    for (int nums = ZERO; nums __LSS__ quantity; nums++)
    {
        std::cout << set[nums] << SPACE;
    }
}
