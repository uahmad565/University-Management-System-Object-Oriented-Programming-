#pragma once
#include "Department.h"
#include"Person.h"
using namespace std;

class Course;
class Registeration;

class Student: virtual public  Person
{
private:
	char*name;
	const Department* department;
	const Registeration** registerations;
	int registerationCapacity;
	int currentRegisterations;
public:
	Student(int userID, int password, char* name,const Department* department);
	virtual ~Student();
	int getuserID() const;
	bool setPassword(int password);
	int getPassword()const;
	char* getName() const;
	Student setDepartment(const Department& department);
	Department* getDepartment() const;
	int getCourseCapacity() const;
	Registeration* getRegisterationByCourseID(int id) const;
	int getCurrentCourseCount() const;
	int getCurrentRegisterations()const;
	Course* getCourseById(int id) const;
	Registeration** getRegisterations()const;
	bool addRegisterations(const Registeration& registeration);
	Registeration* getRegistrationById(int registrationId);
	bool removeRegisterations( Registeration* registeration);
	void addRegisteration(const Registeration*registeration);
	bool operator==(const Student& obj);
	bool registerCourse(Course&course);
	bool unregisterCourse( Course& course);// remove registeration from student's list
	bool withDrawCourse(Course& course);//withdrawing course by putting grade = W
	void changePassword(int password);
	void ViewMarkSheetCourse(const Course& course)const;
	void viewAttendanceCourse(const Course& course)const;
	void printStudent()const;
	void printCourses()const;
	void printCoursesWithGrades()const;
};
