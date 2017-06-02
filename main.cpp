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


int main(){
	cout << "dots in visualization represent empty locations\n";
	
	HashTable* head = NULL;
	
	while(true){
		
		
		char* input = new char[10];
		cout << "\n(a) - add // (p) - print // (d) - delete // (q) - quit\n\n";
		cout << "Enter command:" ;
		cin.getline(input, 10);
		
		translateInput(input, head);
	}
}

void translateInput(char* input, HashTable*& head){
	//char* input = new char[10];
	
	if(strcmp(input, "add") == 0 || strcmp(input, "a") == 0){
		cout << "Input a number of random students you would like to add to the table:\n";
		input = new char[9];
		cin.getline(input, 9);
		
		int amount = 0;
		int count = 0;
		while(input[count] != '\0'){
			amount = amount * 10 + convertCharToInt(input[count]);
			count++;
		}
		
		for(int x = 0; x < amount; x++){
			if(x % (amount/4) == 0 && x  != 0){
				cout << x << " out of " << amount << " students left.\n";
			}
		}
		
		
		
	}else if(strcmp(input, "print") == 0 || strcmp(input, "p") == 0){
		
		
		
	}else if(strcmp(input, "quit") == 0 || strcmp(input, "q") == 0){
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
		exit(24);
	}
}

void printStudent(Student* s){
	cout << "(L:" << s->getLName() << ", F:" << s->getFName() << ") gpa = " << s->getGPA() << endl;
}