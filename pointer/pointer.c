#include <stdio.h>
#include <stdlib.h>

void pointerTest() {
	// allocate three integers and two pointers
	int a = 10;
	int b = 20;
	int c = 30;
	int* p1;
	int* p2;
	p1 = &a;
	p2 = &b;
	
	printf("The Original Address of p1 is: %p; value = %d\n", p1, *p1);
	printf("The Original Address of p2 is: %p; value = %d\n", p2, *p2);
	printf("Current value of int c is: %d\n", c);

	c = *p1;
	p1 = p2;
        printf("After value of int c is %d\n", c);
  	printf("After address of p1 is %p; value = %d\n", p1, *p1);

        *p1 = 13;
        printf("p1 address: %p; value: %d\n", p1, *p1);
        printf("p2 address: %p; value: %d\n", p2, *p2);
}

int main() {
	pointerTest();
	return 0;
}
