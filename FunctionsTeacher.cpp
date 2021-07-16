#include"FunctionsTeacher.h"
#include"Teacher.h"
#include"UserInputs.h"
#include"Department.h"
#include"Course.h"
#include"Student.h"
#include "Registeration.h"
#include<iostream>
using namespace std;

void FunctionsTeacher::ManageAttendanceCourse(Teacher * teacher)
{
	teacher->printCourses();
	if (teacher->getCurrentCourseCount() == 0)
	{
		return;
	}

	Course* course = UserInputs::getCourseFromUser(teacher->getDepartment());
	course->printRegisterations();
	if (course->getCurrentRegisterations() == 0)
	{
		return;
	}

	Registeration* registration = UserInputs::getRegistrationFromUser(course);

	teacher->ManageAttendanceCourse(course->getId(), registration->getId());
	UserInputs::setConsoleColor(GREEN);
	system("cls");
	cout << " Attendance has been updated." << endl;
	cout << endl;
	course->printRegisterations();
}

void FunctionsTeacher::viewAttendanceCourse(Teacher * teacher)
{
	UserInputs::setConsoleColor(WHITE);
	Department*department = teacher->getDepartment();
	cout << endl;
	teacher->printCourses();	
	if (teacher->getCurrentCourseCount() == 0)
	{
		return;
	}
	cout << endl;
	Course*course=UserInputs::getTeacherCourseFromUser(teacher);
	teacher->viewAttendanceCourse(*course);
}

void FunctionsTeacher::ManageEvaluationStudent(Teacher * teacher)
{
	UserInputs::setConsoleColor(WHITE);
	cout << endl;
	teacher->printCourses();
	if (teacher->getCurrentCourseCount() == 0)
	{
		return;
	}
	cout << endl;
	Course*course = UserInputs::getTeacherCourseFromUser(teacher);
	course->printRegisterations();
	if (course->getCurrentRegisterations() == 0)
	{
		return;
	}
	Registeration*registeration= UserInputs::getRegistrationFromUser(course);
	float Marks[2];
	UserInputs::getEvaluationMarksFromUser(Marks);
	teacher->ManageEvaluationStudent(registeration, Marks[0], Marks[1]);
	cout << "\nEvaluation has been managed to "<< registeration->getStudent()->getUserID()
		<<" " <<registeration->getStudent()->getName()<<endl;
	course->viewMarkSheet();
}

void FunctionsTeacher::AssignGradesToStudents(Teacher * teacher)
{
	teacher->printCourses();
	if (teacher->getCurrentCourseCount() == 0)
	{
		return;
	}
	Course*course = UserInputs::getTeacherCourseFromUser(teacher);
	course->printRegisterations();
	if (course->getCurrentRegisterations()== 0)
	{
		return;
	}
	Registeration*registeration = UserInputs::getRegistrationFromUser(course);
	Grade grade = UserInputs::getGradeFromUser();
	teacher->AssignGradesToStudents(registeration,grade);
	course->viewGrades();
}

void FunctionsTeacher::viewEvaluationCourse(Teacher* teacher)
{
	teacher->printCourses();
	cout << endl;
	if (teacher->getCurrentCourseCount() == 0)
	{
		return;
	}
	Course*course = UserInputs::getTeacherCourseFromUser(teacher);
	teacher->viewEvaluationCourse(*course);
}
