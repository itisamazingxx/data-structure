#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct Node {
    char* value;
}Node;

typedef struct ArrayList {
    Node** nodes; // ArrayList中的nodes字段是一个指向指针的指针 其中每个Node*是指向一个Node实例的指针
    int size;
    int num_elements;
}ArrayList;

char* get(ArrayList* list, int index);

void removeAt(ArrayList* list, int index);

ArrayList* create(int size);

ArrayList* add(ArrayList* list, char* value);

void destroyList(ArrayList* list);

void destroyNode(Node* node);

#endif  // ARRAYLIST_H