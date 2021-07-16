#pragma once
#include"Employee.h"
#include"Enums.h"
class Course;
class Department;
class Registeration;
class Student;
class Teacher:public Employee
{
private:
	Course const** courses;
	const Department*department;
	int courseCapacity;
	int currentCourseCount;
public:
	Teacher(int userID, int password, char*name, const Department* department, int courseCount=10);
	Teacher(int userID, int password, char*name, const Department* department,Course const** courses, int courseCount);
	virtual ~Teacher();
	Department*getDepartment()const;
	
	int getUserID() const;
	char* getName() const;
	int getCourseCapacity() const;
	Course* getCourseById(int id) const;
	int getCurrentCourseCount() const;
	Teacher* addCourse(const Course& course, bool& added);
	bool addCourse(const Course*course);
	bool operator==( const Teacher& obj);
	void ManageAttendanceCourse(int courseId, int RegisterationNo);// incremenet 1day 
	void viewAttendanceCourse(const Course& course);
	void ManageEvaluationStudent(Registeration*registeration, float gpa, float obtained);
	void AssignGradesToStudents(Registeration*registeration, Grade grade);
	void viewEvaluationCourse(const Course& course)const;
	void printTeacher()const;
	void printCourses()const;

};

