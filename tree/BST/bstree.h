#include <stdbool.h>
#ifndef BSTREENODE_H
#define BSTREENODE_H

/**
 * Structure of Binary Search tree node
*/
typedef struct BSTreeNode {
    int value;
    struct BSTreeNode* left;
    struct BSTreeNode* right;
} BSTreeNode;

/**
 * Creates a new Binary Search tree node
*/
BSTreeNode* createNode(int value);

/**
 * Frees the allocation memory for the Binary Search Tree
*/
void freeBST(BSTreeNode* node);

/**
 * Inserts a new node into Binary Search tree
 * Returns true if success, false if value already exists & node doesn't exist
*/
BSTreeNode* insert(BSTreeNode* node, int value);

/**
 * Searches inside a Binary Search tree
 * returns the node if exists, NULL otherwise
*/
BSTreeNode* search(BSTreeNode* node, int value);

/**
 * Deletes a node with given value inside a Binary Search tree
 * Returns true if success, false otherwise
*/
BSTreeNode* deleteNode(BSTreeNode* node, int value);

/**
 * Returns Binary Search tree in inorder
*/
void inorder(BSTreeNode* node);

/**
 * Finds the Kth smallest element in the Binary Search tree
*/
BSTreeNode* findKthSmallest(BSTreeNode*, int k);

#endif
