#include<stdio.h>
#include<stdlib.h>
#include"arraylist.h"

/**
 * Retrieves the value at the specified index in the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @param index Index of the element to retrieve
 * @return Value at the specified index, or NULL if index is out of bounds
 */
char* get(ArrayList* list, int index) {
    if(index > list->num_elements) return "OUT_OF_BOUNDS_EXCEPTION";
    if(list->nodes == NULL 
        || list->nodes[index] == NULL) return NULL;
    return list->nodes[index]->value;
}

/**
 * Removes the element at the specified index from the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @param index Index of the element to remove
 */
void removeAt(ArrayList* list, int index) {
    if(index > list->num_elements) return;
    if(list->nodes[index] == NULL) return;
    list->nodes[index] = NULL;
    list->size--;
}

/**
 * Creates a new ArrayList with the specified initial size.
 *
 * @param size Initial size of the ArrayList
 * @return Pointer to the newly created ArrayList
 */
ArrayList* create(int size) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    Node** nodes = (Node**)malloc(sizeof(Node*) * size);
    int i;
    for(i=0; i<size; i++) {
        nodes[i] = NULL;
    }
    list->nodes = nodes;
    list->size = 0;
    list->num_elements = size;
    return list;
}

/**
 * Adds a new element with the specified value to the end of the ArrayList.
 *
 * @param list Pointer to the ArrayList
 * @param value Value to add to the ArrayList
 * @return Pointer to the ArrayList after adding the element
 */
ArrayList* add(ArrayList* list, char* value) {
    ArrayList* res;
    if(list->size == list->num_elements) { //resize if array is at max size
        ArrayList* l = create(list->size * 2);
        int i;
        for(i=0; i<list->size; i++) {
            l->nodes[i] = list->nodes[i];
        }
        l->size = list->size;
        l->num_elements = list->num_elements * 2;
        res = l;
        free(list->nodes); //must free the nodes since we're no longer using that array
        free(list); //must free the list since we've reassigned, but we still need the nodes
    } else {
        res = list;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    res->nodes[res->size] = node;
    res->size = res->size+1;
    return res;
}

/**
 * Destroys the ArrayList and frees up memory.
 *
 * @param list Pointer to the ArrayList to be destroyed
 */
void destroyList(ArrayList* list) {
    int i;
    for(i=0; i<list->size; i++) {
        if(list->nodes[i] != NULL) {
            free(list->nodes[i]);
        }
    }
    if(list->nodes != NULL) {
        free(list->nodes);
    }
    free(list);
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
