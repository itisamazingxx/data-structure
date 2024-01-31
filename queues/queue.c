#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
	int items[MAX_SIZE];
	int front, end;
} Queue;


// initializing an empty queue
Queue* createQueue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = queue->end = -1;
	return queue;
}

void enqueue(Queue* q, int val) {
	if (q->end == MAX_SIZE - 1) {
		printf("queue full\n");
		return;
	}
	if (q->front == -1) {
		q->front = 0;
	}
	q->items[++q->end] = val;
	printf("enqueue value %d\n", val);
}

int dequeue(Queue* q) {
	if (q->front == -1) {
		printf("queue empty\n");
		return -1;
	}
	int val = q->items[q->front];
	if (q->front == q->end) { // scenario1: only one val in queue, set queue to empty
		q->front = q->end = -1;
	} else { // scenario2: at least 2 val, pop left
		q->front++;
	}
	return val;		
}

int main() {
	Queue* q1 = createQueue();
	enqueue(q1, 5);
	enqueue(q1, 10);
	dequeue(q1);
	dequeue(q1);
	// verify queue is empty
	dequeue(q1);
	return 0;
}


