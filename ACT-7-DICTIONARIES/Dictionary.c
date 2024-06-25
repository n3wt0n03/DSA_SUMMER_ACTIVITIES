#include "Dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* getAnimalType(animalType aType) {
	
}

arrListPet populatePetList(void){
    FILE* fp;
    student* studs;
    int dataCount;
    arrListStud SL = {{}, 0};
    
    if((fp = fopen("students.bin", "rb"))== NULL){
        puts("Unsuccessful in opening students.txt");
    }else{
        fseek(fp, 0, 2);
        dataCount = (int) ftell(fp) / sizeof(student);
        studs = (student*) malloc (sizeof(student) * dataCount);
        if(studs != NULL){
            fseek(fp, 0, 0);
            fread(studs, sizeof(student), dataCount, fp);
        }
        /* In this section, insert all the studs into an setList to be returned. */
}

void displayArrListStud(arrListPet petList)
{
    printf("Student Data from the file\n");
    printf("%-10s", "Id Number");
    printf("%-10s", "fName");
    printf("%-10s\n", "lName");
    
    //for(){
        printf("%-10s%-10s%-10s\n");
    //}
}

