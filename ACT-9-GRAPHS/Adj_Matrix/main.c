#include "AdjMatrix.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/* Vertices:
		A - 0;
		B - 1;
		C - 2;
		D - 3;
		E - 4;
	*/
	int adjMatrix[V][V];
	
	printf("Initialization of Adjacency Matrix\n");
	initAdjMatrix(adjMatrix);
	printMatrix(adjMatrix);
	printf("\n");
	
	printf("Putting Values for Adjacency Matrix\n");
	addEdge(adjMatrix, 0, 2); // (A,C)
	addEdge(adjMatrix, 0, 1); // (A,B)
	addEdge(adjMatrix, 0, 3); // (A,D)
	addEdge(adjMatrix, 2, 1); // (C,B)
	addEdge(adjMatrix, 2, 0); // (C,A)
	addEdge(adjMatrix, 2, 3); // (C,D)
	addEdge(adjMatrix, 1, 4); // (B,E)
	addEdge(adjMatrix, 1, 2); // (B,C)
	addEdge(adjMatrix, 1, 0); // (B,A)
	addEdge(adjMatrix, 4, 3); // (E,D)
	addEdge(adjMatrix, 4, 1); // (E,B)
	addEdge(adjMatrix, 3, 0); // (D,A)
	addEdge(adjMatrix, 3, 2); // (D,C)
	addEdge(adjMatrix, 3, 4); // (D,E)
	printMatrix(adjMatrix);
	return 0;
}
