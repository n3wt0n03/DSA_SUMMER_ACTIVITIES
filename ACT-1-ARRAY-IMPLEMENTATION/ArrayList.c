#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct {
	char fname[MAX];
	char lname[MAX];
}studName;

typedef struct{
	int month;
	int year;
}bday;

typedef struct{
	studName name;
	bday birthdate;
	int age;
	int idNum;
}studentInfo;

typedef struct {
	studentInfo studList[MAX];
	int studCount;
}classRecord;

/* MAIN FUNCTIONS */
classRecord initClassRecord(void);
void insertFront(classRecord* cRec, studentInfo database[]);
void insertRear(classRecord* cRec, studentInfo database[]);
void insertAt(classRecord* cRec, studentInfo student, int index);
void insertSorted(classRecord* cRec, studentInfo student);

void deleteFront(classRecord* cRec);
void deleteRear(classRecord* cRec);
void deleteAt(classRecord* cRec, int index);

/* UTILITY FUNCTIONS */
void displayClassRec(classRecord cRec);
void classSort(classRecord* cRec);
void pause(void);

void main(){
	classRecord classOne = initClassRecord();
	
	studentInfo database[15] = {{{"Marc","Ochavo"}, {12, 2003}, 21, 22101526},
								{{"Nicole","Ochavo"}, {05, 2002}, 22, 21101516},
								{{"John","Doe"}, {12, 2003}, 21, 22101526},
								{{"Bang","Yunha"}, {02, 2009}, 15, 23104536},
								{{"Lily","Morrow"}, {10, 1999}, 25, 11932157},
								{{"Yoon A","Seol"}, {01, 1995}, 29, 11987654},
								{{"Hae Won","Oh"}, {02, 1996}, 28, 22102342},
								{{"Jin Sol","Bae"}, {12, 2004}, 20, 22300326},
								{{"Ji Woo","Kim"}, {04, 2005}, 19, 24106875},
								{{"Kyu Jin","Jang"}, {05, 2006}, 18, 23105987},
								{{"Minji","Kim"}, {05, 2006}, 17, 24109867},
								{{"Hanni","Pham"}, {10, 2004}, 20, 26102932},
								{{"Danielle","Marsh"}, {04, 2005}, 19, 24100147},
								{{"Haerin","Kang"}, {05, 2006}, 17, 25102677},				
								{{"Hyein","Lee"}, {05, 2008}, 16, 26203217},
							   };
	
	printf("Insert Front\n");						   
	insertFront(&classOne, database);
	displayClassRec(classOne);
	pause();
	
	printf("Insert Rear\n");
	insertRear(&classOne, database);
	displayClassRec(classOne);
	pause();
	
	printf("Insert At\n");
	insertAt(&classOne, database[10], 3);
	insertAt(&classOne, database[11], 11);
	insertAt(&classOne, database[11], 10);
	displayClassRec(classOne);
	pause();
	
	printf("Insert Sorted\n");
	// sort the class record for easier insert sorted
	classSort(&classOne);
	insertSorted(&classOne, database[12]);
	displayClassRec(classOne);
	pause();
	
	printf("Delete Front\n");
	deleteFront(&classOne);
	deleteFront(&classOne);
	displayClassRec(classOne);
	
	printf("\n\nDelete Rear\n");
	deleteRear(&classOne);
	deleteRear(&classOne);
	displayClassRec(classOne);
	pause();
	
	printf("Delete At\n");
	deleteAt(&classOne, 3);
	displayClassRec(classOne);
	deleteAt(&classOne, 5);
	displayClassRec(classOne);
}

void pause(void){
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}

void displayClassRec(classRecord cRec) {
	printf("\n\nClass Record\n");
	printf("---------------------\n");
	printf("Number of Students: %d\n\n", cRec.studCount);
	printf("%-10s%-20s%-10s%-10s", "Name", "Year of Birth", "Age", "ID Number");
	
	int i;
	for(i = 0; i < cRec.studCount; i++){
		printf("\n%-10s%-20d%-10d%-10d", cRec.studList[i].name, cRec.studList[i].birthdate.year, cRec.studList[i].age, cRec.studList[i].idNum);
	}
}

classRecord initClassRecord(void) {
	classRecord cRec;
	cRec.studCount = 0;
	return cRec;
}

void classSort(classRecord* cRec){
//	sort by age
	int i, j;
	studentInfo temp;
	for(i = 0; i < cRec->studCount; i++){
		for(j = i + 1; j < cRec->studCount; j++){
			if(cRec->studList[i].age > cRec->studList[j].age){
				temp = cRec->studList[i];
				cRec->studList[i] = cRec->studList[j];
				cRec->studList[j] = temp;
			}
		}
	}
}

void insertFront(classRecord* cRec, studentInfo database[]){
	int i,j;
	
	// insert first all elements from database (index 0-5)
	for(i = 0; i < 5; i++){
		if(cRec->studCount == 0){
			// insert at the first index
			cRec->studList[0] = database[i];
		} else {
			//shift elements 
			for(j = cRec->studCount; j >= 0; j--){
				cRec->studList[j+1] = cRec->studList[j];
			}
			// insert at the first index
			cRec->studList[0] = database[i];
		}
		cRec->studCount++;
	}
}

void insertRear(classRecord* cRec, studentInfo database[]){
	int i;
	
	//insert last all elements from database (index 6-10)
	for(i = 5; i < 10; i++){
		cRec->studList[cRec->studCount] = database[i];
		cRec->studCount++;
	}
}

void insertAt(classRecord* cRec, studentInfo student, int index) {
	
	if(index < cRec->studCount){
		if(cRec->studList[index].idNum != 0){
			int i;
			
			//shift elements starting from the desired index to insert
			for(i = cRec->studCount; i >= index; i--){
				cRec->studList[i+1] = cRec->studList[i];
			}
			cRec->studList[index] = student;
		} else {
			cRec->studList[index] = student;
		}
		cRec->studCount++;
	} else {
		printf("Index not found\n\n");
	}
}

void insertSorted(classRecord* cRec, studentInfo student){
	int i, j;
	
	//insert sort by age
	for(i = 0; i < cRec->studCount && cRec->studList[i].age < student.age; i++){}
	
	//shift elements
	for(j = cRec->studCount; j >= i; j--){
		cRec->studList[j+1] = cRec->studList[j];
	}
	cRec->studList[i] = student;
	cRec->studCount++;
		
}

void deleteFront(classRecord* cRec) {
	int i;
	if(cRec->studCount != 0){
		for(i = 1; i < cRec->studCount; i++){
			cRec->studList[i - 1] = cRec->studList[i];
		}
		cRec->studCount--;
	} else {
		printf("Class record is already empty.\n\n");
	}
}

void deleteRear(classRecord* cRec){
	if(cRec->studCount != 0){
		cRec->studCount--;
	} else {
		printf("Class record is already empty.\n\n");
	}
}

void deleteAt(classRecord* cRec, int index){
	int i;

	if(cRec->studCount != 0){
		for(i = index+1; i < cRec->studCount; i++){
			cRec->studList[i-1] = cRec->studList[i];
		}
		cRec->studCount--;
	} else {
		printf("Class record is already empty.\n\n");
	}
}
