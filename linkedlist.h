#pragma warning
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string.h>
#include <iostream>
#include "student.h"

class LinkedList
{
	public:
		LinkedList(Student*);
		LinkedList* getNext();
		void setNext(LinkedList*);
		void setStudent(Student*);
		Student* getStudent();
	private:
		Student* student;
		LinkedList* next;
	
};

#endif