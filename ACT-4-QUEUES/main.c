#include "QueueLL.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue* Q = initQueue();
	
	Enqueue(Q, 10);
	Enqueue(Q, 30);
	Enqueue(Q, 24);
	Enqueue(Q, 50);
	Enqueue(Q, 60);
	
	displayQueue(*Q);
	
	Dequeue(Q);
	Dequeue(Q);
	
	displayQueue(*Q);
	
	printf("Front Data: %d\n", Front(*Q));
	printf("Rear Data: %d", Rear(*Q));
	return 0;
}
