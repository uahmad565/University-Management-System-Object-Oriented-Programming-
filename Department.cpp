#include "Department.h"
#include<iostream>
#include "Course.h"
#include "Teacher.h"
#include"help.h"
#include"helpTemplate.h"
#include"Student.h"
#include"HOD.h"
#include <stdexcept>
#include "IdGenerator.h"
#include "Enums.h"
#include "UserInputs.h"
using namespace std;

IdGenerator Department::idGenerator = IdGenerator();

Department::Department(char* name,int courseMax )
	:currentCourseCount(0),currentTeachersCount(0),currentStudentsCount(0)
	,teacherCapacity(10),courseCapacity(courseMax),studentCapacity(10)
{
	if ((help::validationCharArray(name)) == false)
		throw exception("invalid Name");
	help::memoryAllocateAndCopy(this->name, name);
	this->departmentId = idGenerator.getNextId();
	if (courseMax > 0)
	{
		this->courses = new const Course*[courseCapacity];
	}
	else
		throw invalid_argument("Course Count should be less than 0");
	teachers = new const Teacher*[teacherCapacity];
	students = new const Student*[studentCapacity];
	this->hod = nullptr;
}



Department::~Department()
{
	if (courses != nullptr)
	{
		delete[] this->courses;
	}
	if (students != nullptr)
	{
		delete[] this->students;
	}
	if (teachers != nullptr)
	{
		delete[] this->teachers;
	}

}

Department& Department::setName(char* name)
{
	if ((help::validationCharArray(name)) == false)
		throw exception("invalid Name");
	if (name != nullptr)
		delete[]name;
	help::memoryAllocateAndCopy(this->name, name);
	return *(this);
}

char* Department::getName() const
{
	return this->name;
}

int Department::getId() const
{
	return departmentId;
}

int Department::getCourseCapacity() const
{
	return courseCapacity;
}

int Department::getCurrentCourses() const
{
	return currentCourseCount;
}

Department& Department::setHeadOfDepartment(const HOD& hod)
{
	this->hod = &hod;
	return *this;
}

Department& Department::setIT_Manager(const ITManager & it_manager)
{
	IT_Manager = &it_manager;
	return *this;
}

HOD* Department::getHeadOfDepartment() const
{
	return (HOD*)hod;
}

ITManager * Department::getIT_Manager() const
{
	return const_cast<ITManager*>(IT_Manager);
}

Department& Department::addCourse(const Course& course)
{
	if (!help::hasCapacity(currentCourseCount,courseCapacity))
	{
		helpTemplate::grow2DArray(courses,currentCourseCount);
	}
	courses[currentCourseCount] = &course;
	currentCourseCount++;
	return *this;
}

Department& Department::addStudent(const Student & student)
{
	if (!help::hasCapacity(currentStudentsCount, studentCapacity))
	{
		helpTemplate::grow2DArray(students, currentStudentsCount);
	}
	students[currentStudentsCount++] = &student;
	return *this;
}

Department& Department::addTeacher(const Teacher & teacher)
{
	if (!help::hasCapacity(currentTeachersCount, teacherCapacity))
	{
		helpTemplate::grow2DArray(teachers, currentTeachersCount);
	}
	teachers[currentTeachersCount++] = &teacher;
	return *this;
}

Department& Department::eliminateStudent(const Student & student)
{
	
	int index=helpTemplate::checkPresence(student, students, currentStudentsCount);
	if (index != -1)
	{
		helpTemplate::removePointerFrom2DArray(students, currentStudentsCount, index);
		currentStudentsCount--;
	}
	else
		throw invalid_argument("this Student doesn't exist");
	return *this;
}

Department&  Department::eliminateTeacher(const Teacher & teacher)
{
	int index = helpTemplate::checkPresence(teacher, teachers, currentTeachersCount);
	if (index != -1)
	{
		helpTemplate::removePointerFrom2DArray(teachers, currentTeachersCount, index);	
		currentTeachersCount--;
	}
	else
		throw invalid_argument("this Student doesn't exist");
	return *this;
}

