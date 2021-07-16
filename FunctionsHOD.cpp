#include "FunctionsHOD.h"
#include "Department.h"
#include "Course.h"
#include "Teacher.h"
#include "UserInputs.h"
#include "HOD.h"
#include "Student.h"
#include <iostream>
using namespace std;

void FunctionsHOD::AssignCourseToTeacher(HOD* hod)
{
	UserInputs::setConsoleColor(WHITE);
	system("cls");
	cout << "\t\tProfile Name: " << hod->getName() << endl;
	cout << "\t\tProfile UserID: " << hod->getUserID() << endl;
	cout << "\n*********Command For Assigning a Course For Teacher" << endl;
	hod->getDepartment()->printCourses();
	hod->getDepartment()->printTeachers();
	UserInputs::setConsoleColor(WHITE);
	Course* course = UserInputs::getCourseFromUser(hod->getDepartment());
	Teacher* teacher = UserInputs::getTeaherFromUser(hod->getDepartment());
	cout << endl;
	bool added = hod->assignCoursesToTeachers(*course, *teacher);
	cout << endl;
	if (added)
	{
		system("cls");
		cout << "RECENT INFORMATION:" << endl;
		UserInputs::setConsoleColor(GREEN);
		cout << "Course " << course->getCode() << " has been assigned to teacher " << teacher->getName() << "." << endl;
	}
	else 
	{
		system("cls");
		cout << "RECENT INFORMATION:" << endl;
		UserInputs::setConsoleColor(YELLOW);
		cout << "Course " << course->getCode() << " was already assigned to teacher " << teacher->getName() << "." << endl;
	}

	UserInputs::setConsoleColor(GREEN);
	teacher->printCourses();
}

void FunctionsHOD::RegisterCourseForStudent(HOD * hod)
{
	UserInputs::setConsoleColor(WHITE);
	system("cls");
	cout << "\t\tProfile Name: " << hod->getName() << endl;
	cout << "\t\tProfile UserID: " << hod->getUserID() << endl;
	cout << "\n*********Command For Assigning a Course For Student" << endl;
	hod->getDepartment()->printCourses();
	hod->getDepartment()->printStudents();
	UserInputs::setConsoleColor(WHITE);
	Course* course = UserInputs::getCourseFromUser(hod->getDepartment());
	Student* student = UserInputs::getStudentFromUser(hod->getDepartment());
	bool added = hod->registerCourseForStudent(*course, *student);
	cout << endl;
	cout << endl;
	if (added)
	{
		system("cls");
		cout << "RECENT INFORMATION:" << endl;
		UserInputs::setConsoleColor(GREEN);
		cout << "Course " << course->getCode() << " has been registered for student " << student->getName() << "." << endl;
	}
	else
	{
		system("cls");
		cout << "RECENT INFORMATION:" << endl;
		UserInputs::setConsoleColor(YELLOW);
		cout << "Course " << course->getCode() << " was already registered for student " << student->getName() << "." << endl;
	}
	student->printCourses();
}

void FunctionsHOD::UnregisterCourseForStudent(HOD * hod)
{
	UserInputs::setConsoleColor(WHITE);
	system("cls");
	cout << "\t\tProfile Name: " << hod->getName() << endl;
	cout << "\t\tProfile UserID: " << hod->getUserID() << endl;
	cout << "\n*********Command For Unregister a Course For Student" << endl;
	hod->getDepartment()->printStudents();
	Student* student = UserInputs::getStudentFromUser(hod->getDepartment());
	cout << endl;
	student->printCourses();
	cout << endl;
	if (student->getCurrentCourseCount() > 0)
	{
		Course* course = UserInputs::getStudentCourseFromUser(student);
		hod->unRegisterCourseForStudent(*course, *student);
		system("cls");
		cout << "RECENT INFORMATION:" << endl;
		UserInputs::setConsoleColor(GREEN);
		cout << "Course " << course->getCode() << " has been unregistered from student " << student->getName() << "." << endl;
		student->printCourses();
	}
	else {
		system("cls");
		cout << "RECENT INFORMATION:" << endl;
		UserInputs::setConsoleColor(YELLOW);
		cout << "This " << student->getName() << " have no more Registerations" << endl;
	}
}

void FunctionsHOD::ViewGradesOfCourse(HOD * hod)
{
	UserInputs::setConsoleColor(WHITE);
	system("cls");
	cout << "\t\tProfile Name: " << hod->getName() << endl;
	cout << "\t\tProfile UserID: " << hod->getUserID() << endl;
	cout << "\n*********Command For Viewing Grades of a Course" << endl;
	hod->getDepartment()->printCourses();
	Course* course = UserInputs::getCourseFromUser(hod->getDepartment());
	cout << endl;
	if (course->getCurrentRegisterations() == 0)
	{
		system("cls");
		cout << "RECENT INFORMATION:" << endl;
		UserInputs::setConsoleColor(YELLOW);
		cout << "No registrations exist for this course." << endl;
	}
	else
	{
		system("cls");
		cout << "RECENT INFORMATION:" << endl;
		hod->viewGrades(*course);
	}
}
