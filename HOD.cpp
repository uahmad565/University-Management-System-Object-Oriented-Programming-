#include "HOD.h"
#include"Department.h"
#include"Teacher.h"
#include"Student.h"
#include<iostream>
#include"Registeration.h"
#include"helpTemplate.h"
#include"Department.h"
#include "Enums.h"
#include "Course.h"
#include<stdexcept>
using namespace std;


HOD::HOD(int userID, int password, char*name, const Department* department, int courseCount)
	:Teacher(userID,password,name,department,courseCount),Person(userID,password)
{
}




HOD::HOD(int userID, int password, char*name, const Department* department, Course const** courses, int courseCount)
	:Teacher(userID,password,name,department,courses,courseCount),Person(userID,password)
{
}

bool HOD::assignCoursesToTeachers(Course& course, Teacher & teacher)
{
	bool added;
	course.addTeacher(teacher);
	teacher.addCourse(course, added);
	
	return added;
}

bool HOD::registerCourseForStudent( Course & course,  Student & student)
{
	bool added = student.registerCourse(course);
	return added;
}

bool HOD::unRegisterCourseForStudent( Course & course, Student & student)
{
	return	student.unregisterCourse(course);
}

void HOD::viewGrades(const Course & course) const
{
	course.viewGrades();
}

bool HOD::operator==(const HOD & obj)
{
	return false;
}

void HOD::printHOD() const
{
	cout << "Head Of Department#" << endl;
	cout <<"-"<< getUserID() << "-" << getName()<<endl;
	cout<<"-"<<getDepartment()->getName();
}


