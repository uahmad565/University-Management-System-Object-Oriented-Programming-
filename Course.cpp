#include "Course.h"
#include "Student.h"
#include"Teacher.h"
#include"help.h"
#include"TA.h"
#include"help.h"
#include"Registeration.h"
#include"helpTemplate.h"
#include<stdexcept>
#include<iostream>
#include "IdGenerator.h"
#include "UserInputs.h"
#include "Enums.h"
using namespace std;

IdGenerator Course::idGenerator = IdGenerator();

Course::~Course()
{
	if (code != nullptr)
	{
		delete[]code;
			
	}
	if (name!=nullptr)
	{
		delete[] name;
	}
	if (teachers != nullptr)
	{
		delete[]teachers;
	}
	if (registerations != nullptr)
	{
		delete[]registerations;
	}
}

Course::Course(char*code, char* name)
	:maxRegisterations(50),currentRegistrations(0),currentTeachersCount(0)
	,teachersCapacity(10)
{
	if (help::validationCharArray(name) == false || help::validationCharArray(code) == false)
		throw exception("invalid Name or code");
	help::memoryAllocateAndCopy(this->name, name);
	help::memoryAllocateAndCopy(this->code, code);
	registerations = new const Registeration*[maxRegisterations];
	teachers = new const Teacher*[teachersCapacity];
	for (int i = 0; i < teachersCapacity; i++)
	{
		teachers[i] = nullptr;
	}
	for (int i = 0; i < maxRegisterations; i++)
	{
		registerations[i] = nullptr;
	}
	this->assistant = nullptr;
	this->id = idGenerator.getNextId();
}





Course Course::setCode(char* code)
{
	if (help::validationCharArray(code) == false)
		throw exception("invalid Name or code");
	if (code != nullptr)
		delete[]code;
	help::memoryAllocateAndCopy(this->code, code);
	return *this;
}

char* Course::getCode() const
{

	return code;
}

Course Course::setName(char* name)
{
	if (help::validationCharArray(name) == false )
		throw exception("invalid Name or code");
	if (name != nullptr)
		delete[]name;
	help::memoryAllocateAndCopy(this->name, name);
	return *this;
}

char* Course::getName() const
{
	return (*this).name;
}

Registeration ** Course::getRegisterations()const
{
	return (Registeration**)registerations;
}

int Course::getCurrentRegisterations() const
{
	return currentRegistrations;
}

Course Course::setAssistant(const TA* assistants)
{
	if (assistants != nullptr)
	{
		this->assistant = assistants;
	}
	return *this;
}

TA* Course::getAssistant() const
{
	return const_cast<TA*>(assistant);
}




bool Course::addRegistration(const Registeration & registration)
{
	if (help::hasCapacity(currentRegistrations, maxRegisterations))
	{
		registerations[currentRegistrations] = &registration;
		currentRegistrations++;
		return true;
	}
	return false;
}

bool Course::addRegistration(const Registeration * registeration)
{
	if (currentRegistrations != maxRegisterations)
	{
		registerations[currentRegistrations] = registeration;
		currentRegistrations++;
		return true;
	}
	return false;
}

Registeration * Course::getRegistrationById(int registrationId) const
{
	for (int i = 0; i < currentRegistrations; i++)
	{
		if (registerations[i]->getId() == registrationId)
			return (Registeration*)registerations[i];
	}
	return nullptr;
}

bool Course::removeRegistrationbyID(int id)
{
	int i = 0;
	for (; i < currentRegistrations; i++)
	{
		if (registerations[i]->getId() == id)
		{
			helpTemplate::removePointerFrom2DArray(this->registerations, currentRegistrations, i);
			currentRegistrations--;
			return true;
		}
	}
	return false;
}

bool Course::operator==( const Course & obj)
{
	if (help::charArrayCompare(this->code,obj.code))
		return true;
		return false;
}

void Course::viewGrades() const
{
	if (currentRegistrations == 0)
	{
		UserInputs::setConsoleColor(YELLOW);
		cout << "\nNo Registerations in this course " << getName() << endl;
	}
	else {
		UserInputs::setConsoleColor(GREEN);
		cout << "\nFollowing are the Grades To this Course" << endl;
		UserInputs::setConsoleColor(WHITE);
		for (int i = 0; i < currentRegistrations; i++)
		{
			Student*student = registerations[i]->getStudent();
			cout << student->getName() << " ( " << student->getuserID() <<" )"<< endl
			<<"  Grade: " <<help::gradeToString(registerations[i]->getGrade()) << endl;
		}
	}
}
void Course::viewMarkSheet() const
{
	if (currentRegistrations == 0)
	{
		UserInputs::setConsoleColor(YELLOW);
		cout << "No Registerations are Available to " << getCode() << " " << getName() << endl;
	}	
	else
	{
		UserInputs::setConsoleColor(WHITE);
		cout << "\nFollowing are the Registerations With Mark Sheet" << endl;
		for (int i = 0; i < currentRegistrations; i++)
		{
			Student*student = registerations[i]->getStudent();
			cout << student->getuserID() << " " << student->getName() << endl;
			cout<<"  Grade: "<<help::gradeToString(registerations[i]->getGrade())<<endl
			 << "  CGPA: " << registerations[i]->getGPA()<<endl
				<<"  Obtained: "<< registerations[i]->getObtainedMarks()<< "/100"<<endl;
		}
	}

}

void Course::viewAttendanceCourse() const
{
	if (currentRegistrations == 0)
	{
		UserInputs::setConsoleColor(YELLOW);
		cout << "No registrations are available for course " << this->getCode() << endl;
	}
	else
	{
		UserInputs::setConsoleColor(WHITE);
		cout << "\nFollowing is the attendance of course " << this->getCode() << endl;
		for (int i = 0; i < currentRegistrations; i++)
		{
			registerations[i]->viewAttendance();
		}
	}
}

int Course::getId() const
{
	return this->id;
}

bool Course::removeRegistrationbyId(int id)
{
	int index = -1;
	for (int i = 0; i < currentRegistrations; i++)
	{
		if (registerations[i]->getId() == id)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		int j = index;
		for (; j < currentRegistrations - 1; j++)
		{
			registerations[j] = registerations[j + 1];

		}
		currentRegistrations--;
		return true;
	}
	return false;
}



void Course::addTeacher(const Teacher & teacher)
{
	if (!help::hasCapacity(currentTeachersCount, teachersCapacity))
	{
		helpTemplate::grow2DArray(teachers, teachersCapacity);
	}
	this->teachers[currentTeachersCount] = &teacher;
	currentTeachersCount++;
}

void Course::printCourse() const
{
	cout << id<<"  " <<code << "  " << name<< endl;
}

void Course::printCourseFullInformation() const
{
	printCourse();
	assistant->printTA();
}

void Course::printRegisterations() const
{
	if (this->currentRegistrations == 0)
	{
		UserInputs::setConsoleColor(YELLOW);
		cout << "No registrations are available for this course." << endl;
	}
	else
	{
		UserInputs::setConsoleColor(WHITE);
		cout << "Following registrations are available for this course." << endl;
		for (int i = 0; i < currentRegistrations; i++)
		{
			registerations[i]->viewAttendance();
			cout << endl;
		}
	}
}

Registeration * Course::getRegisterationByCourseID(int id) const
{
	for (int i = 0; i < currentRegistrations; i++)
	{
		if (registerations[i]->getCourse()->getId() == id)
			return (Registeration*)registerations[i];
	}
	return nullptr;
}






