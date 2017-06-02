#include "hash.h"
using namespace std;

HashTable::HashTable(int tS){
	tableSize = tS;
}

int HashTable::getCollisions(){
	return collisions;
}

void HashTable::setCollisions(int c){
	collisions = c;
}

void HashTable::changeTableSize(int newSize){//cahnge + rehash
	
}

int HashTable::getHashedID(Student* s){//hashFunction
	/*
	Prioritizes starts of fName and lName
	Resizes based on current table size
	max size without resize: 129.642857143
	*/
	float hashedID = 0;
	float maxWithoutResize = 129.642857143;
	char* fName = s->getFName();
	char* lName = s->getLName();
	
	int count = 0;
	while(fName[count] != '\0'){
		hashedID += (convertCharToInt(fName[count])/(count+1));
	}
	count= 0;
	while(lName[count] != '\0'){
		hashedID += (convertCharToInt(lName[count])/(count+1));
	}
	
	//calculated using math
	float resizedID = (hashedID * tableSize)/maxWithoutResize;
	
	return (int)resizedID;
}

void HashTable::addToTable(Student* s){
	int hashedID = getHashedID(s);
	
	char* l = new char[10];
	char* f = new char[10];
	
	strcpy(l,s->getLName());
	stpcpy(f,s->getFName());
	
	Student* clone = new Student(f, l, s->getGPA());
	
	if(table[hashedID] == NULL){
		LinkedList* t =new LinkedList(clone);
		table[hashedID] = t;
	}else{
		LinkedList* current = table[hashedID];
		while(current->getNext() != NULL){
			current = current->getNext();
		}
		LinkedList* t =new LinkedList(clone); 
		current->setNext(t);
	}
}

int HashTable::convertCharToInt(char c ){
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
