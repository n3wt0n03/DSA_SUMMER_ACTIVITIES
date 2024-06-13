#include "StackArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

StackArrayList createStack(){
	StackArrayList stack;
	stack.top = -1;
	
	printf("Successfuly created stack array\n");
}

bool stack_push(StackArrayList *s, int elem){
	s->top++;
	s->data[s->top] = elem;	
	
	printf("Successfuly pushed elem %d inside the stack\n", s->data[s->top]);
	return true; 
}

bool stack_pop(StackArrayList *s){
	printf("Popping elem %d inside the stack\n", s->data[s->top]);
	s->top--;
	return true; 
}

int stack_peek(StackArrayList s){
	return s.data[s.top]; // returns the top data
}

void display(StackArrayList s){
	StackArrayList tempStack;
	int i;
	
	for(i = 0; i != -1; ){		
		stack_push(&tempStack, s.data[top]);
		stack_pop(&s);
	}
	
	printf("\n\nDisplaying Stack:");
	printf("\n--------------------\n");
	
//	for(i = 0; i < s.top; i++){
//		printf("%d\n", tempArr[i]);
//	}
}
//
//void visualize(StackArrayList s); // can traverse the array but display the value and its index and its top

// others
// create a function that would get all even numbers and return as a new stack removing from the old stack

