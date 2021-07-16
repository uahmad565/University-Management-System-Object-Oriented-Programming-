#include "Registeration.h"
#include"Student.h"
#include"IdGenerator.h"
#include<iostream>
#include "help.h"
#include"UserInputs.h"
using namespace std;

IdGenerator Registeration::idGenerator = IdGenerator();

Registeration::Registeration(const Student & student, const Course & course)
{
	this->course = &course;
	this->student = &student;
	grade =W;
	gpa = 0;
	obtainedMarks = 0;
	Attendance = 0; // 0 days by defult
	id = idGenerator.getNextId();
}

Registeration::Registeration(const Course * course, const Student * student, int grade, float obtained,float gpa, int attendance)
	:Registeration(*student,*course)
{
	setGrade(grade);
	setObtainedMarks(obtained);
	this->Attendance = attendance;
	setGPA(gpa);
}

Course * Registeration::getCourse() const
{
	return (Course*)course;
}

Student * Registeration::getStudent() const
{
	return (Student*)student;
}



bool Registeration::operator==(const Registeration & obj)
{
	if (course == obj.getCourse()
		&& student == obj.getStudent())
		return true;
	return false;
}

void Registeration::setGrade(Grade grade)
{
	if (grade >= A && grade <= W)
	{
		this->grade = grade;
	}
	else
	{
		throw invalid_argument("Invalid grade");
	}
}

void Registeration::setGrade(int grade)
{
	if (grade == 1)
		this->grade = A;
	else if (grade == 2)
		this->grade = B;
	else if (grade == 3)
		this->grade = C;
	else if (grade == 4)
		this->grade = D;
	else if (grade == 5)
		this->grade = F;
	else
		this->grade = W;
}

int Registeration::getId() const
{
	return this->id;
}

Grade Registeration::getGrade() const
{
	return grade;
}

void Registeration::viewGrade()const
{
	cout << student->getUserID() << " " << student->getName() << " " << help::gradeToString(getGrade())<<endl;
}

void Registeration::viewAttendance() const
{
	cout << id <<" " <<student->getUserID() << " " << student->getName() <<endl 
		<<"Present Days: "<< getAttendance()<<" DAYS" << endl;
}

void Registeration::setGPA(float gpa)
{
	if (gpa > 0.0 && gpa < 4.0)
		this->gpa = gpa;
	else
		this->gpa = 0.0;
}

float Registeration::getGPA() const
{
	return gpa;
}

void Registeration::setObtainedMarks(float obtainedmarks)
{
	if (obtainedMarks <= 100)
		obtainedMarks = obtainedmarks;
	else
		obtainedMarks = 0;
}

float Registeration::getObtainedMarks() const
{
	return obtainedMarks;
}

int Registeration::attendanceIncrement()
{
	return ++Attendance;
}

int Registeration::getAttendance() const
{
	return Attendance;
}


