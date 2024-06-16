#ifndef STACK_LL
#define STACK_LL

#include <stdbool.h>

typedef struct node {
	int data;
	struct node* next;
}*StackLL;

StackLL initStack(void);		// set an empty stack
bool isEmpty(StackLL head);			//check if stack is empty
//bool isFull(Stack *list);			// Tentative to add
void push(StackLL *head, int data);	//insert from the top
void pop(StackLL *head);					//delete form the top
int peek(StackLL head);				//return the top
void display(StackLL head);				// display the top
void visualize(StackLL head);			//display the list


#endif 
