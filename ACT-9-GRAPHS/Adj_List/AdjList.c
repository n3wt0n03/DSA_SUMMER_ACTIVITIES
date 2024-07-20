#include "AdjList.h"
#include <stdio.h>
#include <stdlib.h>

GRAPH* initGraph(void){
	GRAPH* G = (GRAPH*) malloc (sizeof(struct graph));
	if (G != NULL){
		G->numOfVertices = SIZE;
		G->numOfEdges = 0;
		int i;
		for(i = 0; i < G->numOfVertices; i++){
			G->nodes[i] = NULL;
		}
		printf("Adjacency List Matrix Initialization Successfully\n");
	}

    return G;
}

nodeType createNode(int vertix) {
	nodeType newNode = (nodeType) malloc(sizeof(struct node));
	if(newNode != NULL){
		newNode->V = vertix;
		newNode->next = NULL;
	}
	return newNode;
}

void printGraph(GRAPH G){
	printf("\nAdjacency Matrix");
	printf("\n--------------------\n");
	printf("Number of Vertices: %d\n", G.numOfVertices);
	printf("Number of Edges: %d\n\n", G.numOfEdges);
	
	int i;
	nodeType trav;
	for(i = 0; i < G.numOfVertices; i++){
		printf("[%d] => ", i);
		for(trav = G.nodes[i]; trav != NULL; trav = trav->next){
			printf("%d => ", trav->V);
		}
		printf("NULL");
		printf("\n");
	}
}

void addEdge(GRAPH* G, int i, int j){
	// add edge from i to j
	nodeType newNode = createNode(j); // We use the value of j for it is the destination
	if (newNode != NULL){
		nodeType* trav;
		for(trav = &G->nodes[i]; *trav != NULL && (*trav)->V != i; trav = &(*trav)->next){}
		
		// Insert Last
		newNode->next = *trav; // Let the next of the new node point to the last node of the list
		*trav = newNode; // Let the last node of the index(vertix) point to the new node
		G->numOfEdges++; // increment the number of edges
	}
}
