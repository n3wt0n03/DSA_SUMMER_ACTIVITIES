#include "StackArray.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList stack = createStack();
	
	stack_push(&stack, 40);
	stack_push(&stack, 31);
	stack_push(&stack, 20);

	int top = stack_peek(stack);
	printf("Peeking the top of the stack: %d", top);
	display(stack);
	return 0;
}
