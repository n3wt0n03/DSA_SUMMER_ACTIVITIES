#include "UID.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SET A = initSET();
	SET B = initSET();
	SET C = initSET(); // use for UID
	
	displaySET(A);
	displaySET(B);
	
	insertElem(&A, 6);
	insertElem(&A, 3);
	insertElem(&A, 5);
	insertElem(&A, 11);
	insertElem(&A, 13);
	
	printf("Display SET A");
	displaySET(A);
	
	deleteElem(&A, 13);
	printf("Display SET A After Deleting Element 13");
	displaySET(A);
	
	insertElem(&B, 1);
	insertElem(&B, 2);
	insertElem(&B, 5);
	insertElem(&B, 12);
	insertElem(&B, 13);
	
	printf("Display SET B");
	displaySET(B);
	
	deleteElem(&B, 2);
	printf("Display SET A After Deleting Element 13");
	displaySET(A);

	C = setUnion(A, B);
	
	printf("Display UNION A AND B");
	displaySET(C);
	
	C = setIntersect(A, B);
	
	printf("Display INTERSECT A AND B");
	displaySET(C);
	
	
	
	
	return 0;
}
