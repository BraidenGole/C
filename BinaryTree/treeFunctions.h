/**
 * @file treeFunctions.h
 * @author Braiden Gole
 * @brief 
 * @version 0.1
 * @date 2021-01-06
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _KTREEFUNCTIONS
#define _KTREEFUNCTIONS "treeFunctions.h"

struct LeafNode
{
    char leafLetter;
    struct LeafNode* leftTree;
    struct LeafNode* rightTree;
};

// Function prototypes.
struct LeafNode* createLeaf(struct LeafNode* root, char data);
const bool forLeafInTree(struct LeafNode* root, const char letterData);
void inOrderTraversal(struct LeafNode* root);
void freeTheTree(struct LeafNode** root);
#endif