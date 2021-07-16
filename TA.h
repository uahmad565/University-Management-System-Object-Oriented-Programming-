#pragma once
#include"Teacher.h"
#include"Student.h"

class Course;
class TA:Teacher,Student
{
private:
	Course*course;
public:
	TA(int userID, int password, char*name, const Department* department, Course* course);
	void printTA()const;

};

