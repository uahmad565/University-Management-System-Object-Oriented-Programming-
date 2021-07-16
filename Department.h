#pragma once
#include <string>
using namespace std;

class Course;
class Teacher;
class Student;
class ITManager;
class HOD;
class IdGenerator;
class Department
{
private:
	static IdGenerator idGenerator;
	char* name;
	const Course ** courses; //aggregation
	const Student** students;//aggregation
	const Teacher** teachers; //aggregation
	HOD const * hod;
	const ITManager*IT_Manager;
	int teacherCapacity;
	int currentTeachersCount;
	int courseCapacity;
	int currentCourseCount;
	int studentCapacity;
	int currentStudentsCount;
	int departmentId;
public:
	Department(char* name, int courseMax);
	~Department();
	Department& setName(char* name);//setters
	Department& setHeadOfDepartment(const HOD& hod);
	Department& setIT_Manager(const ITManager& it_manager);//
	char* getName() const;//getters
	int getId()const;
	int getCourseCapacity() const;
	HOD* getHeadOfDepartment() const;
	ITManager*getIT_Manager()const;//
	Department& addCourse(const Course& course);  //adding
	Department& addStudent(const Student& student);
	Department& addTeacher(const Teacher& teacher);//
	Department& eliminateStudent(const Student& student);//removing
	Department& eliminateTeacher(const Teacher& teacher);
	Department& eliminateCourse(const Course& course);//
	Teacher**getTeachers()const;//Getting2d-Pointer's
	Course**getCourses()const;
	Student**getStudents()const;//
	int getCurrentCourses() const;//get current Numbers
	int getCurrentTeachers()const;
	int getCurrentStudents()const;//
	bool operator==(const Department& obj)const;
	Course* getCourseByCode(char* courseCode);
	Course* getCourseById(int id) const;
	Teacher* getTeacherById(int teacherID) const;
	int getDepartmentId() const;
	void setDepartmentId(int id);
	Student*getStudentByID(int id)const;
	void printDepartment()const;
	void printCourses()const;
	void printStudents()const;
	void printTeachers()const;
};
