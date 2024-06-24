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

//void displayQueue(Queue Q){
//	printf("Displaying Queue(Linear):");
//	printf("\n--------------------\n");
//	printf("Front Data: %d\n", Front(Q));
//	printf("Rear Data: %d\n\n", Rear(Q));
//	
//	NodePtr trav;
//	for(trav = Q.front; trav != NULL; trav = trav->next){
//		printf("%d -> ", trav->data);
//	}
//	printf("NULL");	
//}


void displayQueue(Queue Q) {
    printf("Displaying Queue(Linear):\n");
    printf("--------------------\n");
    printf("Front Data: %d\n", Front(Q));
    printf("Rear Data: %d\n\n", Rear(Q));

//	Queue tempQueue = Q;
    Queue* temp = initQueue();
    while (!isEmpty(Q)) {
        Enqueue(temp, Front(Q));
        printf("%d -> ", Front(Q));
        Dequeue(&Q);
    }
    
    printf("\n");
    
    while (!isEmpty(*temp)) {
        Enqueue(&Q, Front(*temp));
        Dequeue(&temp);
    	printf("%d -> ", Front(*temp));
    }
//    

	printf("NULL\n");
    printf("\n");
}

void visualize(Queue Q){
	printf("\n\nVisualization of Queue(Linear):");
	printf("\n--------------------\n");
	printf("Front Data: %d\n", Front(Q));
	printf("Rear Data: %d\n\n", Rear(Q));
	printf("%-10s%-10s%-10s\n", "NODE", "VALUE", "POSITION");
	
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
