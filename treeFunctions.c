/**
 * @file treeFunctions.c
 * @author Braiden Gole
 * @brief This is a binary tree search implementation.
 * @version 0.1
 * @date 2021-01-06
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Header file.
#include "treeFunctions.h"

/**     -- Function header comment
 *  FUNCTION        :   createLeaf
 *  DESCRIPTION     :   This is a function that will create a leaf node
 *                      for a binary search tree, this function will also
 *                      handle the insertion of the node.
 *  PARAMETERS      :   root, data
 *  RETURNS         :   root
 */
struct LeafNode* createLeaf(struct LeafNode* root, char data)
{
    struct LeafNode* newLeaf = NULL;
    newLeaf = (struct LeafNode*)malloc(sizeof(struct LeafNode));
    if (newLeaf == NULL)
    {
        return NULL;
    }

    newLeaf->leafLetter = data;
    newLeaf->leftTree = NULL;
    newLeaf->rightTree = NULL;

    // If the tree is empty insert the root node.
    struct LeafNode* currentLeaf = NULL;
    struct LeafNode* parentLeaf = NULL;

    if (root == NULL)
    {
        root = newLeaf;
        return root;
    }

    // Set a pointer after the first node to make sure
    // that we can trace this pointer and the move to the next point
    // depending on what value is inserted.
    currentLeaf = root;

    int newLeafDataAsciiVal = 0;
    int argumentDataAsciiVal = 0;
     
    newLeafDataAsciiVal = (int)currentLeaf->leafLetter;
    argumentDataAsciiVal = (int)data;
    
    bool insertLeaf = true;
    while (insertLeaf)
    {   
        // This is our parent node that will keep track of the current node.
        parentLeaf = currentLeaf;
        if (newLeafDataAsciiVal > argumentDataAsciiVal)
        {
            currentLeaf = currentLeaf->leftTree;
            if (currentLeaf == NULL)
            {
                parentLeaf->leftTree = newLeaf;
                insertLeaf = false;
            }
        }
        else
        {
            currentLeaf = currentLeaf->rightTree;
            if (currentLeaf == NULL)
            {
                parentLeaf->rightTree = newLeaf;
                insertLeaf = false;
            }
        }
    }
    return root;
}

/**     -- Function header comment
 *  FUNCTION        :   forLeafInTree
 *  DESCRIPTION     :   This function will search the binary tree to
 *                      find the potential leaf that matches the corresponding
 *                      letter data passed in.
 *  PARAMETERS      :   root, letterData
 *  RETURNS         :   true, false
 */
const bool forLeafInTree(struct LeafNode* root, const char letterData)
{
    struct LeafNode* traverseRoot = NULL;
    traverseRoot = root;

    bool traverseTree = true;
    while (traverseTree)
    {   
        // Cycle through the left tree.
        if (traverseRoot->leftTree != NULL)
        {   
            traverseRoot = traverseRoot->leftTree;
            if (traverseRoot->leafLetter == letterData)
            {
                return true;
            }
        }
        
        // Visit the root.
        if (traverseRoot->leafLetter == root->leafLetter)
        {
            if (traverseRoot->leafLetter == letterData)
            {
                return true;
            }
        }
        
        // Cycle through the right tree.
        if (traverseRoot->rightTree != NULL)
        {  
            traverseRoot = traverseRoot->rightTree;
            if (traverseRoot->leafLetter == letterData)
            {
                return true;
            }
        }
        else
        {   
            return false;
        }
    }
    return false;
}

/**     -- Function header comment
 *  FUNCTION        :   freeTheTree
 *  DESCRIPTION     :   This function will free every node in the tree in order.
 *  PARAMETERS      :   root
 *  RETURNS         :   None
 */
void freeTheTree(struct LeafNode** root)
{
    struct LeafNode* traverseRoot = NULL;
    traverseRoot = *root;

    bool traverseTree = true;
    while (traverseTree)
    {   
        // Cycle through the left tree.
        if (traverseRoot->leftTree != NULL)
        {   
            traverseRoot = traverseRoot->leftTree;
            free(traverseRoot);
        }
        
        // Visit the root.
        if (traverseRoot->leafLetter == (*root)->leafLetter)
        {
            free(traverseRoot);
        }
        
        // Cycle through the right tree.
        if (traverseRoot->rightTree != NULL)
        {  
            traverseRoot = traverseRoot->rightTree;
            free(traverseRoot);
        }
        else
        {   
            free(root);
            return;
        }
    }
}

/**     -- Function header comment
 *  FUNCTION        :   inOrderTraversal
 *  DESCRIPTION     :   This function will output the tree structure
 *                      in order traversal.
 *  PARAMETERS      :   root
 *  RETURNS         :   None
 */
void inOrderTraversal(struct LeafNode* root)
{   
    struct LeafNode* traverseRoot = NULL;
    traverseRoot = root;

    bool traverseTree = true;
    while (traverseTree)
    {   
        // Cycle through the left tree.
        if (traverseRoot->leftTree != NULL)
        {   
            traverseRoot = traverseRoot->leftTree;
            printf("%c ", traverseRoot->leafLetter);
        }
        
        // Visit the root.
        if (traverseRoot->leafLetter == root->leafLetter)
        {
            printf("%c ", traverseRoot->leafLetter);
        }
        
        // Cycle through the right tree.
        if (traverseRoot->rightTree != NULL)
        {  
            traverseRoot = traverseRoot->rightTree;
            printf("%c ", traverseRoot->leafLetter);
        }
        else
        {
            return;
        }
    }
}