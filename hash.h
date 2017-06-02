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
		void setCollisions(int);
		int getHashedID(Student*);
		void addToTable(Student*);
		void changeTableSize(int);
		int convertCharToInt(char);
		
		
	private:
		int collisions;
		LinkedList** table;;
		int tableSize;
	
};

#endif