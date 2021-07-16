#include "TA.h"
#include"Department.h"
#include<iostream>
using namespace std;

TA::TA(int userID, int password, char* name, const Department* department, Course* course)
	:Teacher(userID,password, name,  department), Student(userID,password,name,department)
	,Person(userID,password), course(course)
{
}

void TA::printTA() const
{
	cout << "Teacher Assistant:" << 
	Student::getUserID() << "-" << Student::getName() << endl;
}
