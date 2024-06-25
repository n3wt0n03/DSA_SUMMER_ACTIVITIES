#include "FCFS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void initQueue(ProcessQueue* PQ){
	PQ->front = PQ->rear = NULL;
}

void enqueueProcess(ProcessQueue* PQ, Process data){
	PtrProcNode newNode = (PtrProcNode) malloc (sizeof(ProcessNode));
	
	if(newNode != NULL){
		newNode->data = data;
		newNode->next = NULL;
		
		if(PQ->front == NULL){
			PQ->front = PQ->rear = newNode;
		} else {
			PQ->rear->next = newNode;
			PQ->rear = newNode;
		}
	}
}

Process dequeueProcess(ProcessQueue* PQ){
	Process prcs;
	PtrProcNode temp;
	if(PQ->front == NULL){
		printf("Queue is empty. Please try again.\n");
	} else {
		prcs = PQ->front->data;
		temp = PQ->front;
		PQ->front = temp->next;
		if(PQ->front == NULL){
			PQ->rear = NULL;
		}
		free(temp);
	}
	return prcs;
}

bool isEmpty(ProcessQueue PQ){
	return PQ.front == NULL && PQ.rear == NULL;
}

int Front(ProcessQueue PQ){
	return (!isEmpty(PQ)) ? PQ.front->data.processID : -1;
}

int Rear(ProcessQueue PQ){
	return (!isEmpty(PQ)) ? PQ.rear->data.processID : -1;
}

ProcessArray getProcess(void){
	ProcessArray tempArr;
	int prcsCount;
	
	printf("Enter your desired number of process: ");
	scanf("%d", &prcsCount);	
	
	int i= 0;
	int upperLetter = 65;
	while(i < prcsCount){
		tempArr.data[i].processID = i;
		tempArr.data[i].et = -1;
		tempArr.data[i].wt = -1;
		tempArr.data[i].tt = -1;
		
		printf("Process ID: %c\n", upperLetter);
		printf("Enter Arrival Time: ");
		scanf("%d", &tempArr.data[i].at);
		printf("Enter Burst Time: ");
		scanf("%d", &tempArr.data[i].bt);
		 
		printf("\n");
		upperLetter++;
		i++;
	}
	
	tempArr.dataCount = i;
	displayProcessArray(tempArr);
	
	return tempArr;
}

void displayProcessArray(ProcessArray PA){
	printf("First Come First Serve (Getting Inputs)\n");
	printf("---------------------------------------\n");
	printf("%-5s%-5s%-5s\n", "PROCESS | ", "ARRIVAL TIME | ", "BURST TIME");
	
	int i;
	for(i = 0; i < PA.dataCount; i++){
		printf("%7c | %12d | %9d\n", PA.data[i].processID+65, PA.data[i].at, PA.data[i].bt);
	}
	printf("\n\n");
}

void visualization(ProcessQueue PQ){
	printf("\n\nVisualization of Process Queue:");
	printf("\n--------------------\n");
	printf("Front Data: %c\n", 65+Front(PQ));
	printf("Rear Data: %c\n\n", 65+Rear(PQ));
	printf("%-10s%-10s%-10s\n", "NODE", "VALUE", "POSITION");
	printf("------  ---------  ----------\n");
	
	PtrProcNode trav;
	int elem;
	for(trav = PQ.front, elem = 0; trav != NULL; trav = trav->next, elem++){
		printf("\n%-10d%-10c", elem, 65+trav->data.processID);
		if(trav->data.processID == Front(PQ)){
			printf("<--- FRONT");
		}
		if(trav->data.processID == Rear(PQ)){
			printf("<--- REAR");
		}
	}
}

void executeFCFS(ProcessQueue PQ, ProcessArray PA){
	// Sort the ProcessArray based on arrival time using Selection Sort
    int i, j;
	for (i = 0; i < PA.dataCount - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < PA.dataCount; j++) {
            if (PA.data[j].at < PA.data[minIndex].at) {
                minIndex = j;
            }
        }
        // Swap the processes
        Process temp = PA.data[i];
        PA.data[i] = PA.data[minIndex];
        PA.data[minIndex] = temp;
    }
//    displayProcessArray(PA);

	// Enqueue the sorted processes into the queue
    for (i = 0; i < PA.dataCount; i++) {
        enqueueProcess(&PQ, PA.data[i]);
    }
    
//    visualization(PQ);

	printf("First Come First Serve (PROCESS TABLE)\n");
	printf("---------------------------------------\n");
	printf("%-5s%-5s%-5s%-5s%-5s%-5s\n", "PROCESS | ", "BT | ", "AT | ", "ET | ", "WT | ", "TT | ");

    int currentTime = 0, waitingTime = 0, turnAroundTime = 0;  
    int wtTotal = 0, ttTotal;
	while(!isEmpty(PQ)){
    	Process process = dequeueProcess(&PQ);
    	waitingTime = currentTime - process.at;
    	turnAroundTime += process.bt;

//    	printf("%7c | %2d | %2d | %2d | %2d | %2d |\n", PA.data[0].processID+65, PA.data[0].bt, PA.data[0].at, PA.data[0].et, PA.data[0].wt, PA.data[0].tt);	    
  		printf("%7c | %2d | %2d | %2d | %2d | %2d |\n", process.processID+65, process.bt, process.at, currentTime, waitingTime, turnAroundTime);	    
		currentTime += process.bt;
		wtTotal += waitingTime;
		ttTotal += turnAroundTime;
	}
	
	printf("%7s - ----- - ----- - ----- | %2d | %2d |\n", "TOTAL", wtTotal, ttTotal);
}
