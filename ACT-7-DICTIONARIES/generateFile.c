#include <stdio.h>

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

void generatePetFile(void){
	Pet pets[] = {
		{{"Fido", "Johnson"}, 0b01011001}, // Boy, not House-Trained, not Neutered, Vaccinated, Social, Dog
		{{"Whiskers", "Smith"}, 0b11001000}, // Girl, House-Trained, Neutered, not Vaccinated, Aggressive, Cat
		{{"Goldie", "Fin"}, 0b10110010}, // Boy, House-Trained, Neutered, Vaccinated, Shy, Fish
		{{"Sunny", "Set"}, 0b01101001}, // Boy, not House-Trained, Neutered, Vaccinated, Social, Bird
		{{"Buddy", "Dirb"}, 0b11011001}, // Girl, House-Trained, Neutered, Vaccinated, Social, Dog
		{{"Mittens", "KitKat"}, 0b01001000}, // Boy, not House-Trained, not Neutered, not Vaccinated, Aggressive, Cat
		{{"Finley", "Memo"}, 0b10111010}, // Boy, House-Trained, Neutered, Vaccinated, Shy, Fish
		{{"Lola", "Bord"}, 0b01111001}, // Girl, not House-Trained, Neutered, Vaccinated, Social, Bird
		{{"Rocky", "Sam"}, 0b11001001}, // Boy, House-Trained, Neutered, not Vaccinated, Social, Dog
		{{"Snowball", "Dory"}, 0b01010010}, // Boy, not House-Trained, Neutered, Vaccinated, Shy, Fish
		{{"Tweety", "Girde"}, 0b01101000}, // Boy, not House-Trained, Neutered, not Vaccinated, Aggressive, Bird
		{{"Daisy", "Katkit"}, 0b11011000}, // Girl, House-Trained, Neutered, Vaccinated, Aggressive, Cat
		{{"Bubbles", "Grish"}, 0b10101010}, // Boy, House-Trained, Neutered, Vaccinated, Shy, Fish
		{{"Sammy", "Bi"}, 0b01111000}, // Boy, not House-Trained, Neutered, Vaccinated, Aggressive, Bird
		{{"Coco", "Melon"}, 0b11010001}, // Girl, House-Trained, Neutered, not Vaccinated, Social, Dog
	};
	
	FILE *file = fopen("pets.bin", "wb");
    if (file != NULL) {
        fwrite(pets, sizeof(Pet), 15, file);
    }
    fclose(file);
}

int main(void){
	generatePetFile();
	return 0;
}
