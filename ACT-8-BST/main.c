#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Product prods[12] = {{"Apple", 1.99, 10, {1, 1, 2025}},
					     {"Banana", 0.99, 20, {2, 15, 2024}},
					     {"Carrot", 0.79, 30, {3, 20, 2023}},
					     {"Donut", 2.49, 15, {4, 1, 2025}},
					     {"Eggs", 1.99, 25, {5, 15, 2024}},
					     {"Flour", 1.49, 10, {6, 20, 2023}},
					     {"Grapes", 2.99, 20, {7, 1, 2025}},
					     {"Honey", 3.99, 15, {8, 15, 2024}},
					     {"Ice Cream", 4.99, 10, {9, 20, 2023}},
					     {"Jelly", 2.49, 25, {10, 1, 2025}},
					     {"Kale", 1.99, 20, {11, 15, 2024}},
						 {"Lettuce", 1.49, 15, {12, 20, 2023}},
						};
						
	NodePtr T = initTree();
	
	addElement(&T, prods);
	
	printf("\nPreOrder Traversal: \n");
	preOrder(T);
	printf("\n");
	
	printf("\nInOrder Traversal: \n");
	inOrder(T);
	printf("\n");
	
	printf("\nPostOrder Traversal: \n");
	postOrder(T);
	printf("\n");
	
	deleteElement(&T, prods[2]);
	
	printf("\nPreOrder Traversal after deletion: \n");
	preOrder(T);
	printf("\n");
	
	return 0;
}
