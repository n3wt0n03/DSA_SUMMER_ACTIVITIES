#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


NodePtr initTree(void){
	NodePtr T = (NodePtr) malloc (sizeof(NodeType));
	Product initVal = {EMPTY, 0, 0, {0, 0, 0}}; 
	if(T != NULL){ 
		T->item = initVal;
		T->left = NULL;
		T->right = NULL;
	} 
	return T;
}

void addElement(NodePtr* T, Product prod[]) {
	int i;
	for(i = 0; i < 12; i++){
		NodePtr *trav = T;
		if(strcmp((*T)->item.prodName, EMPTY) == 0){
			(*T)->item = prod[i];
			printf("Data %s inserted successfully as a root\n", (*trav)->item.prodName);
		} else {
			while(*trav != NULL && strcmp((*trav)->item.prodName, prod[i].prodName) != 0){
				trav = (strcmp((*trav)->item.prodName, prod[i].prodName) < 0) ? &(*trav)->right : &(*trav)->left;
			}
		}
		
		if(*trav == NULL){
			NodePtr newNode = (NodePtr) calloc (sizeof(NodeType), 1);
			if(newNode != NULL){
				newNode->item = prod[i];
				*trav = newNode;
				printf("Data %s inserted successfully\n", (*trav)->item.prodName);
			} else {
				printf("Data %d is already in the Tree\n", (*trav)->item.prodName);
			}
		}
	}
}

//void deleteElement(NodePtr* T, Product prod);

void preOrder(NodePtr T){
	if(T != NULL){
		printf("%s -> ", T->item.prodName);
		preOrder(T->left);
		preOrder(T->right);
	}
}

void inOrder(NodePtr T){
	if(T != NULL){
		inOrder(T->left);
		printf("%s -> ", T->item.prodName);
		inOrder(T->right);
	}	
}

void postOrder(NodePtr T){
	if(T != NULL){
		postOrder(T->left);
		postOrder(T->right);
		printf("%s -> ", T->item.prodName);
	}
}
