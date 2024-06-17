#include "StackLL.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {	
	StackLL head = initStack();
	
	stack_push(&head, 10);
	stack_push(&head, 15);
	stack_push(&head, 30);
	stack_push(&head, 40);

	display(head);
	visualize(head);
	
	return 0;
}
