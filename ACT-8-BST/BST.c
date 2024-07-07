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

void deleteElement(NodePtr* T, Product prod){
	NodePtr *trav, *succ, temp;
	
	// Loop throught the tree and find the elem
	for(trav = T; *trav != NULL && strcmp((*trav)->item.prodName, prod.prodName) != 0; ){
			trav = (strcmp((*trav)->item.prodName, prod.prodName) < 0) ? &(*trav)->right : &(*trav)->left;
	}
	
	if(*trav != NULL){
		// If there is no LC, let *trav point to the remaining child.
		if((*trav)->left == NULL){
			temp = *trav;
			*trav = temp->right;
			free(temp);
		// Else, if there is no RC, let *trav point to the remaining child.
		} else if ((*trav)->right == NULL){
			temp = *trav;
			*trav = temp->left;
			free(temp);
		// Else, if there are two children, find the successor
		} else {
			for(succ = &(*trav)->right; (*succ)->left != NULL; succ = &(*succ)->left){}
			temp = *succ;
			*succ = temp->right;
			(*trav)->item = temp->item;
			free(temp);
		}
		
	}
}

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
