#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>
#define MAX 5

typedef struct {
	int data[MAX];
	int top;
} StackArrayList;

StackArrayList createStack();

bool isEmpty(StackArrayList s);
bool isFull(StackArrayList s);

bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
int stack_peek(StackArrayList s);

void display(StackArrayList s); // can't traverse
void visualize(StackArrayList s); // can traverse the array but display the value and its index and its top

// Other Functions
StackArrayList createStackEven(StackArrayList *s); // create a function that would get all even numbers and return as a new stack removing from the old stack

#endif
