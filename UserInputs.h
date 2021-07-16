#pragma once
#include "Enums.h"
#include <Windows.h>
#include<iostream>
#include"University.h"
using namespace std;

class Department;
class Course;
class Student;
class Teacher;

class UniversitySystem;
class Registeration;

class UserInputs
{
public:
	static HANDLE consoleHandle;
	static Department* getDepartmentFromUser();
	static Course* getCourseFromUser(const Department* department);	
	static Course* getTeacherCourseFromUser(const Teacher* department);
	static Course* getStudentCourseFromUser(const Student* student);
	static Teacher* getTeaherFromUser(const Department* department);
	static Student* getStudentFromUser(const Department* department);
	static Registeration* getRegistrationFromUser(const Course* course);
	template<typename T>
	static T*createAccountInformation(bool type,Department*department); //type 0 create Faculty Account
	//type 1 create Student Account
	static int getPasswordFromUser(bool isNew = true);
	static int getUserIDFromUser(bool isNew = true);
	static Grade getGradeFromUser();
	static void getEvaluationMarksFromUser(float *Marks);
	static void setConsoleColor(Colors color);
};

template<typename T>
T* UserInputs::createAccountInformation(bool type, Department*department)
{

	int UserId = 0;
	int password = 0;
	cout <<endl<< "Enter UserID: ";
	cin >> UserId;
	cout << "Enter Passward: ";
	cin >> password;
	char name[1000];
	cin.ignore();
	do {
		cout << "Enter Valid Name: ";
		cin.getline(name, 1000);
		if (!help::validationCharArray(name))
		{
			cout << "Please Enter Valid Name: " << endl;
			cin >> name;
		}
	} while (!help::validationCharArray(name));
	/*UniversitySystem::university->printDepartments();*/
	/*Department*department = getDepartmentFromUser();*/
	T* obj = new T(UserId, password, name, department);
	return obj;
}

