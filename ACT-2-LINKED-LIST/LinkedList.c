#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	int idNum;
	int age;
}info;

typedef struct node {
	info data;
	struct node* next;
}Node, *NodePtr;

/* MAIN FUNCTIONS */
NodePtr initLL(void);
void insertFront(NodePtr* head, info data);
void insertRear(NodePtr* head, info data);
void insertAt(NodePtr* head, info data, int index);

void deleteFront(NodePtr* head);
void deleteRear(NodePtr* head);
void deleteAt(NodePtr* head, int index);

/* UTILITY FUNCTIONS */
void displayLL();
void pause(void);

void main(){
	NodePtr head = initLL();

	info database[10] = {{{"Marc Ochavo"}, 22101526, 21},
						 {{"Nicole Ochavo"}, 21101516, 22},
						 {{"John Doe"}, 22101526, 21},
					 	 {{"Bang Yunha"}, 23104536, 15},
						 {{"Lily Morrow"}, 11932157, 25},
				  	 	 {{"Seol Yoon A"}, 11987654, 29},
				 		 {{"Oh Hae Won"}, 22102342, 28},
						 {{"Bae Jin Sol"}, 22300326, 20},
						 {{"Kim Ji Woo"}, 24106875, 19},
						 {{"Jang Kyu Jin"}, 23105987, 18},
					   };
	
	printf("Insert Front:\n");
	insertFront(&head, database[0]);
	insertFront(&head, database[1]);
	insertFront(&head, database[2]);
	displayLL(head);
	pause();

	printf("Insert Rear:\n");
	insertRear(&head, database[3]);
	insertRear(&head, database[4]);
	insertRear(&head, database[5]);
	displayLL(head);
	pause();
	
	printf("Insert At:\n");
	insertAt(&head, database[6], 3);
	insertAt(&head, database[7], 2);
	insertAt(&head, database[8], 4);
	displayLL(head);
	pause();
	
	printf("Delete Front:\n");
	deleteFront(&head);
	deleteFront(&head);
	displayLL(head);
	pause();
	
	printf("Delete Rear:\n");
	deleteRear(&head);
	deleteRear(&head);
	displayLL(head);
	pause();
	
	printf("Delete At:\n");
	deleteAt(&head, 3);
	deleteAt(&head, 2);
	displayLL(head);
	pause();
}

void pause(void){
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}

void displayLL(NodePtr head){
	printf("\n\nClass Record\n");
	printf("---------------------\n");
	printf("%-20s%-10s%-10s", "Name", "Age", "ID Number");
	NodePtr trav;
	
	for(trav = head; trav != NULL; trav = trav->next){
		printf("\n%-20s%-10d%-10d", trav->data.name, trav->data.age, trav->data.idNum);
	}
}

NodePtr initLL(void){
	NodePtr head = NULL;
	return head;
}

void insertFront(NodePtr* head, info data){
	NodePtr temp = (NodePtr) malloc (sizeof(struct node));
	
	if(temp != NULL){
		temp->data = data;
		temp->next = *head;
		*head = temp;
	}
}

void insertRear(NodePtr* head, info data) {
	NodePtr temp, *trav;
	
	temp = (NodePtr) malloc (sizeof(struct node));
	
	if(temp != NULL){
		for(trav = head; *trav != NULL; trav = &(*trav)->next){}
		temp->data = data;
		temp->next = *trav;
		*trav = temp;
	}
}

void insertAt(NodePtr* head, info data, int index) {
	int count;
	NodePtr temp, *trav;
	
	temp = (NodePtr) malloc (sizeof(struct node));
	
	if(temp != NULL){
		for(count = 0, trav = head; *trav != NULL && count != index; count++, trav = &(*trav)->next){}
		temp->data = data;
		temp->next = *trav;
		*trav = temp;
	}
}

void deleteFront(NodePtr* head){
	NodePtr temp;
	
	if(*head != NULL){
		temp = *head;
		*head = temp->next; // Set the value of the current trav to its next value
		free(temp);
	} else {
		printf("The List is empty! No more values to delete");
	}
}

void deleteRear(NodePtr* head){
	NodePtr temp, *trav;
	
	// If the value of trav is NULL AND the value of the next value of trav is NULL,
	for(trav = head; *trav != NULL && (*trav)->next != NULL; trav = &(*trav)->next){}
	
	if(*trav != NULL){
		temp = *trav;
		*trav = NULL; // Set the value of the current trav to NULL so it won't link to the other nodes
		free(temp);
	} else {
		printf("The List is empty! No more values to delete");
	}
}


void deleteAt(NodePtr* head, int index){
	NodePtr temp, *trav;
	int count;
	
	// If the value of trav is NULL AND count is equal to index,
	for(trav = head, count = 0; *trav != NULL && count != index; count++, trav = &(*trav)->next){}
	
	if(*trav != NULL){
		temp = *trav;
		*trav = temp->next;
		free(temp);
	} else {
		printf("The List is empty! No more values to delete");
	}
}

