#include "Student.h"
#include "Course.h"
#include"help.h"
#include"helpTemplate.h"
#include"Registeration.h"
#include<stdexcept>
#include<iostream>
#include "UserInputs.h"
#include "Enums.h"
using namespace std;




Student::Student(int userID,int password,char* name, const Department* department)
	: Person(userID,password),department(department),currentRegisterations(0)
	,registerationCapacity(5)
{
	if ( help::validationCharArray(name) == false)
		throw exception("invalid  name");
	help::memoryAllocateAndCopy(this->name, name);
	registerations = new const Registeration*[registerationCapacity];
}


Student::~Student()
{
	if (registerations != nullptr)
		delete[] this->registerations;
}

int Student::getuserID() const
{
	return Person::getUserID();
}

bool Student::setPassword(int password)
{
	return Person::setPassword(password);
}

int Student::getPassword() const
{
	return Person::getPassword();
}

char * Student::getName() const
{
	return name;
}



Student Student::setDepartment(const Department& department)
{
	this->department = &department;
	return *this;
}

Department* Student::getDepartment() const
{
	return (Department*)department;
}

int Student::getCourseCapacity() const
{
	return registerationCapacity;
}

Registeration* Student::getRegisterationByCourseID(int id) const
{
	for (int i = 0; i < currentRegisterations; i++)
	{
		if (registerations[i]->getCourse()->getId() == id)
			return (Registeration*)registerations[i];
	}
	return nullptr;
}

int Student::getCurrentCourseCount() const
{
	return currentRegisterations;
}

int Student::getCurrentRegisterations() const
{
	return currentRegisterations;
}

Course* Student::getCourseById(int id) const
{
	for (int i = 0; i < currentRegisterations; i++)
	{
		if (registerations[i]->getCourse()->getId() == id)
			return registerations[i]->getCourse();
	}
	return nullptr;
}

Registeration ** Student::getRegisterations() const
{
	return (Registeration**)registerations;
}

bool Student::addRegisterations(const Registeration & registeration)
{
	if (help::hasCapacity(currentRegisterations, registerationCapacity))
	{
		registerations[currentRegisterations] = &registeration;
		currentRegisterations++;
		return true;
	}
	return false;
}

Registeration * Student::getRegistrationById(int registrationId)
{
	for (int i = 0; i < currentRegisterations; i++)
	{
		if (registerations[i]->getId() == registrationId)
		{
			return (Registeration*)registerations[i];
		}
	}
	return nullptr;
}

bool Student::removeRegisterations(Registeration* registeration)
{
	int index=helpTemplate::checkPresence(*registeration, registerations, currentRegisterations);
	if (index != -1)
	{
		helpTemplate::removePointerFrom2DArray(registerations, currentRegisterations, index);
		return true;
	}
	return false;
}

void Student::addRegisteration(const Registeration * registeration)
{
	if (currentRegisterations != registerationCapacity)
	{
		registerations[currentRegisterations] = registeration;
		currentRegisterations++;
	}
}


bool Student::registerCourse(Course&course)
{
	Registeration*registeration=getRegisterationByCourseID(course.getId());
	if (registeration == nullptr)
	{
		Registeration*registeration = new Registeration(*(this), course);
		addRegisterations(*registeration);
		course.addRegistration(*registeration);
		return true;
	}
	return false;
		
}

bool Student::unregisterCourse( Course & course)
{
	Registeration*registeration=getRegisterationByCourseID(course.getId());
	int id = registeration->getId();
	course.removeRegistrationbyId(id);
	if (removeRegisterations(registeration))
	{
		 currentRegisterations--;
		 return true;
	}
	 return false;
}

bool Student::withDrawCourse(Course & course)
{
	Registeration**registerations = this->getRegisterations();
	int currentRegs = this->getCurrentRegisterations();
	bool presence = false;
	for (int i = 0; i < currentRegs && !presence; i++)
	{
		if (*(registerations[i]->getCourse()) == course)
		{
			presence = true;
			registerations[i]->setGrade(W);
			return true;
		}
	}
	return false;
}

bool Student::operator==(const Student & obj)
{
	if (Person::getUserID()==obj.getUserID())
		return true;
	return false;
}

void Student::changePassword(int password)
{
	setPassword(password);
}

void Student::ViewMarkSheetCourse(const Course& course) const
{
	course.viewMarkSheet();
}

void Student::viewAttendanceCourse(const Course & course) const
{
	course.viewAttendanceCourse();
}

void Student::printStudent() const
{
	cout << "Student#" << endl;
	cout << getUserID() << " " << getName() << endl;
	cout<<department -> getName();
}

void Student::printCourses() const
{
	if (currentRegisterations == 0)
	{
		UserInputs::setConsoleColor(YELLOW);
		cout << "\nNo courses have been registered with " << this->getName() << "." << endl;
	}
	else
	{
		UserInputs::setConsoleColor(WHITE);
		cout << "\nFollowing Courses are Registered to this Student" << endl;
		for (int i = 0; i < currentRegisterations; i++)
		{
			registerations[i]->getCourse()->printCourse();
		}
	}
}

void Student::printCoursesWithGrades() const
{
	if (currentRegisterations == 0)
	{
		UserInputs::setConsoleColor(YELLOW);
		cout << "\nNo Registerations are available yet\n";
	}
	else
	{
		UserInputs::setConsoleColor(WHITE);
		cout << "\nFollowing are the Courses With Grades:" << endl;
		for (size_t i = 0; i < currentRegisterations; i++)
		{
			cout << registerations[i]->getCourse()->getId()<<" "<< registerations[i]->getCourse()->getCode()
				<<"-"<< registerations[i]->getCourse()->getName();
			cout << endl << "\tGrade: " << help::gradeToString(registerations[i]->getGrade()) << endl;
		}
	}
}
