#ifndef QUEUE_LL
#define QUEUE_LL

#include <stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}Node, *NodePtr;

typedef struct {
	NodePtr front;
	NodePtr rear;
}Queue;

Queue* initQueue(void); // Initialize Queue
void Enqueue(Queue* Q, int data); // Insert Last
void Dequeue(Queue* Q); // Delete First
int Front(Queue Q); // Returns the value of the first node
int Rear(Queue Q); // Returns the value of the last node
bool isEmpty(Queue Q); // Returns true if the queue is empty

void displayQueue(Queue Q);// Display Queue


#endif
