#include "QueueLL.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

Queue* initQueue(void){
	Queue* Q = (Queue*) malloc (sizeof(struct node));
	Q->front = Q->rear = NULL;
//	printf("Initialization Successful!");

	return Q;
}

void Enqueue(Queue* Q, int data) {
	NodePtr temp = (NodePtr) malloc (sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	
	if(temp != NULL){
		if(Q->front == NULL){
			Q->front = Q->rear = temp;
		} else {
			Q->rear->next = temp;
			Q->rear = temp;
		}
	}
}

void Dequeue(Queue* Q){
	if(Q->front != NULL){
		NodePtr temp = Q->front;
		Q->front = temp->next;
		if(Q->front == NULL){
			Q->rear = NULL;
		}
		free(temp);
	} 
}
int Front(Queue Q){
	return (!isEmpty(Q)) ? Q.front->data : -1;
}
int Rear(Queue Q){
	return (!isEmpty(Q)) ? Q.rear->data : -1;
}

bool isEmpty(Queue Q){
	return (Q.front == NULL && Q.rear == NULL) ? true : false;
}

void displayQueue(Queue Q){
	NodePtr trav;
	for(trav = Q.front; trav != NULL; trav = trav->next){
		printf("%d -> ", trav->data);
	}
	printf("NULL");
	printf("\n\n");
}
