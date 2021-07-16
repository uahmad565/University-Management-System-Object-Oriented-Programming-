#pragma once
#include "Enums.h"

class Course;
class Student;
class IdGenerator;
class Registeration
{
private:

	const Course*course;
	const Student*student;
	Grade grade;
	float gpa;
	float obtainedMarks; //assuming total marks 100
	int Attendance;
	static IdGenerator idGenerator;
	int id;
	
public:
	Registeration(const Student& student, const Course& course);
	Registeration(const Course * course, const Student * student, int grade, float obtained, float gpa, int attendance);
	Course*getCourse()const;
	Student*getStudent()const;
	bool operator==( const Registeration& obj);
	void setGrade(Grade grade);
	void setGrade(int grade);
	int getId() const;
	Grade getGrade() const;
	void viewGrade() const;
	void viewAttendance()const;
	void setGPA(float gpa);
	float getGPA()const;
	void setObtainedMarks(float obtainedmarks);
	float getObtainedMarks()const;
	int attendanceIncrement();
	int getAttendance()const;

};

