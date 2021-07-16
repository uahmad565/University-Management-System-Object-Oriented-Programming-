#pragma once
#include <iostream>
#include "Enums.h"
using namespace std;

class University;
class UserInputs;
class Person;

class UniversitySystem
{
public:
	friend class UserInputs;
	static University* university;
	static Person* loggerIdPerson;
	static void PerformTasksHOD();
	static void PerformTasksITManager();
	static void PerformTasksTeacher();
	static void PerformTasksStudent();
	static Person* isUserIdAndPasswordValid(int userId, int password, int departmentId, Role role);
};