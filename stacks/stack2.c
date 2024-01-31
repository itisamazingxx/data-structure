#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack structure
typedef struct Stack {
	int items[MAX_SIZE];
	int top;
} Stack;

// Initializing an empty Stack
Stack* createStack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
	return stack;
}

void push(Stack* s, int val) {
	if (s->top == MAX_SIZE - 1) {
       		printf("Stack Overflow\n");
        	return;
    	}
	s->items[++s->top] = val;
	printf("pushed value = %d\n", val);
}

int pop(Stack* s) {
	if (s->top == -1) {
		printf("Stack Underflow");
		return -1;
	}
	return s->items[s->top--];
}

int main() {
	Stack* s1 = createStack();
	push(s1, 10);
	push(s1, 20);
	pop(s1);
	pop(s1);
	// verify stack underflow
	pop(s1);
	return 0;
}
