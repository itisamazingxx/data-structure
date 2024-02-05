#include <stdio.h>
#include <stdlib.h>

/**
 * BST property: 
 * for each node, all nodes in its left subtree must have values less than the node's value
 * and all nodes in its right subtree must have values greater than the node's value.
*/

typedef struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
    
} treeNode;

treeNode* createNode(int val) {
    treeNode* BSTree = (treeNode*)malloc(sizeof(treeNode));
    BSTree->val = val;
    return BSTree;
}

/**
 * preorder traversal
 * for error checking
*/
void preOrder(treeNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%d\n", node->val);
    preOrder(node->left);
    preOrder(node->right);
}

/**
 * insert into a binary search tree
*/
treeNode* insertNode(treeNode* node, int val) {
    if (node == NULL) {
        node = createNode(val);
        return node;
    }
    if (val < node->val) {
        node->left = insertNode(node->left, val);
    }
    if (val > node->val) {
        node->right = insertNode(node->right, val);
    }
    return node;
}

treeNode* searchNode(treeNode* node, int val) {
    if (node == NULL || node->val == val) {
        return node;
    }
    if (val < node->val) {
        return searchNode(node->left, val);
    }
    if (val > node->val) {
        return searchNode(node->right, val);
    }
    return NULL;
}

treeNode* deleteNode(treeNode* node, int val) {
    if (node == NULL) {
        return NULL; // value not found; node doesn't exist
    }
    if (val < node->val) {
        node->left = deleteNode(node->left, val); 
    }
    else if (val > node->val) {
        node->right = deleteNode(node->right, val); 
    }
    else {// value found in tree
        if (node->left == NULL && node->right == NULL) {
            return NULL;
        }
        else if (node->left != NULL && node->right == NULL) {
            return node->left;
        }
        else if (node->left == NULL && node->right != NULL) {
            return node->right;
        }
        else { // deleted node has two childs
            treeNode* cur = node->right;
            while (cur->left) {
                cur = cur->left; // find the min element in right subtree
            }
            cur->left = node->left;
            node = node->right;
            return node;
        }
    }
    return node;
}

int main() {
    // verify the insert function
    treeNode* bst = createNode(5);
    insertNode(bst, 10);
    insertNode(bst, 1);
    insertNode(bst, 4);
    preOrder(bst);

    // verify the search function
    treeNode* searched = searchNode(bst, 4);
    printf("true, return node val should be 4\n");
    printf("%d\n", searched->val);

    // verify the delete function
    treeNode* deleted = deleteNode(bst, 5);
    printf("after remove, new root 10\n");
    printf("%d\n", deleted->val);


    return 0;
}

    
