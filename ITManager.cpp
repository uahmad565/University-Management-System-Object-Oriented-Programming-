#include "ITManager.h"
#include"Department.h"
#include"Student.h"
#include"Teacher.h"
#include"Person.h"
#include<iostream>
using namespace std;

ITManager::ITManager(int userID, int password, char*name,  Department* department)
	:Employee(userID,password,name),Person(userID,password)
{
	this->department = department;
}

ITManager::~ITManager()
{
	if (department != nullptr)
		delete department;
}

void ITManager::createAccountStudent(const Student& student)
{
	department->addStudent(student);
}

bool ITManager::deleteAccountStudent(const Student& student)
{
	
	department->eliminateStudent(student);
	return false;
}

bool ITManager::deleteAccountFaculty(const Teacher& teacher)
{
	department->eliminateTeacher(teacher);
	return false;
}

bool ITManager::createAccountFaculty(const Teacher& teacher)
{
	department->addTeacher(teacher);
	return false;
}

bool ITManager::setAccountPass(Person * person,int password)
{
	return person->setPassword(password);
	
}

bool ITManager::setAccountUserID(Person * person, int userId)
{
	return person->setUserID(userId);
}

int ITManager::getAccountPass(Person * person)
{
	return person->getPassword();
}

void ITManager::printITManager() const
{
	cout << getUserID() << " " << Employee::getName();
	cout << endl;
	department->printDepartment();
}

Department * ITManager::getDepartment() const
{
	return department;
}

bool ITManager::operator==(const ITManager & obj) const
{
	return Employee::getUserID() == obj.getUserID();
}
