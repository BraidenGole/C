/**
 * @file stackAlgorithm.c
 * @author Braiden Gole
 * @brief This file is used to write methods that are relevant to a stack.
 * @version 0.1
 * @date 2021-05-01
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdbool.h>

#include "stackAlgorithm.h"

// Function prototypes.
bool isFull(struct Stack* stack);
bool isEmpty(struct Stack* stack);

/**     -- Function header comment
 *  FUNCTION        :   push
 *  DESCRIPTION     :   This method is responsible for pushing the data
 *                      to the stack.
 *  PARAMETERS      :   stack, data
 *  RETURNS         :   None
 */
int push(struct Stack* stack, int data)
{   
    if (isFull(stack) == true)
    {
        return -1;
    }
    stack->top += 1;
    stack->numbers[stack->top] = data;
    return stack->numbers[stack->top];
}

/**     -- Function header comment
 *  FUNCTION        :   pop
 *  DESCRIPTION     :   This method is responsible for popping the data off
 *                      of the stack.
 *  PARAMETERS      :   stack
 *  RETURNS         :   None
 */
int pop(struct Stack* stack)
{   
    if (isEmpty(stack) == true)
    {
        return -1;
    }
    int deletedNumber = stack->numbers[stack->top];
    stack->top -= 1;
    return deletedNumber;
}

/**     -- Function header comment
 *  FUNCTION        :   peek
 *  DESCRIPTION     :   This function will return the number that is on the very top
 *                      of the stack.
 *  PARAMETERS      :   stack
 *  RETURNS         :   stack->top
 */
int peek(struct Stack* stack)
{
    if (isEmpty(stack) == true)
    {
        return -1;
    }
    return stack->numbers[stack->top];
}

/**     -- Function header comment
 *  FUNCTION        :   isFull
 *  DESCRIPTION     :   This method check to see if the stack is full.
 *  PARAMETERS      :   stack
 *  RETURNS         :   true, false
 */
bool isFull(struct Stack* stack)
{
    if (stack->top == stack->size - 1)
    {
        return true;
    }
    return false;
}

/**     -- Function header comment
 *  FUNCTION        :   isEmpty
 *  DESCRIPTION     :   This method check to see if the stack is empty.
 *  PARAMETERS      :   stack
 *  RETURNS         :   true, false
 */
bool isEmpty(struct Stack* stack)
{
    if (stack->top == -1)
    {
        return true;
    }
    return false;
}

