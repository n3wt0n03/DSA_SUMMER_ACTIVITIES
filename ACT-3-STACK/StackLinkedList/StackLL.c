#include "StackLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//typedef struct node {
//	int data;
//	struct node* next;
//};

StackLL initStack(void){
	StackLL head = NULL;
	return head;
}	

bool isEmpty(StackLL head) {
	return head == NULL; 
}
			
void push(StackLL *head, int data) {
	(*head)->data = data;
}
	
void pop(StackLL *head){
	if(!isEmpty(*head)){
		StackLL temp = *head;
		*head = temp->next;
		free(temp);
	}
}

int peek(StackLL head){
	return head->data;
}

//void display(StackLL head);				// display the top
//void visualize(StackLL head);			//display the list
