#ifndef CIRCULAR_Q
#define CIRCULAR_Q
#define MAX 10
#define EMPTY 999

#include <stdbool.h>

typedef struct {
	int data[MAX];
	int front;
	int rear;
}CircularQ;

CircularQ initQueue(void);				// Returns a CircularQ data type wherein it allocates an array and Initializes the front and rear 
void enqueue(CircularQ *CQ, int data);	// Inserts a data in the rear in a circular manner
void dequeue(CircularQ *CQ);			// Deletes a data in the front in a circular manner
int front(CircularQ CQ);
int rear(CircularQ CQ);
bool isEmpty(CircularQ CQ);
bool isFull(CircularQ CQ);

void display(CircularQ CQ);
void visualize(CircularQ CQ);


#endif
