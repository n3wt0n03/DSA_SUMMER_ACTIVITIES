#ifndef DICTIONARY
#define DICTIONARY
#define ANIMALS 4 // For Open Dict (Based on bit hash)
#define MAX_PETS 15 // Number of pets to be stored inside the array

//#include <stdbool.h>

// Set the open dictionary (deleteElem)
// Convert to close dictionary

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

typedef petLL petDict[ANIMALS];

char* getAnimalType(animalType aType);       
arrListPet populatePetList(Pet pets[]);
void displayArrListStud(arrListPet petList);

int animalHash(animalType aType);
void initOpenDict(petDict D);
void insertPet(petDict D, arrListPet PL);
void displayOpenDict(petDict D);





#endif
