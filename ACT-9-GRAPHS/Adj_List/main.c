#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	// Declare and initialize graph
	GRAPH* G = initGraph();
	printGraph(*G);
	
	addEdge(G, 0, 1);
	addEdge(G, 0, 3);
	addEdge(G, 1, 2);
	addEdge(G, 2, 3);
	addEdge(G, 3, 1);
	addEdge(G, 2, 4);
	addEdge(G, 3, 2);
	
	
	printGraph(*G);
}
