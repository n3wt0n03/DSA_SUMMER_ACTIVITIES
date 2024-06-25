#ifndef DICTIONARY
#define DICTIONARY
#define TYPE 5 
#define MAX 25

// Set the bits for animal types
// Set the array
// Set the open dictionary
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
	petName animal_name;
	animalType type;
}Pet;

typedef struct {
	Pet animal[MAX];
	int numPets;
}arrListPet;

typedef struct petNode{
	Pet pet;
	struct petNode* next;
}petNode, *petLL;

char* getAnimalType(animalType aType);
arrListPet populatePetList(void);
void displayArrListStud(arrListPet petList);






#endif
