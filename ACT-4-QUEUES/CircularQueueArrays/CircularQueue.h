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

CircularQ initQueue(void);
void enqueue(CircularQ *CQ, int data);
void dequeue(CircularQ *CQ);
int front(CircularQ CQ);
int rear(CircularQ CQ);
bool isEmpty(CircularQ CQ);
bool isFull(CircularQ CQ);

void display(CircularQ CQ);
void visualize(CircularQ CQ);


#endif