Department& Department::eliminateCourse(const Course & course)
{
	int index = helpTemplate::checkPresence(course, courses, courseCapacity);
	if (index != -1)
	{
		helpTemplate::removePointerFrom2DArray(courses, courseCapacity, index);
	}
	else
		throw invalid_argument("this Student doesn't exist");
	return *this;

}

Teacher ** Department::getTeachers() const
{
	return const_cast<Teacher**>(teachers);
}

int Department::getCurrentTeachers() const
{
	return currentTeachersCount;
}

Course ** Department::getCourses() const
{
	return (Course**)courses; //const cast
}

Student ** Department::getStudents() const
{
	return (Student**)students;
}

int Department::getCurrentStudents() const
{
	return currentStudentsCount;
}

bool Department::operator==(const Department & obj)const
{
	return help::charArrayCompare(name, obj.getName());
}

Course * Department::getCourseByCode(char* courseCode)
{
	Course* course = nullptr;
	for (int i = 0; i < currentCourseCount; i++)
	{
		if (help::charArrayCompare(courses[i]->getCode(), courseCode))
		{
			course = (Course*)courses[i];
		}
	}

	return course;
}

Course * Department::getCourseById(int id) const
{
	Course* course = nullptr;
	for (int i = 0; i < currentCourseCount; i++)
	{
		if (courses[i]->getId() == id)
		{
			course = (Course*)courses[i];
		}
	}

	return course;
}

Teacher * Department::getTeacherById(int teacherID) const
{
	Teacher* teacher = nullptr;
	for (size_t i = 0; i < currentTeachersCount; i++)
	{
		if (teachers[i]->getUserID() == teacherID)
		{
			return teacher = (Teacher*) teachers[i];
		}
	}

	return teacher;
}

int Department::getDepartmentId() const
{
	return this->departmentId;
}

void Department::setDepartmentId(int id)
{
	this->departmentId = id;
}

Student * Department::getStudentByID(int id) const
{
	Student*student = nullptr;
	for (int i = 0; i < currentStudentsCount; i++)
	{
		if (students[i]->getUserID() == id)
		{
			student = (Student*)students[i];
		}
	}
	return student;
}

void Department::printDepartment() const
{
	UserInputs::setConsoleColor(WHITE);
	cout << "Department#" << endl;
	cout << departmentId << "-" << name << endl;
	cout << "Current Courses: "
		<< currentCourseCount << endl
		<< "Current Students: " << currentStudentsCount<<endl
		<< "Current Teachers: " << currentTeachersCount<<endl;
		cout << endl;	
}

void Department::printCourses() const
{
	UserInputs::setConsoleColor(WHITE);
	cout << endl << "Following courses are available:" << endl;
	for (int i = 0; i < currentCourseCount; i++)
	{
		cout << courses[i]->getId() << "    " << courses[i]->getCode() << "    " 
			<<courses[i]->getName();
		cout << endl;
	}
}

void Department::printStudents() const
{
	if (currentStudentsCount == 0)
	{
		UserInputs::setConsoleColor(YELLOW);
		cout << "\nNo Students Are Availabe for " << getName() << endl;
	}
	else {
		UserInputs::setConsoleColor(WHITE);
		cout << endl << "\nFollowing students are available for " << getName() << endl;
		for (int i = 0; i < currentStudentsCount; i++)
		{
			cout << students[i]->getUserID() << "    " << students[i]->getName();
			cout << endl;
		}
	}
	
}

void Department::printTeachers() const
{
	UserInputs::setConsoleColor(WHITE);
	if (currentTeachersCount == 0)
	{
		UserInputs::setConsoleColor(YELLOW);
		cout << "\nNo Teachers Are Availabe for " << getName() << endl;
	}
	else {
		UserInputs::setConsoleColor(WHITE);
		cout << endl << "\nFollowing teachers are available for " << getName() << " Department" << endl;
		for (int i = 0; i < currentTeachersCount; i++)
		{
			cout << teachers[i]->getUserID() << "    " << teachers[i]->getName();
			cout << endl;
		}
	}
	
}


