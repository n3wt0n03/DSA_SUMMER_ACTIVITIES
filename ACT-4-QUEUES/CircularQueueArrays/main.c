#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CircularQ CQ = initQueue();
	
	enqueue(&CQ, 5);
	enqueue(&CQ, 200); 
	enqueue(&CQ, 21);
	enqueue(&CQ, 30);
	enqueue(&CQ, 15);
	enqueue(&CQ, 100);	
	enqueue(&CQ, 150);
	enqueue(&CQ, 120);	
	enqueue(&CQ, 111);
	enqueue(&CQ, 131); //error can't insert

//	display(CQ);
	visualize(CQ);
	
	dequeue(&CQ);
	enqueue(&CQ, 300); 
	
//	display(CQ);
	visualize(CQ);
//	
//	dequeue(&CQ);
//	enqueue(&CQ, 400);
//	dequeue(&CQ);
//	enqueue(&CQ, 500);
//	dequeue(&CQ);
//	enqueue(&CQ, 600);
//	enqueue(&CQ, 650); //error can't insert
//	
//	display(CQ);
//	visualize(CQ);

	return 0;
}
