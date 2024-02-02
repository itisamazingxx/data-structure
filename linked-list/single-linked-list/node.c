#include<stdio.h>
#include<stdlib.h>
#include "node.h"

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}
