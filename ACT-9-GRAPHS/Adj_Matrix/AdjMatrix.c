#include "AdjMatrix.h"
#include <stdio.h>
#include <stdlib.h>

void initAdjMatrix(int arr[][V]){
	int i, j;
	
	for(i = 0; i < V; i++){
		for(j = 0; j < V; j++){
			arr[i][j] = 0;
		}
	}
}

void addEdge(int arr[][V], int src, int dest){
	arr[src][dest] = 1;
}

void printMatrix(int arr[][V]){
	int i, j;
	
	for(i = 0; i < V; i++){
		for(j = 0; j < V; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
