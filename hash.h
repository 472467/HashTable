#pragma warning
#ifndef HASH_H
#define HASH_H

#include <string.h>
#include <iostream>
#include <fstream> 
#include <ctype.h>
#include <cstdlib>
#include <stdio.h>
#include "linkedlist.h"

class HashTable
{
	public:
		HashTable(int);
		int getCollisions();
		int getTableSize();
		void findKey(char*, char*);
		LinkedList** getTable();
		void setCollisions(int);
		int getHashedID(Student*);
		void addToTable(Student*);
		void resizeTable(int);
		int convertCharToInt(char);
		int convertAlphabetToInt(char);
		int& getSeed();
		unsigned xor_hash(Student*);
		unsigned long shittyHashFunction(Student*);
		
		
	private:
		int collisions;
		LinkedList** table;;
		int tableSize;
		int seed;
	
};

#endif