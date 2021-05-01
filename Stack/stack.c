/**
 * @file stack.c
 * @author Braiden Gole
 * @brief This is a stack implementation.
 * @version 0.1
 * @date 2021-05-01
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>

#include "stackAlgorithm.h"

int main(void)
{
    struct Stack* stack = NULL;
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL)
    {
        return 1;
    }

    stack->top = -1;
    stack->size = 10;
    stack->numbers = (int*)malloc(sizeof(int) * stack->size);
    if (stack->numbers == NULL)
    {
        return 1;
    }

    printf("push: %i\n", push(stack, 1));
    printf("push: %i\n", push(stack, 2));
    printf("push: %i\n", push(stack, 3));
    printf("push: %i\n", push(stack, 4));
    printf("push: %i\n", push(stack, 5));
    printf("push: %i\n", push(stack, 6));

    printf("\nPeek: %i\n\n", peek(stack));

    printf("pop: %i\n", pop(stack));
    printf("pop: %i\n", pop(stack));
    printf("pop: %i\n", pop(stack));

    printf("\nNew Peek: %i", peek(stack));

    free(stack);
    free(stack->numbers);
    return 0;
}