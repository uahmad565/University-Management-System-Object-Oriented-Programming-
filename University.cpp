#include "University.h"
#include "Department.h"
#include"help.h"
#include"helpTemplate.h"
#include"UserInputs.h"
#include"Enums.h"
#include <stdexcept>
#include<iostream>
using namespace std;

University::University(char* name, int departmentCount)
{
	if ((help::validationCharArray(name)) == false)
		throw exception("invalid Name");
	help::memoryAllocateAndCopy(this->name, name);
	if (departmentCount > 0)
	{
		this->departmentCapacity = departmentCount;
		this->departments = new const Department * [departmentCount];
	}
	else 
	{
		this->departmentCapacity = 0;
	}
	this->currentDepartmentsCount = 0;
}



University::~University()
{
	if (name != nullptr)
	{
		delete []name;
	}
	if (departments != nullptr)
	{
		delete[]departments;
	}
}

University University::setName(char * name)
{
	if ((help::validationCharArray(name)) == false)
		throw exception("invalid Name");
	if (name != nullptr)
		delete[]name;
	help::memoryAllocateAndCopy(this->name, name);
	return *this;

}

char* University::getName() const
{
	return name;
}

Department * University::getDepartmentById(int id)const
{
	Department* dept = nullptr;
	for (size_t i = 0; i < currentDepartmentsCount; i++)
	{
		if (departments[i]->getDepartmentId() == id)
		{
			dept = (Department*)departments[i];
		}
	}

	return dept;
}

Department ** University::getDepartments() const
{
	return (Department**)departments;
}

int University::getNoOfDepartments() const
{
	return currentDepartmentsCount;
}

void University::printUniversity() const
{
	
	cout <<"\tNAME: "<< getName() << " " <<endl 
	<<"\tCurrentDepartments: "<<getNoOfDepartments()<<endl;
	for (int i = 0; i < currentDepartmentsCount; i++)
	{
		cout << endl;
		departments[i]->printDepartment();
	}
}

void University::printDepartments() const
{
	if (currentDepartmentsCount == 0)
	{
		UserInputs::setConsoleColor(YELLOW);
		cout<<"No Departments Available To This " << getName() << endl;
	}
	else
	{
		UserInputs::setConsoleColor(WHITE);
		cout << "\nFollowing Are The Departments Of The " << getName() << endl;
		for (int i = 0; i < currentDepartmentsCount; i++)
		{
			cout << " " << departments[i]->getId() << " " << departments[i]->getName() << endl;
		}
	}
}

University& University::addDepartment(const Department& department)
{
	if (!help::hasCapacity(currentDepartmentsCount, departmentCapacity))
		helpTemplate::grow2DArray(departments, currentDepartmentsCount);

	this->departments[currentDepartmentsCount] = &department;
	currentDepartmentsCount++;
	return *this;
}
