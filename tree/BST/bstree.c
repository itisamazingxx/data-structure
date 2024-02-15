#include "bstree.h"
#include<stdio.h> // For printf...etc
#include<stdlib.h> // For malloc

/**
 * Creates a new Binary Search tree node
*/
BSTreeNode* createNode(int value) {
    BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Frees the allocation memory for the Binary Search Tree
*/
void freeBST(BSTreeNode* node) {
    if (node == NULL) {
        return;
    }
    freeBST(node->left);
    freeBST(node->right);
    free(node);
}

/**
 * Inserts a new node into Binary Search tree
 * Returns true if success, false if value already exists & node doesn't exist
*/
BSTreeNode* insert(BSTreeNode* node, int value) {
    if (node == NULL) {
        node = createNode(value);
        return node;
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } 
    return node;     
}

/**
 * Searches inside a Binary Search tree
 * returns the node if exists, NULL otherwise
*/
BSTreeNode* search(BSTreeNode* node, int value) {
    if (node == NULL || node->value == value) {
        return node;
    }
    if (value < node->value) {
        return search(node->left, value);
    } else if (value > node->value) {
        return search(node->right, value);
    }
    return NULL;
}

/**
 * Deletes a node with given value inside a Binary Search tree
 * Returns true if success, false otherwise
*/
BSTreeNode* deleteNode(BSTreeNode* node, int value) {
    if (node == NULL) {
        return NULL;
    }
    if (value < node->value) {
        return deleteNode(node->left, value);
    } else if (value > node->value) {
        return deleteNode(node->right, value);
    } else {
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }
        else if (node->left != NULL && node->right == NULL) {
            BSTreeNode* temp = node->left;
            free(node);
            return temp;
        }
        else if (node->left == NULL && node->right != NULL) {
            BSTreeNode* temp = node->right;
            free(node);
            return temp;
        }
        BSTreeNode* temp = node->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        node->value = temp->value;
        node->right = deleteNode(node->right, temp->value);
    }
    return node;
}

/**
 * Finds the Kth smallest element in the Binary Search tree
*/
// BSTreeNode* findKthSmallest(BSTreeNode*, int k);

/**
 * Returns Binary Search tree in inorder
*/
void inorder(BSTreeNode* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d\n", node->value);
    inorder(node->right);
}

int main() {
    BSTreeNode* node = createNode(60);
    insert(node, 45);
    insert(node, 89);
    insert(node, 23);
    inorder(node);

    printf("\n");

    BSTreeNode* expected = search(node, 23);
    printf("%d\n", expected->value);

    printf("\n");

    deleteNode(node, 60);
    inorder(node);
    freeBST(node);
    return 0;
}




