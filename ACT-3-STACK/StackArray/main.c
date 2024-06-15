#include "StackArray.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList stack = createStack();

	stack_push(&stack, 40);
	stack_push(&stack, 31);
	stack_push(&stack, 20);
	stack_push(&stack, 10);
	stack_push(&stack, 15);

	display(stack);
	visualize(stack);
	
	StackArrayList stackEven = createStackEven(&stack);
	display(stackEven);
	visualize(stackEven);
	return 0;
}
