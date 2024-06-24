#include "UID.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

SET initSET(void) {
	SET S;
	int i;
	for(i = 0; i < MAX; i++){
		S.elem[i] = 0;
	}	
	
	S.count = 0;
	printf("SET initialized successfully!\n");
	return S;
}

bool insertElem(SET* S, int elem){
	if(S->count < MAX && elem <= MAX-1) {
		S->elem[elem] = 1;
		S->count++;
	} else {
		printf("Element %d cannot be inserted!", elem);
	}
	return true;
}

bool deleteElem(SET* S, int elem){
	if(S->count > 0 && elem <= MAX-1) {
		S->elem[elem] = 0;
		S->count--;
	} else {
		printf("Element %d cannot be deleted!", elem);
	}
	return true;
}

SET setUnion(SET A, SET B) {
	SET C = initSET();
	
	int i;
	for(i = 0; i < MAX; i++){
		if(A.elem[i] || B.elem[i]){
			C.elem[i] = 1;
			C.count++;
		}
	}
	
	return C;
}
SET setIntersect(SET A, SET B){
	SET C = initSET();
	
	int i;
	for(i = 0; i < MAX; i++){
		if(A.elem[i] && B.elem[i]){
			C.elem[i] = 1;
			C.count++;
		}
	}
	
	return C;	
}

//SET setDifference(SET A, SET B);

void displaySET(SET S){
	printf("\n--------------\n");
	if(S.count == 0) {
		printf("SET is empty!\n");
	} else {
		int i;
		for(i = 0; i < MAX; i++){
			if(S.elem[i]){
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	printf("\n");
}

