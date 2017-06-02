#include "linkedlist.h"

LinkedList::LinkedList(Student* s){
	student = s;
}

void LinkedList::setNext(LinkedList* n){
	next = n;
}

LinkedList* LinkedList::getNext(){
	return next;
}

Student* LinkedList::getStudent(){
	return student;
}

void LinkedList::setStudent(Student* s){
	student = s;
}