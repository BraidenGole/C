/**
 * @file binSearchTree.c
 * @author Braiden Gole
 * @brief This is a binary tree search implementation.
 * 
 * NOTE: This is a simple binary tree implementation it does not support
 *       the balancing of data between branches. Suggesting that you would
 *       have to be careful to how you insert each element into the tree if you
 *       wanted a efficient balance between the left and right sides. There are algorithms
 *       to handle this situation but this is my first implementation of the algorithm
 *       and would like to keep things basic for this one.
 * 
 *       This implementation supports in order traversal and properly freeing the dynamically
 *       allocated memory from the tree using the in order traversal.
 * @version 0.1
 * @date 2021-01-06
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Header file.
#include "treeFunctions.h"

int main(void)
{   
    
    struct LeafNode* rootOfTree = NULL;
    
    rootOfTree = createLeaf(rootOfTree, 'A');
    rootOfTree = createLeaf(rootOfTree, 'B');
    rootOfTree = createLeaf(rootOfTree, 'C');
    rootOfTree = createLeaf(rootOfTree, 'D');
    rootOfTree = createLeaf(rootOfTree, 'E');
    rootOfTree = createLeaf(rootOfTree, 'F');
    rootOfTree = createLeaf(rootOfTree, 'G');
    rootOfTree = createLeaf(rootOfTree, 'H');
    rootOfTree = createLeaf(rootOfTree, 'I');
    rootOfTree = createLeaf(rootOfTree, 'J');

    bool searchForLetters = true;
    char letterToFind = 0;
    while (searchForLetters)
    {   
        printf("\nsearch or '.' to quit: ");
        letterToFind = getchar();
        getchar();
        letterToFind = toupper(letterToFind);
     
        if ((forLeafInTree(rootOfTree, letterToFind)) == true)
        {
            printf("\n\tLetter found !\n");
        }
        else
        {   
            if (letterToFind == '.')
            {
                break;
            }
            printf("\n\tLetter [NOT] found !\n");
        }
    }
    printf("\n");
    inOrderTraversal(rootOfTree);

    // Free the dynamically allocated tree.
    freeTheTree(&rootOfTree);
    return 0;
}