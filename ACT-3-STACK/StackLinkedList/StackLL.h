#ifndef STACK_LL
#define STACK_LL

#include <stdbool.h>

typedef struct node {
	int data;
	struct node* next;
}*StackLL;

StackLL initStack(void);					// Initialize an empty stack
bool isEmpty(StackLL head);					// Check if stack is empty
//bool isFull(Stack *list);					// Tentative to add
void stack_push(StackLL *head, int data);	// Insert from the top using the insertFirst concept
void stack_pop(StackLL *head);				// Delete from the top using the deleteFirst concept
int stack_peek(StackLL head);				// Return the value of top
void display(StackLL head);					// Display the stack using a temp with a series of push and pop
void visualize(StackLL head);				// Display the stack from first node up to the last node

//others
StackLL createEvenStack(StackLL *head);		// Create a function that would get all even numbers and return as a new stack removing from the old stack


#endif  
