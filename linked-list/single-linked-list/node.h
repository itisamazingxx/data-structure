
 

#ifndef header_file
#define header_file

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// function declaration for creating a node
Node* createNode(int val);

#endif
