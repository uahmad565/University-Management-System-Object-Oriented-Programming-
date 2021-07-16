#pragma once
#include "Teacher.h"

class Course;
class Student;
enum Grade;

class HOD:public Teacher
{
public:
	HOD(int userID, int password, char*name, const Department* department, int courseCount = 10);
	HOD(int userID, int password, char*name, const Department* department, Course const** courses, int courseCount);
	bool assignCoursesToTeachers( Course& course, Teacher& teacher);
	bool registerCourseForStudent( Course& course, Student& student);
	bool unRegisterCourseForStudent( Course& course, Student& student);
	void viewGrades(const Course& course)const;
	bool operator==(const HOD& obj);
	void printHOD() const;
};

