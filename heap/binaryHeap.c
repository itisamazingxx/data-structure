/**
 * In a priority queue, the highest priority items are
 * retrieved from the queue ahead of lower priority items
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

// complete binary tree
// 完全二叉树特性: left child of position p: 2p
// right child: 2p+1
// given a node at position n, the parent is at position n/2

typedef struct minHeap {
    int items[MAX_SIZE];
    int size;
} minHeap;

/**
 * Creating a new. empty binary heap
*/
minHeap* createHeap() {
    minHeap* heap = (minHeap*)malloc(sizeof(minHeap));
    heap->size = 0;
    return heap;
}

/**
 * Moving the last added element up to the heap
 * maintain heap's properties.
*/
void swiftUp(minHeap* heap) {
    int i = heap->size;
    while (i / 2 != 0) {
        if (heap->items[i] < heap->items[i/2]) {
            int temp = heap->items[i];
            heap->items[i] = heap->items[i/2];
            heap->items[i/2] = temp;
        }
        i = i / 2;
    }
}

void shiftDown(minHeap* heap, int i) {
    while (i * 2 <= heap->size) {
        int son = i * 2;
        if (i * 2 + 1 <= heap->size && heap->items[i * 2 + 1] < heap->items[son]) {
            son = i * 2 + 1;
        }
        int temp = heap->items[i];
        heap->items[i] = heap->items[son];
        heap->items[son] = temp;

        i = son;
    }
}

/**
 * add new item to the heap
*/
void add(minHeap* heap, int val) {
    heap->items[++heap->size] = val;
    swiftUp(heap);
}

/**
 * find the minimum element in heap
 * return the first element in heap
*/
int findMin(minHeap* heap) {
    return heap->items[1];
}

int deleteMin(minHeap* heap) {
    int deleted = findMin(heap);
    heap->items[1] = heap->items[heap->size];
    heap->size--;
    shiftDown(heap, 1);
    return deleted;
}

minHeap* buildHeap(int* alist, int listSize) {
    minHeap* heap = createHeap();
    for (int i = 0; i < listSize; i++) {
        heap->items[i+1] = alist[i];
        heap->size++;
    }
    for (int i = heap->size / 2; i > 0; i--) {
        shiftDown(heap, i);
    }
    return heap;
}


int main() {
    minHeap* heap1 = createHeap();

    // testing add/find function
    add(heap1, 5);
    add(heap1, 10);
    add(heap1, 1);
    add(heap1, 3);
    printf("print the heap top element should be 1\n");
    int min = findMin(heap1);
    printf("%d\n", min);
    int delete_val = deleteMin(heap1);
    printf("print the deleted value should be 1, and the current heap top should be 3\n");
    printf("%d %d\n", delete_val, heap1->items[1]);

    // verify the building heap with given list function
    int alist[] = {17, 10, 84, 19, 6, 22, 9};
    minHeap* builded = buildHeap(alist, 7);
    printf("newly minHeap with min val 6, size 7\n");
    printf("%d %d\n", builded->items[1], builded->size);
    
    return 0;
}
