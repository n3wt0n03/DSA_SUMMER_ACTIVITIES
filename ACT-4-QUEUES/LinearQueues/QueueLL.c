#include "QueueLL.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

Queue* initQueue(void){
	Queue* Q = (Queue*) malloc (sizeof(Queue));
	if(Q != NULL){
		Q->front = Q->rear = NULL;
		printf("Initialization Successful!\n\n");
	} else {
		printf("Initialization Unsuccessful!\n\n");
	}
	return Q;
}

void Enqueue(Queue* Q, int data) {
	NodePtr temp = (NodePtr) malloc (sizeof(struct node));
	if(temp != NULL){
		temp->data = data;
		temp->next = NULL;
		
		if(Q->front == NULL){
			Q->front = Q->rear = temp;
		} else {
			Q->rear->next = temp;
			Q->rear = temp;
		}
	} else {
		printf("Allocation failed!!");
	}
}

void Dequeue(Queue* Q){
	if(!isEmpty(*Q)){
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
	return Q.front == NULL && Q.rear == NULL;
}


void displayQueue(Queue* Q) {
    printf("Displaying Queue(Linear):\n");
    printf("--------------------\n");

    Queue* temp = initQueue();
    while(!isEmpty(*Q)) {
        Enqueue(temp, Front(*Q));
        printf("%d -> ", Front(*Q));
        Dequeue(Q);
    }
    
    while(!isEmpty(*temp)){
    	Enqueue(Q, Front(*temp));
    	Dequeue(temp);
	}
    
    printf("NULL\n");
}

void visualize(Queue Q){
	printf("\n\nVisualization of Queue(Linear):");
	printf("\n--------------------\n");
	printf("Front Data: %d\n", Front(Q));
	printf("Rear Data: %d\n\n", Rear(Q));
	printf("%-10s%-10s%-10s\n", "NODE", "VALUE", "POSITION");
	printf("------  ---------  ----------\n");
	
	NodePtr trav;
	int elem;
	for(trav = Q.front, elem = 0; trav != NULL; trav = trav->next, elem++){
		printf("\n%-10d%-10d", elem, trav->data);
		if(trav->data == Front(Q)){
			printf("<--- FRONT");
		}
		if(trav->data == Rear(Q)){
			printf("<--- REAR");
		}
	}
	printf("\n\n\n");
}
