/**
 * @file stackAlgorithm.h
 * @author Braiden Gole
 * @brief 
 * @version 0.1
 * @date 2021-05-01
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _STACKALGORITHM
#define _STACKALGORITHM "stackAlgorithm.h"

struct Stack
{
    int top;
    unsigned int size;
    int* numbers;
};

// Function prototypes.
int push(struct Stack* stack, int data);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
#endif