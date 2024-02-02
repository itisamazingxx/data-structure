
 

#include<stdio.h>
#include<stdlib.h>
#include "node.h"

// Linked-list struct
typedef struct LList {
    Node* head;
    int size;
} LList;

// create an empty Linked-list.
LList* createList() {
	// memory allocation
	LList* llist = (LList*)malloc(sizeof(LList));
	// dynamic allocation failed
	if (llist == NULL) {
		printf("Allocation failed!\n");
	}
	// initializing
	llist->head = NULL;
	llist->size = 0;

	return llist;
}

void addNode(LList* llist, int val) {
	// create a new node
	Node* newNode = createNode(val);
	// if Linked-list is empty, set the new node as head
	if (llist->head == NULL) {
		llist->head = newNode;
		llist->size++;
		return;
	}
	// normal scenario (at least one node inside linked-list)
	Node* cur = llist->head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = newNode;
	llist->size++;
}

void removeNodeAt(LList* llist, int index) {
	// return if Linked-list is empty, nothing to remove
	if (llist->head == NULL) {
		return;
	}
	// create a new pre dummy head
	Node* dummy = createNode(0);
	dummy->next = llist->head;
	Node* pre = dummy;

	// find the correct 'pre' pointer pisition
	while (index > 0 && pre->next != NULL) {
		pre = pre->next;
		index--;
	}
	// the "ready to delete" node exists
	if (pre->next != NULL) {
		Node* temp = pre->next;
		pre->next = pre->next->next;
		free(temp);
		llist->size--;
	}

	llist->head = dummy->next;
	free(dummy);
}

void removeAllNodesWithValue(LList* llist, int val) {
	if (llist->head == NULL) {
		return;
	}
	Node* dummy = createNode(0);
	dummy->next = llist->head;
	Node* pre = dummy;

	while (pre->next != NULL) {
		if (pre->next->val == val) {
			Node* temp = pre->next;
			pre->next = pre->next->next;
			free(temp);
			llist->size--;
		} else {
			pre = pre->next;
		}
	}

	// reset llinked-list head
	llist->head = dummy->next;
	free(dummy);
}

int main() {
	// creating first node
	Node* n1 = createNode(1);
	printf("the first value is %d\n", n1->val);
	// creating new list
	LList* ll = createList();
	addNode(ll, 5);
	printf("The head node of linked list is %p\n", ll->head);
	addNode(ll, 85);
	addNode(ll, 5);
	addNode(ll, 66);
	// verify the current linked-list size should be 4
	printf("The size of linked-list is %d\n", ll->size);
	removeAllNodesWithValue(ll, 5);
	// verify the current linked-list size should be 2
        printf("After removing 5, The size of linked-list is %d\n", ll->size);
	removeNodeAt(ll, 1);
	removeNodeAt(ll, 0);
	printf("final size should be %d\n", ll->size);


}
