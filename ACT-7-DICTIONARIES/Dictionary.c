#include "Dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>

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
		retVal = 0;
	} else if(mask == 0b01){
		retVal = 1;
	} else if(mask == 0b10){
		retVal = 2;
	} else {
		retVal = 3;
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

int closeHash(animalType aType){
	int retVal = 0;
	
	retVal = (animalHash(aType) + 10) % MAX_CLOSE;
	return retVal;
}

void convertToCloseDict(petDict D, petCLDict CLD){
	int i, ndx;
	petLL *trav; // use PPN for deletion (deleteFirst)
	
	// Access the first index in the Open Dictionary
	// Hash the the animal type of the first index of the Open Dictionary
	// Access the hashed index of Close Dictionary
	// Insert to Close Dictionary
	// Delete the the index' chain in the Open Dictionary
	// Repeat until Open Dictionary is empty
	
	for(i = 0; i < ANIMALS; i++){
		trav = &D[i];
	}
}





