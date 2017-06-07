#include "hash.h"
#include <math.h> 
using namespace std;

HashTable::HashTable(int tS){
	tableSize = tS;
	seed = (time(NULL));
	table = new LinkedList*[tS];
	collisions = 0;
	for(int x = 0; x < tS; x++){
		table[x] = NULL;
	}
	
}

int HashTable::getCollisions(){
	return collisions;
}

void HashTable::setCollisions(int c){
	collisions = c;
}

void HashTable::resizeTable(int newSize){//cahnge + rehash
	LinkedList** newTable = new LinkedList*[newSize];
	for(int x = 0; x < newSize; x++){
		newTable[x] = NULL;
	}
	
	Student** studentStore = new Student*[tableSize + collisions + 5];
	int currentStudent = 0;
	for(int x = 0; x < tableSize; x++){
		if(table[x] == NULL){
		}else if(table[x]->getNext() == NULL){
			studentStore[currentStudent] = table[x]->getStudent();
			currentStudent++;
		}else{//collided students
			LinkedList* current = table[x];
			while(current != NULL){
				studentStore[currentStudent] = current->getStudent();
				current = current->getNext();
				currentStudent++;
			}
		}
	}
	table = new LinkedList*[newSize];
	for(int x = 0; x < newSize; x++){
		table[x] = NULL;
	}
	tableSize = newSize;
	collisions = 0;
	for(int x = 0; x < currentStudent; x++){
		addToTable(studentStore[x]);
		cout << "TEST" << endl;
	}
	
}

int HashTable::getHashedID(Student* s){//hashFunction
	/*
	Prioritizes starts of fName and lName
	Resizes based on current table size
	max size without resize: 129.642857143/2
	*/
	float hashedID = 0;
	float maxWithoutResize = 114.821428571/4;
	char* fName = s->getFName();
	char* lName = s->getLName();
	
	int count = 0;
	while(fName[count] != '\0'){
		hashedID += convertAlphabetToInt(fName[count])/((count*8) + 1);
		count++;
	}
	count= 0;
	while(lName[count] != '\0'){
		hashedID += convertAlphabetToInt(lName[count])/((count*8) + 1);
		count++;
	}
	
	//calculated using math
	float resizedID = (hashedID * tableSize)/maxWithoutResize;
	seed++;
	
	
	return (int)resizedID;
}

unsigned long HashTable::shittyHashFunction(Student* s){
	char* lName = s->getLName();
	char* fName = s->getFName();
	unsigned long maxValue = (2777777777777750);
	unsigned long hashNum = 0;
	
	char* p = new char[16];
	int count = 0;
	while(fName[count] != '\0'){
		p[count] = fName[count];
		count++;
	}
	int count2 = 0;
	while(lName[count2] != '\0'){
		p[count] = lName[count2];
		count2++;
		count++;
	}
	//count = 14;
	//p = "zzzzzzzzzzzzzzzzzzz";
	//cout << p << " "<< count << endl << endl;
	for(int x = 0; x < count; x++){
		hashNum+= (convertAlphabetToInt(p[x]) * pow(10,(14 - x)));
	}
	
	unsigned long resizedID = (hashNum * ((unsigned long)tableSize))/(maxValue);
	cout << seed << ", "<< resizedID << ", "<< tableSize << " F: " << fName << " L: " << lName << " RealID: " << hashNum << endl;
	return (unsigned long)(resizedID);
}

unsigned HashTable::xor_hash(Student* s){
	char* lName = s->getLName();
	char* fName = s->getFName();
	char* p = new char[16];
	int count = 0;
	while(fName[count] != '\0'){
		p[count] = fName[count];
		count++;
	}
	int count2 = 0;
	while(lName[count2] != '\0'){
		p[count] = lName[count2];
		count2++;
		count++;
	}
	
    unsigned h = 0;
    int constant = tableSize/800;

    for (int i = 0; i < count; i++){
        h = constant * h ^ p[i];
    }

	
	
    return h;
}

void HashTable::addToTable(Student* s){
	///int hashedID = getHashedID(s);
	unsigned testID = shittyHashFunction(s);
	//cout << getHashedID(s) << " ";
	
	char* l = new char[10];
	char* f = new char[10];
	
	strcpy(l,s->getLName());
	stpcpy(f,s->getFName());
	
	Student* clone = new Student(f, l, s->getGPA());
	//cout << l << endl <<f << endl;
	if(table[testID] == NULL){
		//cout << l << endl <<f << endl;
		LinkedList* t =new LinkedList(clone);
		
		table[testID] = t;
	}else{
		collisions++;
		LinkedList* current = table[testID];
		//cout << l << endl <<f << endl;
		while(current->getNext() != NULL){
			current = current->getNext();
		}
		LinkedList* t =new LinkedList(clone); 
		current->setNext(t);
	}
	
}

int HashTable::convertAlphabetToInt(char c){
	char* alphanum = "abcdefghijklmnopqrstuvwxyz";
	char* alphaCap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int x = 0; x < 26; x++){
		if(alphaCap[x] == c || alphanum[x] == c){
			//cout << "\n " << alphanum[x] << " = " << x; //<< endl;
			return x;
		}
	}
	cout <<"Fucking shit";
	return -10000;
}

int HashTable::getTableSize(){
	return tableSize;
}

void HashTable::findKey(char* fName, char* lName){
	Student* s = new Student(fName, lName, 1.0);
	
	LinkedList* current = table[getHashedID(s)];
	Student* foundStudent = NULL;
	
	while(current != NULL){
		if(strcmp((current->getStudent())->getFName(), fName) == 0 && strcmp((current->getStudent())->getFName(), fName) == 0 ){
			foundStudent = current->getStudent();
		}
		current = current->getNext();
	}
	
	if(foundStudent != NULL){
		cout << "Found Student: (L: " << foundStudent->getLName() << ", F: " << foundStudent->getFName() << ") gpa = " << foundStudent->getGPA() << "at " << getHashedID(s) << endl;
	}else{
		cout << "Student not found." << endl;
	}
	
	
}

LinkedList** HashTable::getTable(){
	return table;
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

int& HashTable::getSeed(){
	return seed;
}
