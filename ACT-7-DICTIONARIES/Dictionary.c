#include "Dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* getAnimalType(animalType aType) {
    animalType mask = aType & 0b11; // shift right by 1 bit and mask with 3
    char* retVal = (char*) malloc (sizeof(char)*8);
    strcpy(retVal, " ");

	if(retVal != NULL){
		if(mask == 0b00){
			strcpy(retVal, "Cat");
		} else if(mask == 0b01){
			strcpy(retVal, "Dog");
		} else if(mask == 0b10){
			strcpy(retVal, "Fish");
		} else {
			strcpy(retVal, "Bird");
		} 
	}
    return retVal;
}

arrListPet populatePetList(Pet pets[]){
	arrListPet PL;
	int i;
	
	for(i = 0; i < MAX_PETS; i++){
		PL.animal[i] = pets[i];
	}
	PL.numPets = MAX_PETS;

	printf("Pets are populated inside the array!\n\n");
	return PL;
}

void displayArrListStud(arrListPet petList)
{
    printf("Pet List inside the Array\n");
    printf("---------------------------\n");
    printf("Pet count inside the array: %d\n\n", petList.numPets);
    printf("%-10s%-10s%-10s%-10s\n", "Index", "fName", "lName", "Animal\n");
    
    int i;
    for(i = 0; i < petList.numPets; i++){
        printf("%-10d%-10s%-10s%-10s\n", i, petList.animal[i].animal_name.fName, petList.animal[i].animal_name.lName, getAnimalType(petList.animal[i].type));
    }
}

void initOpenDict(petDict D){
	int i;
	for(i = 0; i < ANIMALS; i++){
		D[i] = NULL;
	}
}

int animalHash(animalType aType) {
    int retVal = 0;
    animalType mask = aType & 0b11; // shift right by 1 bit and mask with 3

	if(mask == 0b00){
		retVal = 0; // Cat
	} else if(mask == 0b01){
		retVal = 1; // Dog
	} else if(mask == 0b10){
		retVal = 2; // Fish
	} else {
		retVal = 3; // Bird
	} 
    return retVal;
}

void insertPet(petDict D, arrListPet PL){
	int i;
	petLL *trav;
	
	for(i = 0; i < PL.numPets; i++){
		int ndx = animalHash(PL.animal[i].type);
		
		// Make a new functin purely for inserting it as linked-list
		for(trav = &D[ndx]; *trav != NULL && strcmp((*trav)->pet.petID, PL.animal[i].petID) != 0; trav = &(*trav)->next){}
		
		petLL newNode = (petLL) malloc (sizeof(petNode));
		if(newNode != NULL){
				newNode->pet = PL.animal[i];
				newNode->next = *trav;
				*trav = newNode;
		} else {
			printf("New node not initialized\n");	
		}
	}  
}

void displayOpenDict(petDict D){
	printf("\n\nSETS OF PETS USING OPEN DICTIONARY:");
	printf("\n-----------------------------------\n\n");
	printf("%10s", "INDEX");
	printf("%20s", "CHAIN OF VALUES\n");
	
	int i;
	petLL trav;
	
	for(i = 0; i < ANIMALS; i++){
		printf("%6s %-10d", " ", i);
		for(trav = D[i]; trav != NULL; trav = trav->next){
			printf("%-10s => ", trav->pet.animal_name);
		}
		printf("NULL \n");
	}
}

void initCloseDict(petCLDict CLD){
	int i;
	for(i = 0; i < MAX_CLOSE; i++){
		strcpy(CLD[i].petID, EMPTY);
		strcpy(CLD[i].animal_name.fName, EMPTY);
		strcpy(CLD[i].animal_name.lName, EMPTY);
		CLD[i].type = 0b00000000;
	}
}

int closeHash(char fName[], animalType aType){
	int retVal = 0;
	
	int i;
	for(i = 0; fName[i] != '\0'; i++){
		retVal += fName[i];
	}
	
//	printf("%s = %d\n", fName, retVal % MAX_CLOSE);
	return retVal % MAX_CLOSE;
}

bool isFull(petCLDict CLD){
	int i, counter = 0;
	for(i = 0; i < MAX_CLOSE; i++){
		if(strcmp(CLD[i].petID, EMPTY) == 0 && strcmp(CLD[i].petID, DELETED) == 0){
			counter++;
		}
	}
	
	return (counter == MAX_CLOSE) ? true : false;
}

void convertToCloseDict(petDict D, petCLDict CLD){
	int i, j, ndx;
    petLL *trav, temp;
 
	// Access the indexes in the Open Dictionary
    for(i = 0; i < ANIMALS; i++){
    	// Loop through the Open Dictionary starting from the first index
        for(trav = &D[i]; *trav != NULL; ){      	
        	if(!isFull(CLD)){
        		// Hash the animal type + first name of pet from the Open Dictionary
        		ndx = closeHash((*trav)->pet.animal_name.fName, (*trav)->pet.type);
        		// Access the hashed index of Close Dictionary
				// Check if it collides, if it is, linear probing
        		for(j = ndx; strcmp(CLD[j].petID, EMPTY) == 0 && strcmp(CLD[j].petID, DELETED) == 0; j = (j + 1) % MAX_CLOSE){}
        		// Insert to Close Dictionary 
				CLD[j] = (*trav)->pet;
				
				// Delete the Pet Node from the Open Dictionary; Repeat the steps till the Open Dictionary is empty
	            temp = *trav;
	            *trav = (*trav)->next;
	            free(temp);
			}
		}
    }
}

void displayCloseDict(petCLDict CLD){
	printf("\n\nSETS OF PETS USING ClOSE DICTIONARY:");
	printf("\n-----------------------------------\n\n");
 	printf("%-10s%-10s%-10s%-10s\n", "INDEX", "FNAME", "LNAME", "ANIMAL\n");
	
	int i;
	for(i = 0; i < MAX_CLOSE; i++){
		    animalType mask = CLD[i].type & 0b11111111;
		    char* retVal = (char*) malloc (sizeof(char)*8);
		    int retType;
				if(mask == 0b00000000){
					strcpy(retVal, "EMPTY");
				} else {
					retVal = getAnimalType(CLD[i].type);
				}
		printf("%-10d%-10s%-10s%-10s\n", i, CLD[i].animal_name.fName, CLD[i].animal_name.lName, retVal);
	}
}





