#include "UserInputs.h"
#include "UniversitySystem.h"
#include "Department.h"
#include "University.h"
#include"Student.h"
#include "Enums.h"
#include "Registeration.h"
#include "Course.h"
#include"help.h"
#include"helpTemplate.h"
#include "Teacher.h"

HANDLE UserInputs::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

Department* UserInputs::getDepartmentFromUser()
{
	UserInputs::setConsoleColor(WHITE);
	int departmentID;
	cout << " Enter department ID: ";
	cin >> departmentID;
	Department* department = UniversitySystem::university->getDepartmentById(departmentID);
	while (department == nullptr)
	{
		if (departmentID == 0)
		{
			return nullptr;
		}
		UserInputs::setConsoleColor(RED);
		cout << " No department found with ID " << departmentID << ". Please enter again: ";
		cin >> departmentID;
		department = UniversitySystem::university->getDepartmentById(departmentID);
	}

	return department;
}

Course* UserInputs::getCourseFromUser(const Department* department)
{
	UserInputs::setConsoleColor(WHITE);
	int courseID;
	cout << " Enter course ID: ";
	cin >> courseID;
	Course* course = department->getCourseById(courseID);
	while (course == nullptr)
	{
		UserInputs::setConsoleColor(RED);
		cout << " No course found with ID " << courseID << ". Please enter again: ";
		cin >> courseID;
		course = department->getCourseById(courseID);
	}

	return course;
}

Course * UserInputs::getTeacherCourseFromUser(const Teacher * teacher)
{
	UserInputs::setConsoleColor(WHITE);
	int courseID;
	cout << " Enter course ID: ";
	cin >> courseID;
	Course* course = teacher->getCourseById(courseID);
	while (course == nullptr)
	{
		UserInputs::setConsoleColor(RED);
		cout << " No course found with ID " << courseID << ". Please enter again: ";
		cin >> courseID;
		course = teacher->getCourseById(courseID);
	}

	return course;
}

Course * UserInputs::getStudentCourseFromUser(const Student * student)
{
	UserInputs::setConsoleColor(WHITE);
	int courseID;
	cout << " Enter course ID: ";
	cin >> courseID;
	Course* course = student->getCourseById(courseID);
	while (course == nullptr)
	{
		UserInputs::setConsoleColor(RED);
		cout << " No course found with ID " << courseID << ". Please enter again: ";
		cin >> courseID;
		course = student->getCourseById(courseID);
	}
	return course;
}

Teacher * UserInputs::getTeaherFromUser(const Department * department)
{
	UserInputs::setConsoleColor(WHITE);
	/*department->printTeachers();*/
	int teacherId;
	cout << " Enter teacher ID: ";
	cin >> teacherId;
	Teacher* teacher = department->getTeacherById(teacherId);
	while (teacher == nullptr)
	{
		UserInputs::setConsoleColor(RED);
		cout << " No teacher found with ID " << teacherId << ". Please enter again: ";
		cin >> teacherId;
		teacher = department->getTeacherById(teacherId);
	}

	return teacher;
}

Student * UserInputs::getStudentFromUser(const Department * department)
{
	UserInputs::setConsoleColor(WHITE);
	int studentId;
	cout << " Enter student ID: ";
	cin >> studentId;
	Student* student = department->getStudentByID(studentId);
	while (student == nullptr)
	{
		UserInputs::setConsoleColor(RED);
		cout << " No Student found with ID " << studentId << ". Please enter again: ";
		cin >> studentId;
		student = department->getStudentByID(studentId);
	}
	return student;
}

Registeration * UserInputs::getRegistrationFromUser(const Course * course)
{
	UserInputs::setConsoleColor(WHITE);
	cout << " Enter registration ID: ";
	int registrationId;
	cin >> registrationId;

	Registeration* registration = course->getRegistrationById(registrationId);
	while (registration == nullptr)
	{
		UserInputs::setConsoleColor(RED);
		cout << " No registration found with ID " << registrationId << ". Please enter again: ";
		cin >> registrationId;
		registration = course->getRegistrationById(registrationId);
	}
	
	return registration;
}




int UserInputs::getPasswordFromUser(bool isNew)
{
	UserInputs::setConsoleColor(WHITE);
	int password;
	cout << "Enter" << (isNew ? " new" : "") << " Password: ";
	cin >> password;
	return password;
}

int UserInputs::getUserIDFromUser(bool isNew)
{
	UserInputs::setConsoleColor(WHITE);
	int id;
	cout << "Enter" << (isNew ? " new" : "") << " ID: ";
	cin >> id;
	return id;
}

Grade UserInputs::getGradeFromUser()
{
	UserInputs::setConsoleColor(WHITE);
	char grade_;
	cout <<endl<< "Enter Grades: "
		<< "\n  'A'"
		<< "\n  'B'"
		<< "\n  'C'"
		<< "\n  'D'"
		<< "\n  'F'"<<endl;
	do {
		UserInputs::setConsoleColor(RED);
		cin >> grade_;
		if((grade_ < 65 || grade_>68) && (grade_ != 70))
			cout << "invalid Character."<<endl;
	}
	while ((grade_ < 65 || grade_>68) && (grade_ != 70));
	
	int choice = grade_-64;

	Grade grade;
	switch (choice)
	{
	case 1:
		grade = A;
		break;
	case 2:
		grade = B;
		break;
	case 3:
		grade = C;
		break;
	case 4:
		grade = D;
		break;
	case 5:
		grade = F;
		break;
	default:
		throw invalid_argument("Invalid grade entered");
	}

	return grade;
}

void UserInputs::getEvaluationMarksFromUser(float* Marks)
{
	float obtainedMarks = 0;
	float Cgpa=0;
	do
	{
		UserInputs::setConsoleColor(WHITE);
			cout << "Enter Student's Cgpa out of 4.0: ";
			cin >> Cgpa;
		if (Cgpa > 4 || Cgpa < 0)
		{
			UserInputs::setConsoleColor(RED);
			cout << "Enter Valid Cgpa";
			cout << endl;
		}
		
	} while (Cgpa > 4 || Cgpa < 0);
	do
	{
		UserInputs::setConsoleColor(WHITE);
			cout << "Please Enter Student's Obtained Marks out of 100: ";
			cin >> obtainedMarks;

		if (obtainedMarks > 100 || obtainedMarks< 0)
		{
			UserInputs::setConsoleColor(RED);
			cout << "Please Enter Valid Obtained Marks";
			cout << endl;
		}
	} while (obtainedMarks > 100 || obtainedMarks < 0);
	Marks[0] = Cgpa;
	Marks[1] = obtainedMarks;
}

void UserInputs::setConsoleColor(Colors color)
{
	SetConsoleTextAttribute(consoleHandle, color);
}
