#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
		printf("\nQueue is already full! Can't insert data %d\n", data);
	}
}

void dequeue(CircularQ *CQ){
	if(!(isEmpty(*CQ))){
		CQ->front = (CQ->front + 1) % MAX;
	} else {
		printf("\nQueue is already empty! Insert more data\n");
	}
}

int front(CircularQ CQ) {
	return (!isEmpty(CQ)) ? CQ.front : -1;
}
int rear(CircularQ CQ){
	return (!isEmpty(CQ)) ? CQ.rear : -1;
}

bool isEmpty(CircularQ CQ){
	return (CQ.rear + 1) % MAX == CQ.front ? true : false;
}

bool isFull(CircularQ CQ){
	return (CQ.rear + 2) % MAX == CQ.front ? true : false;
}

void display(CircularQ CQ){
	printf("\nDisplaying Circular Queue:");
	printf("\n--------------------\n");
	int i;
	printf("Value of front: %d\n", CQ.data[front(CQ)]);
	printf("Value of rear: %d\n\n", CQ.data[rear(CQ)]);
	for(i = CQ.front; i != CQ.rear; i = (i + 1) % MAX){
		printf("%d -> ", CQ.data[i]);
	}
	printf("%d\n\n", CQ.data[i]);
}

void visualize(CircularQ CQ){
	printf("\nVisualization of Circular Queue:");
	printf("\n--------------------\n");
	int i;
	printf("%-10s%-10s%-10s\n", "INDEX", "DATA", "POSITION");
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
	printf("%-10d%-10d", i, CQ.data[i]);
    if(i == CQ.front) {
        printf("<-- FRONT");
    }
    if(i == CQ.rear) {
        printf("<-- REAR");
    }
    printf("\n");	
}
