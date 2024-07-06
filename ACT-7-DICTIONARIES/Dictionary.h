#ifndef DICTIONARY
#define DICTIONARY
#define MAX_PETS 15 // Number of pets to be stored inside the array
#define ANIMALS 4 // For Open Dict (Based on bit hash)
#define MAX_CLOSE 25// For Close Dict
#define EMPTY "empty"
#define DELETED "del"

#include <stdbool.h>

typedef struct {
	char fName[64];
	char lName[32];
}petName;

typedef unsigned char animalType;
/*Given 8 bits: 0000 0000
 
 Bits
 8    = Gender:            	0 - Boy, 1 - Girl
 7    = House-Trained:     	0 - No, 1 - Yes
 6    = Spayed/Neutered: 	0 - No, 1 - Yes
 5    = Vaccinated:        	0 - No, 1 - Yes
 3-4  = Behaviour:			00 - Aggressive, 01 - Nocturnal, 10 - Social, 11 - Shy
 1-2  = Animal:           	00 - Cat, 01 - Dog, 10 - Fish, 11 - Bird
 
 For example:
 1001 1001 would represent a Boy that is not House-Trained and not Neutered, is Vaccinated, and is a Socialized Dog
*/

typedef struct {
	char petID[5];
	petName animal_name;
	animalType type;
}Pet;

typedef struct {
	Pet animal[MAX_PETS];
	int numPets;
}arrListPet;

typedef struct petNode{
	Pet pet;
	struct petNode* next;
}petNode, *petLL;

typedef petLL petDict[ANIMALS]; // Open Dictionary

typedef Pet petCLDict[MAX_CLOSE]; // Close Dictionary

/* Function Prototypes for Array List*/
char* getAnimalType(animalType aType);       
arrListPet populatePetList(Pet pets[]);
void displayArrListStud(arrListPet petList);

/* Function Prototypes for Dictionaries*/
int animalHash(animalType aType); // get the equivalent bits of 3
int closeHash(char fName[], animalType aType); // animalHash() + 10 % MAX

// Open Dictionary
void initOpenDict(petDict D);
void insertPet(petDict D, arrListPet PL);
//void deletePet(petDict D);
void displayOpenDict(petDict D);

// Close Dictionary
void initCloseDict(petCLDict CLD);
bool isFull(petCLDict CLD);
void convertToCloseDict(petDict D, petCLDict CLD);




#endif
