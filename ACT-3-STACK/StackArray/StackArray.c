#include "StackArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

StackArrayList createStack(){
	StackArrayList stack;
	stack.top = -1;
	
	// Initialize all values to 0
	int i;
	for(i = 0; i < MAX; i++){
		stack.data[i] = 0;
	}
	
	return stack;
//	printf("Successfuly created stack array\n");
}

bool isEmpty(StackArrayList s){
	return (s.top == -1) ? true : false;
}

bool isFull(StackArrayList s){
	return (s.top == MAX - 1) ? true : false;
}

bool stack_push(StackArrayList *s, int elem){
	if(!isFull(*s)) {
		s->top++;
		return s->data[s->top] = elem;	
	}
//	printf("Successfuly pushed elem %d inside the stack\n", s->data[s->top]); 
}

bool stack_pop(StackArrayList *s){
//	printf("Popping elem %d inside the stack\n", s->data[s->top]);
	if(!isEmpty(*s)){
		return s->top--;
	}
}

int stack_peek(StackArrayList s){
	return (!isEmpty(s)) ? s.data[s.top] : -1; // returns the top data
}

void display(StackArrayList s){
	printf("Displaying Stack:");
	printf("\n--------------------\n");
	
	StackArrayList tempStack = createStack();
	
	printf("Original Stack: \n");
	while(!(isEmpty(s))){
		stack_push(&tempStack, stack_peek(s));
		printf("\n%d", stack_peek(tempStack));
		stack_pop(&s);
	}
	printf("\n");
	
	printf("\nRestoring Stack to its Previous Form: \n");
	while(!(isEmpty(tempStack))){
		stack_push(&s, stack_peek(tempStack));
		printf("\n%d", stack_peek(s));
		stack_pop(&tempStack);
	}
	printf("\n");
}

 void visualize(StackArrayList s){
	printf("\n\nVisualization of Stack:");
	printf("\n--------------------\n");
	printf("Value of Top of the Stack: %d\n\n", s.data[s.top]);
	printf("%-10s%-10s%-10s\n", "INDEX", "VALUE", "POSITION");
	
	int i;
	for(i = 0; i < MAX; i++){
		printf("\n%-10d%-10d", i, s.data[i]);
		if(s.data[i] == stack_peek(s)){
			printf("<-- TOP");
		}
	}
	
 }
 
// Other Functions
// create a function that would get all even numbers and return as a new stack removing from the old stack
StackArrayList createStackEven(StackArrayList *s){
	StackArrayList stackEven = createStack();
	StackArrayList tempStack = createStack();
	
	printf("\n\nCreating a new stack with even numbers: \n\n");
	while(!(isEmpty(*s))){
		if(s->data[s->top] % 2 == 0){
			stack_push(&stackEven, stack_peek(*s));
		} else {
			stack_push(&tempStack, stack_peek(*s));
		}
		stack_pop(s);
	}
	
	while(!(isEmpty(tempStack))){
		stack_push(s, stack_peek(tempStack));
		stack_pop(&tempStack);	
	}	
	
	return stackEven;
}

