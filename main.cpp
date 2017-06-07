#include "student.h"
#include "linkedlist.h"
#include "hash.h"
#include <iostream>
#include <fstream> 
#include <ctype.h>
#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;

void translateInput(char*, HashTable*&);
int convertCharToInt(char);
void printStudent(Student* s);


int main(){
	cout << "dots in visualization represent empty locations\n";
	
	HashTable* hashTable = new HashTable(10000);
	
	while(true){
		
		
		char* input = new char[10];
		cout << "\n(a) - add // (p) - print // (f) - find // (d) - delete // (q) - quit\n\n";
		cout << "Enter command:" ;
		cin.getline(input, 10);
		
		translateInput(input, hashTable);
	}
}

void translateInput(char* input, HashTable*& hashTable){
	//char* input = new char[10];
	
	if(strcasecmp(input, "add") == 0 || strcasecmp(input, "a") == 0){
		cout << "Input a number of random students you would like to add to the table: ";
		input = new char[9];
		cin.getline(input, 9);
		
		int amount = 0;
		int count = 0;
		while(input[count] != '\0'){
			amount = amount * 10 + convertCharToInt(input[count]);
			count++;
		}
		
		for(int x = 0; x < amount; x++){
			Student* s = new Student(hashTable->getSeed());
			hashTable->addToTable(s);
		}
		
		while(hashTable->getCollisions() >= 3){
			cout <<endl<<endl<< hashTable->getCollisions() << endl << endl;
			hashTable->resizeTable(hashTable->getTableSize()*2);
		}
		
		
		
	}else if(strcasecmp(input, "find") == 0 || strcasecmp(input, "f") == 0){
		char* name = new char[20];
		cout << "Enter FIRST name of student you would like to find" << endl;
		cin.getline(name, 20);
		
		char* lName = new char[20];
		cout << "Enter LAST name of student you would like to find" << endl;
		cin.getline(lName, 20);
		
		Student* clone = new Student(name, lName, 0);
		
		unsigned hashID = hashTable->shittyHashFunction(clone);
		LinkedList* current = hashTable->getTable()[hashID];
		if(current == NULL){
			if(strcasecmp(name,(current->getStudent())->getFName()) == 0 && strcasecmp(lName,(current->getStudent())->getLName())){
				cout << "Student found at " << hashID;
				printStudent(current->getStudent());
			}
		}else{
			int count = 0;
			while(current != NULL){
				if(strcasecmp(name,(current->getStudent())->getFName()) == 0 && strcasecmp(lName,(current->getStudent())->getLName())){
					cout << "Student found at " << hashID;
					printStudent(current->getStudent());
				}
				
				current = current->getNext();
				count++;
			}
			if(count > 0){
				cout << count << " extra students found in linked chain.\n";
			}else{
				cout << "Student not found!";
			}
			
		}
		
	}else if(strcasecmp(input, "print") == 0 || strcasecmp(input, "p") == 0){
		LinkedList** table = hashTable->getTable();
		int count = 0;
		for(int x = 0; x < hashTable->getTableSize(); x++){
			LinkedList* current = table[x];
			if(current != NULL){
				printStudent(current->getStudent());
				current = current->getNext();
				count++;
			}
		}
		
		cout << "\n\n" << count << " Total Students." << endl;
		
	}else if(strcasecmp(input, "quit") == 0 || strcmp(input, "q") == 0){
		exit(0);
	}else{
		cout << "\nUnrecognized command.\n";
	}

	
	delete input;
}

int convertCharToInt(char c ){
	if(c == '0'){
		return 0;
	}else if(c == '1'){
		return 1;
	}else if(c == '2'){
		return 2;
	}else if(c == '3'){
		return 3;
	}else if(c == '4'){
		return 4;
	}else if(c == '5'){
		return 5;
	}else if(c == '6'){
		return 6;
	}else if(c == '7'){
		return 7;
	}else if(c == '8'){
		return 8;
	}else if(c == '9'){
		return 9;
	}else{
		cout << "\nError: trying to input non-number" << endl;
		//exit(24);
	}
}

void printStudent(Student* s){
	cout << "(L:" << s->getLName() << ", F:" << s->getFName() << ") gpa = " << s->getGPA() << endl;
}