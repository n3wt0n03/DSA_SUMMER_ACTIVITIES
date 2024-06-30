#include "Dictionary.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Pet pets[] = {
		{"10056", {"Fido", "Johnson"}, 0b01011001}, // Boy, not House-Trained, not Neutered, Vaccinated, Social, Dog
		{"10231", {"Whiskers", "Smith"}, 0b11001000}, // Girl, House-Trained, Neutered, not Vaccinated, Aggressive, Cat
		{"10126", {"Goldie", "Fin"}, 0b10110010}, // Boy, House-Trained, Neutered, Vaccinated, Shy, Fish
		{"20394", {"Sunny", "Set"}, 0b01101011}, // Boy, not House-Trained, Neutered, Vaccinated, Social, Bird
		{"49381", {"Buddy", "Dirb"}, 0b11011001}, // Girl, House-Trained, Neutered, Vaccinated, Social, Dog
		{"98654", {"Mittens", "KitKat"}, 0b01001000}, // Boy, not House-Trained, not Neutered, not Vaccinated, Aggressive, Cat
		{"14352", {"Finley", "Memo"}, 0b10111010}, // Boy, House-Trained, Neutered, Vaccinated, Shy, Fish
		{"09685", {"Lola", "Bord"}, 0b01111011}, // Girl, not House-Trained, Neutered, Vaccinated, Social, Bird
		{"09786", {"Rocky", "Sam"}, 0b11001001}, // Boy, House-Trained, Neutered, not Vaccinated, Social, Dog
		{"01285", {"Snowball", "Dory"}, 0b01010011}, // Boy, not House-Trained, Neutered, Vaccinated, Shy, Fish
		{"64532", {"Tweety", "Girde"}, 0b01101011}, // Boy, not House-Trained, Neutered, not Vaccinated, Aggressive, Bird
		{"10923", {"Daisy", "Katkit"}, 0b11011000}, // Girl, House-Trained, Neutered, Vaccinated, Aggressive, Cat
		{"10193", {"Bubbles", "Grish"}, 0b10101010}, // Boy, House-Trained, Neutered, Vaccinated, Shy, Fish
		{"22104", {"Sammy", "Bi"}, 0b01111011}, // Boy, not House-Trained, Neutered, Vaccinated, Aggressive, Bird
		{"22104", {"Coco", "Melon"}, 0b11010001}, // Girl, House-Trained, Neutered, not Vaccinated, Social, Dog
	};
	
	// Populate Array
	arrListPet PL = populatePetList(pets);
	displayArrListStud(PL);
	
	// Open Dictionary
	petDict PD;
	initOpenDict(PD);
	insertPet(PD, PL);
	displayOpenDict(PD);
	
	
	return 0;
}
