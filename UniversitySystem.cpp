#pragma once
#include "UniversitySystem.h"
#include "University.h"
#include "Menus.h"
#include "FunctionsHOD.h"
#include"ITManager.h"
#include "HOD.h"
#include"Person.h"
#include"Teacher.h"
#include"Student.h"
#include"FunctionsITManager.h"
#include"FunctionsTeacher.h"
#include"FunctionsStudent.h"



University* UniversitySystem::university = nullptr;
Person* UniversitySystem::loggerIdPerson = nullptr;

void UniversitySystem::PerformTasksHOD()
{
	try
	{
		HOD* hod = dynamic_cast<HOD*>(loggerIdPerson);
		Menus::PrintMenuHOD();
		int choice = Menus::GetInput(0, 4);
		while (choice != 0)
		{
			switch (choice)
			{
			case 1:
				FunctionsHOD::AssignCourseToTeacher(hod);
				cout << "Course has been assigned to teacher.";
				break;
			case 2:
				FunctionsHOD::RegisterCourseForStudent(hod);
				cout << "Course has been registered for student.";
				break;
			case 3:
				FunctionsHOD::UnregisterCourseForStudent(hod);
				cout << "Course has been unregistered from student.";
				break;
			case 4:
				FunctionsHOD::ViewGradesOfCourse(hod);
				break;
			default:
				cout << "Invalid option entered.";
			}

			cout << endl << endl;
			Menus::PrintMenuHOD();
			choice = Menus::GetInput(0, 4);
		}
	}
	catch (const std::exception& ex)
	{
		cout << "Error occurred: " << ex.what() << endl;
	}
}

void UniversitySystem::PerformTasksITManager()
{
	try
	{
		ITManager* ITmanager = dynamic_cast<ITManager*>(loggerIdPerson);
		Menus::PrintMenuITManager();
		int choice = Menus::GetInput(0, 5);
		while (choice != 0)
		{
			switch (choice)
			{
			case 1:
				
				cout << "A Faculty Member Account has been Created.";
				break;
			case 2:
				FunctionsITManager::deleteAccountFaculty(ITmanager);
				cout << "A Faculty Member Account has been deleted.";
				break;
			case 3:
				FunctionsITManager::createAccountStudent(ITmanager);
				cout << "A Student Account has been Created.";
				break;
			case 4:
				FunctionsITManager::deleteAccountStudent(ITmanager);
				cout << "A Student Account has been deleted.";
				break;
			case 5:
				FunctionsITManager::MaintainAccount(ITmanager);
				cout << "An Account has been maintained.";
				break;
			default:
				cout << "Invalid option entered.";
			}

			cout << endl << endl;
			Menus::PrintMenuITManager();
			choice = Menus::GetInput(0, 5);
		}
	}
	catch (const std::exception& ex)
	{
		cout << "Error occurred: " << ex.what() << endl;
	}
}

void UniversitySystem::PerformTasksTeacher()
{
	try
	{
		Teacher* teacher= dynamic_cast<Teacher*>(loggerIdPerson);
		Menus::PrintMenuTeacher();
		int choice = Menus::GetInput(0, 5);
		while (choice != 0)
		{
			switch (choice)
			{
			case 1:
				FunctionsTeacher::ManageAttendanceCourse(teacher);
				break;
			case 2:
				FunctionsTeacher::viewAttendanceCourse(teacher);
				break;
			case 3:
				FunctionsTeacher::ManageEvaluationStudent(teacher);
				break;
			case 4:
				FunctionsTeacher::viewEvaluationCourse(teacher);
				break;
			case 5:
				FunctionsTeacher::AssignGradesToStudents(teacher);
				break;
			default:
				cout << "Invalid option entered.";
			}

			cout << endl << endl;
			Menus::PrintMenuTeacher();
			choice = Menus::GetInput(0, 5);
		}
	}
	catch (const std::exception& ex)
	{
		cout << "Error occurred: " << ex.what() << endl;
	}
}

void UniversitySystem::PerformTasksStudent()
{
	try
	{
		Student* student= dynamic_cast<Student*>(loggerIdPerson);
		Menus::PrintMenuStudent();
		int choice = Menus::GetInput(0, 6);
		while (choice != 0)
		{
			switch (choice)
			{
			case 1:
				FunctionsStudent::registerCourse(student);
				break;
			case 2:
			FunctionsStudent::unregisterCourse(student);
				break;
			case 3:
			FunctionsStudent::withDrawCourse(student);
				break;
			case 4:
			FunctionsStudent::ViewMarkSheetCourse(student);
				break;
			case 5:
			FunctionsStudent::viewAttendanceCourse(student);
				break;
			case 6:
				FunctionsStudent::changePassword(student);
			default:
				cout << "Invalid option entered.";
			}

			cout << endl << endl;
			Menus::PrintMenuStudent();
			choice = Menus::GetInput(0, 6);
		}
	}
	catch (const std::exception& ex)
	{
		cout << "Error occurred: " << ex.what() << endl;
	}

}

Person* UniversitySystem::isUserIdAndPasswordValid(int userId, int password, int departmentId, Role role)
{
	Department* department = university->getDepartmentById(departmentId);
	Person* person;
	switch (role)
	{
	case HEAD_OF_DEPARTMENT:
		person = department->getHeadOfDepartment();
		if (userId == person->getUserID() && password == person->getPassword())
		{
			return person;
		}
		else
		{
			return nullptr;
		}
		break;
	case TEACHER:
		person = department->getTeacherById(userId);
		if (person != nullptr && password == person->getPassword())
		{
			return person;
		}
		else
		{
			return nullptr;
		}
		break;
	case IT_MANAGER:
		person = department->getIT_Manager();
		if (userId == person->getUserID() && password == person->getPassword())
		{
			return person;
		}
		else
		{
			return nullptr;
		}
		break;
	case STUDENT:
		person = department->getStudentByID(userId);
		if (person != nullptr && password == person->getPassword())
		{
			return person;
		}
		else
		{
			return nullptr;
		}
		break;
	default:
		throw invalid_argument("Invalid role received.");
	}
}



