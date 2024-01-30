# Pointers

** Bad Pointer **
> When a pointer is first allocated, it does not have a pointee.
> "uninitialized pointer"; "bad pointer"
```c
int *p;
```

** Pointer Test Example **

```c
int a = 10;
int b = 20;
int c = 30;
int* p1;
int* p2;
p1 = &a;
p2 = &b;
```
```
The Original Address of p1 is: 0x7ff7b6a0e88c; value = 10
The Original Address of p2 is: 0x7ff7b6a0e888; value = 20
Current value of int c is: 30
```
```c
c = *p1;
p1 = p2;
```
```
After value of int c is 10
After address of p1 is 0x7ff7b6a0e888; value = 20
```
```c
*p1 = 13;
```
p1 address: 0x7ff7b6a0e888; value: 13
p2 address: 0x7ff7b6a0e888; value: 13
```

