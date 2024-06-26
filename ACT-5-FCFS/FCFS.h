#ifndef FCFS
#define FCFS
#define MAX 15
#include <stdbool.h>

typedef struct {
	int processID; // Process
	int at; // Arrival Time
	int bt; // Burst Time
}Process;

typedef struct {
	Process data[MAX];
	int dataCount;
}ProcessArray;

typedef struct processNode{
	Process data;
	struct processNode* next;
}ProcessNode, *PtrProcNode;

typedef struct{
	PtrProcNode front;
	PtrProcNode rear;
}ProcessQueue;

void initQueue(ProcessQueue* PQ);
void enqueueProcess(ProcessQueue* PQ, Process data);
Process dequeueProcess(ProcessQueue* PQ);
bool isEmpty(ProcessQueue PQ);
int Front(ProcessQueue PQ);
int Rear(ProcessQueue PQ);
void visualization(ProcessQueue PQ);

ProcessArray getProcess(void);
void displayProcessArray(ProcessArray PA);

void executeFCFS(ProcessQueue PQ, ProcessArray PA);





#endif 
