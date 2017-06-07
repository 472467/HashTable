#include "student.h"
#include <cstdlib>

Student::Student(int& sd){
	srand(sd);
	sd++;
	genFName();
	srand(sd);
	sd++;
	genLName();
	srand(sd);
	sd++;
	gpa = (((float)(rand() % 400))/100); 
	
}

Student::Student(char* f, char* l, float g){
	fName = new char[10];
	lName = new char[10];
	
	strcpy(fName, f);
	strcpy(lName,l);
	gpa = g;
}

Student::~Student(){
	delete fName;
	delete lName;
}

void Student::genFName(){
	
	char* alphanum = "abcdefghijklmnopqrstuvwxyz";
	char* alphaCap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	int length = rand() % 4 + 3;
	char* tName = new char[length + 1];
	
	for(int x = 0; x <= length; x++){
		int cID = rand() % 26;
		
		if(x == 0){
			tName[x] = alphaCap[cID];
		}else{
			tName[x] = alphanum[cID];
		}
	}
	tName[length + 1] = '\0';
	fName = new char[length + 1];
	strcpy(fName, tName);
}

void Student::genLName(){
	char* alphanum = "abcdefghijklmnopqrstuvwxyz";
	char* alphaCap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	int length = rand() % 4 + 3;
	char* tName = new char[length + 1];
	
	for(int x = 0; x <= length; x++){
		int cID = rand() % 26;
		
		if(x == 0){
			tName[x] = alphaCap[cID];
		}else{
			tName[x] = alphanum[cID];
		}
	}
	tName[length + 1] = '\0';
	lName = new char[length + 1];
	strcpy(lName, tName);
}

float Student::getGPA(){
	return gpa;
}

char* Student::getFName(){
	return fName;
}

char* Student::getLName(){
	return lName;
}