#pragma warning
#ifndef STUDENT_H
#define STUDENT_H

#include <string.h>
#include <iostream>

class Student
{
	public:
		Student(int&);
		Student(char*,char*,float);
		~Student();
		
		char* getFName();
		char* getLName();
		float getGPA();
		void genFName();
		void genLName();
		
	private:
		char* fName;
		char* lName;
		float gpa;
	
};

#endif