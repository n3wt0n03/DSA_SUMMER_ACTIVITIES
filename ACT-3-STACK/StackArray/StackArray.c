#include "StackArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

StackArrayList createStack(){
	StackArrayList stack;
	stack.top = -1;
	
	printf("Successfuly created stack array\n");
}

bool isEmpty(StackArrayList s){
	return s.top == -1;
}

bool isFull(StackArrayList s){
	return s.top == MAX - 1;
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
	return s.data[s.top]; // returns the top data
}

//void display(StackArrayList s){
//	printf("\n\nDisplaying Stack:");
//	printf("\n--------------------\n\n");
//	
//	StackArrayList tempStack = createStack();
//	
//	printf("Temporary Stack: \n");
//	while(!(isEmpty(s))){
//		stack_push(&tempStack, stack_peek(s));
//		printf("\n%d", stack_peek(tempStack));
//		stack_pop(&s);
//	}
//	printf("\n");
//	
//	printf("Original Stack: \n");
//	while(!(isEmpty(tempStack))){
//		stack_push(&s, stack_peek(tempStack));
//		printf("\n%d", stack_peek(s));
//		stack_pop(&tempStack);
//	}
//}

 void visualize(StackArrayList s){
	printf("\n\nVisualization of Stack:");
	printf("\n--------------------\n\n");
	printf("Value of Top of the Stack: %d\n", s.data[s.top]);
	printf("%-10s%-10s\n", "Index", "Value");
	
	int i;
	for(i = 0; i < MAX; i++){
		printf("%-10d%-10d\n", i, s.data[i]);
	}
	
 }
// others
// create a function that would get all even numbers and return as a new stack removing from the old stack

