#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include"arraylist.h"

/**
 * Retrieves the value at the specified index in the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @param index Index of the element to retrieve
 * @return Value at the specified index, or NULL if index is out of bounds
 */
char* get(ArrayList* list, int index) {
    if (index < 0 || index >= list->num_elements) return NULL;
    return list->nodes[index]->value;
}

/**
 * Removes the element at the specified index from the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @param index Index of the element to remove
 */
void removeAt(ArrayList* list, int index) {
    if (index < 0 || index > list->num_elements) return;
    for (int i = index; i < list->num_elements - 1; i++) {
        list->nodes[i] = list->nodes[i+1];
    }
    list->num_elements--; 
}

/**
 * Creates a new ArrayList with the specified initial size.
 *
 * @param size Initial size of the ArrayList
 * @return Pointer to the newly created ArrayList
 */
ArrayList* create(int size) {
    ArrayList* arr = (ArrayList*)malloc(sizeof(ArrayList));
    Node** nodes = (Node**)malloc(sizeof(Node*)*size);
    for (int i = 0; i < size; i++) {
        nodes[i] = NULL;
    }
    arr->nodes = nodes;
    arr->num_elements = 0;
    arr->size = size;
    return arr;  
}

ArrayList* resize(ArrayList* list) {
    int newSize = list->size * 2;
    ArrayList* newList = create(newSize);
    for (int i = 0; i < list->size; i++) {
        newList->nodes[i] = list->nodes[i]; // shallow copy, 后续释放内存会出错
    }
    newList->num_elements = list->size;
    for (int i = 0; i < list->size; i++) {
        list->nodes[i] = NULL; // 避免双重释放
    }
    destroyList(list);
    return newList;
}

/**
 * Adds a new element with the specified value to the end of the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @param value Value to add to the ArrayList
 * @return Pointer to the ArrayList after adding the element
 */
ArrayList* add(ArrayList* list, char* value) {
    if (list->num_elements == list->size) {
        list = resize(list);
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    list->nodes[list->num_elements++] = node;
    return list;
}

/**
 * Destroys the ArrayList and frees up memory.
 *
 * @param list Pointer to the ArrayList to be destroyed
 */
void destroyList(ArrayList* list) {
    for (int i =0 ; i < list->size; i++) {
        if(list->nodes[i] != NULL) {
            free(list->nodes[i]);
        }
    }
    if (list->nodes != NULL) {
        free(list->nodes);
    }
    free(list);
    return;
}

/**
 * Destroys a single node and frees up memory.
 *
 * @param node Pointer to the node to be destroyed
 */
void destroyNode(Node* node) {
    free(node);
    return;
}

/**
 * Returns the current size of the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @return Current size of the ArrayList
 */
int size(ArrayList* list) {
    return list->size;
}