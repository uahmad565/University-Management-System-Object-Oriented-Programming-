#include<iostream>
using namespace std;
#include "Teacher.h"
#include "Course.h"
#include"Student.h"
#include"Department.h"
#include"help.h"
#include"helpTemplate.h"
#include"Registeration.h"
#include <stdexcept>
#include "UserInputs.h"
#include "Enums.h"

Teacher::Teacher(int userID ,int password,char*name,const Department* department, int courseCount )
	:Employee(userID,password,name),Person(userID,password),department(department)
{
	if (courseCount > 0)
	{
		this->courseCapacity = courseCount;
		this->currentCourseCount = 0;
		this->courses = new const Course*[courseCount]; 
	}
	else
	{
		this->courseCapacity = courseCount;
		this->currentCourseCount = 0;
	}
}

Teacher::Teacher(int userID, int password, char*name, const Department* department,Course const** courses, int courseCount )
:Teacher(userID,password, name,department, courseCount)
{
	if (courses != nullptr)
	{
		for (int i = 0; i < courseCount; i++)
		{
			this->courses[i] = courses[i];
		}

		this->currentCourseCount = courseCount;
	}
}

Teacher::~Teacher()
{
	if (courses != nullptr)
		delete[]this->courses;
}

Department * Teacher::getDepartment() const
{
	return const_cast<Department*>(department);
}



int Teacher::getUserID() const
{
	return Employee::getUserID();
}

char* Teacher::getName() const
{
	return Employee::getName();
}

int Teacher::getCourseCapacity() const
{
	return courseCapacity;
}

Course* Teacher::getCourseById(int id) const
{
	for (int i = 0; i < currentCourseCount; i++)
	{
		if (id == courses[i]->getId())
		{
			return (Course*)courses[i];
		}
	}
	return nullptr;
}

int Teacher::getCurrentCourseCount() const
{
	return currentCourseCount;
}

Teacher* Teacher::addCourse(const Course& course, bool& added)
{
	if (!help::hasCapacity(currentCourseCount,courseCapacity))
	{
		helpTemplate::grow2DArray(courses,currentCourseCount);
	}

	Course* existingCourse = getCourseById(course.getId());
	added = false;
	if (existingCourse == nullptr)
	{
		courses[currentCourseCount] = &course;
		currentCourseCount++;
		added = true;
	}

	return this;
}

bool Teacher::addCourse(const Course * course)
{
	if (!help::hasCapacity(currentCourseCount, courseCapacity))
	{
		helpTemplate::grow2DArray(courses, currentCourseCount);
	}

	Course* existingCourse = getCourseById(course->getId());
	if (existingCourse == nullptr)
	{
		courses[currentCourseCount] = course;
		currentCourseCount++;
		return true;
	}
	return false;
}

bool Teacher::operator==(const Teacher & obj)
{
	return  getUserID()== obj.getUserID();
}

void Teacher::ManageAttendanceCourse(int courseId, int RegisterationNo)
{
	Course* course = this->getDepartment()->getCourseById(courseId);
	Registeration* registrationFromCourse = course->getRegistrationById(RegisterationNo);

	registrationFromCourse->attendanceIncrement();
}

void Teacher::viewAttendanceCourse(const Course & course)
{
	course.viewAttendanceCourse();
}

void Teacher::ManageEvaluationStudent(Registeration * registeration, float gpa, float obtained)
{
	registeration->setGPA(gpa);
	registeration->setObtainedMarks(obtained);
}


void Teacher::AssignGradesToStudents(Registeration*registeration, Grade grade)
{
	registeration->setGrade(grade);
}

void Teacher::viewEvaluationCourse(const Course & course) const
{
	course.viewMarkSheet();
}

void Teacher::printTeacher() const
{
	cout << "Teacher#" << endl;
	cout << getUserID() << " " << getName() << endl;
	cout << department->getName();
}

void Teacher::printCourses() const
{
	if (currentCourseCount == 0)
	{
		UserInputs::setConsoleColor(YELLOW);
		cout << "\nNo courses have been assigned to " << this->getName() << "." << endl;
	}
	else
	{
		UserInputs::setConsoleColor(WHITE);
		cout << "Following are the courses Assigned to this Teacher:\n";
		for (int i = 0; i < currentCourseCount; i++)
		{
			courses[i]->printCourse();
		}
	}
}

