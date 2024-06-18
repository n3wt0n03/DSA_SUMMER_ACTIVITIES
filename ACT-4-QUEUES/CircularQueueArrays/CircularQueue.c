#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//typedef struct {
//	int data[MAX];
//	int front;
//	int rear;
//}CircularQ;

CircularQ initQueue(void){
	CircularQ CQ;
	
	// initially put empty values
	int i;
	for(i = 0; i < MAX; i++){
		CQ.data[i] = EMPTY;
	}
	
	CQ.front = 0;
	CQ.rear = MAX-1;
	printf("Circular Queue initialized sucessfully\n\n");
	
	return CQ;
}

void enqueue(CircularQ *CQ, int data){
	if(!isFull(*CQ)){
		CQ->rear = (CQ->rear + 1) % MAX;
		CQ->data[CQ->rear] = data;	
	} else {
		printf("Queue is already full! Can't insert data %d\n", data);
	}
}

void dequeue(CircularQ *CQ){
	if(!(isEmpty(*CQ))){
		CQ->front = (CQ->front + 1) % MAX;
	} else {
		printf("Queue is already empty! Insert more data\n");
	}
}

//int front(CircularQ CQ);
//int rear(CircularQ CQ);
bool isEmpty(CircularQ CQ){
	return (CQ.rear + 1) % MAX == CQ.front ? true : false;
}

bool isFull(CircularQ CQ){
	return (CQ.rear + 2) % MAX == CQ.front ? true : false;
}

void display(CircularQ CQ){
	int i;
	printf("Value of front: %d\n", CQ.data[CQ.front]);
	printf("Value of rear: %d\n", CQ.data[CQ.rear]);
	for(i = CQ.front; i != CQ.rear; i = (i + 1) % MAX){
		printf("%d\n", CQ.data[i]);
	}
}

void visualize(CircularQ CQ){
	int i;
	printf("%-10s%-10s%-10s\n", "INDEX", "DATA", "FRONT/REAR");
	for(i = CQ.front; i != CQ.rear; i = (i + 1) % MAX){
		printf("%-10d%-10d", i,CQ.data[i]);
		if(i == CQ.front) {
			printf("<-- FRONT");
		}
		if(i == CQ.rear) {
			printf("<-- REAR");
		}
		printf("\n");	
	}
}


