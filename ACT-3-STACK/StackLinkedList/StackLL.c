#include "StackLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

StackLL initStack(void){
	StackLL head = NULL;
//	printf("Initialization of Stack Successful\n");
	return head;
}	

bool isEmpty(StackLL head) {
	return head == NULL; 
}
			
void stack_push(StackLL *head, int data) {
	StackLL temp = (StackLL) malloc (sizeof(struct node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
//	printf("\nData %d pushed successfully in stack", stack_peek(*head));
}
	
void stack_pop(StackLL *head){
	if(!isEmpty(*head)){
		StackLL temp = *head;
		*head = temp->next;
		free(temp);
	}
}

int stack_peek(StackLL head){
	return head->data;
}

void display(StackLL head){
	StackLL tempStack = initStack();
	
	printf("Temporary Stack:\n");
	while(!isEmpty(head)){
		stack_push(&tempStack, stack_peek(head));
		printf("%d\n", stack_peek(tempStack));
		stack_pop(&head);
	}
	
	printf("Original Stack: \n");
	while(!isEmpty(tempStack)){
		stack_push(&head, stack_peek(tempStack));
		printf("%d\n", stack_peek(head));
		stack_pop(&tempStack);
	}
}

void visualize(StackLL head){
	printf("\n\nVisualization of Stack(Linked List):");
	printf("\n--------------------\n");
	printf("Value of Top of the Stack: %d\n\n", stack_peek(head));
	printf("%-10s%-10s\n", "Element", "Value");
	
	StackLL trav;
	int elem;
	for(trav = head, elem = 0; trav != NULL; trav = trav->next, elem++){
		printf("%-10d%-10d\n", elem, trav->data);
	}
}
