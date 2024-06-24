#ifndef UID
#define UID
#define MAX 15

#include <stdbool.h>

typedef struct {
	int elem[MAX];
	int count;	
}SET;

SET initSET(void);
bool insertElem(SET* S, int elem);
bool deleteElem(SET* S, int elem);
SET setUnion(SET A, SET B);
SET setIntersect(SET A, SET B);
SET setDifference(SET A, SET B);

void displaySET(SET S);


#endif
