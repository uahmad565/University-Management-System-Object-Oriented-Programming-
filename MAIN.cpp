#include <iostream>
#include"University.h"
#include"Teacher.h"
#include"Student.h"
#include"Course.h"
#include"Department.h"
#include"ITManager.h"
#include"TA.h"
#include"HOD.h"
#include<fstream>
#include "UniversitySystem.h"
#include"Registeration.h"
#include "Menus.h"
#include "Enums.h"
#include "UserInputs.h"
#include "FunctionsHOD.h"
#include "FunctionsTeacher.h"
#include"FunctionsITManager.h"
#include"FunctionsStudent.h"
using namespace std;

void LoadAssignedCoursesToTeachers()
{
	ifstream fin("AssignedCoursesTeachers.txt");
	int noOfDepartments = 0;
	fin >> noOfDepartments;
	int j_1 = 0;
	while (j_1 < noOfDepartments)
	{
		int departID = 0;
		fin >> departID;
		Department*department = UniversitySystem::university->getDepartmentById(departID);
		fin.ignore();
		int noOFTeachers = 0;
		fin >> noOFTeachers;
		int j_2 = 0;
		while (j_2 < noOFTeachers)
		{
			int teacherID = 0;
			fin >> teacherID;
			fin.ignore();
			int noOfCourses = 0;
			fin >> noOfCourses;
			int j_3 = 0;
			while (j_3 < noOfCourses)
			{
				int courseID = 0;
				fin >> courseID;
				Teacher*teacher=department->getTeacherById(teacherID);
				Course*course = department->getCourseById(courseID);
				teacher->addCourse(course);
				j_3++;
			}
			j_2++;
		}

		j_1++;
	}
}

void LoadRegisterationsFromFile()
{
	ifstream fin("Registerations.txt");//s
	int noOfDepartments = 0;
	fin >> noOfDepartments;
	int j_noOfDeparts = 0;
	while (j_noOfDeparts < noOfDepartments)
	{
		int departmentID = 0;
		fin >> departmentID;
		Department*department = UniversitySystem::university->getDepartmentById(departmentID);
		int noOfStudents=0;
		fin.ignore();
		fin >> noOfStudents;
		int count = 0;
		while (count < noOfStudents)
		{
			int studentuserID = 0;
			fin >> studentuserID;
			Student*student = department->getStudentByID(studentuserID);
			fin.ignore();
			int noOfRegisterations = 0;
			fin >> noOfRegisterations;
			int j = 0;
			while (j < noOfRegisterations)
			{
				int courseID = 0;
				fin >> courseID;
				Course*course = department->getCourseById(courseID);
				fin.ignore();
				int grade;
				fin >> grade;
				fin.ignore();
				float gpa = 0;
				fin >> gpa;
				fin.ignore();
				float obtained = 0;
				fin >> obtained;
				fin.ignore();
				int attandence = 0;
				fin >> attandence;
				Registeration*registeration = new Registeration(course, student, grade, obtained, gpa, attandence);
				course->addRegistration(registeration);
				student->addRegisteration(registeration);
				j++;
			}
			count++;
		}
		j_noOfDeparts++;
	}
}
void writeUniversityData()
{
	University*university=UniversitySystem::university;
	ofstream fout("Write.txt");
	fout << university->getName()<<endl;
	int noOfDepartments = university->getNoOfDepartments();
	fout << noOfDepartments;
	int j = 0;
	while (j< noOfDepartments)
	{
		Department**departments=university->getDepartments();
		if (departments != nullptr)
		{
			fout <<endl <<departments[j]->getName() << endl;
			int noOfCourses = departments[j]->getCurrentCourses();
			fout << noOfCourses << endl;
			Course**courses = departments[j]->getCourses();
			int j_courses = 0;
			while (j_courses < noOfCourses)
			{
				fout << courses[j_courses]->getCode() << "," << courses[j_courses]->getName()<<endl;
				j_courses++;
			}
			int noOfTeachers=departments[j]->getCurrentTeachers();
			fout << noOfTeachers + 1 << endl;
			bool checkHOD = true;
			int j_teachers = 0;
			while (j_teachers < noOfTeachers )
			{
				if (checkHOD == true)
				{
					HOD*hod = departments[j]->getHeadOfDepartment();
					fout << hod->getUserID() << "," << hod->getName() << "," << hod->getPassword()<<endl;
					checkHOD = false;
					continue;
				}
					Teacher**teachers=departments[j]->getTeachers();
					fout << teachers[j_teachers]->getUserID() << "," << teachers[j_teachers]->getName()
						<< "," << teachers[j_teachers]->getPassword()<<endl;
				j_teachers++;
			}
			fout << 1<<endl;
			ITManager*IT=departments[j]->getIT_Manager();
			fout << IT->getUserID() << "," << IT->getName() << "," << IT->getPassword() << endl;
			Student**students = departments[j]->getStudents();
			if (students != nullptr)
			{
				int noOfStudents = departments[j]->getCurrentStudents();
				fout << noOfStudents;
				int j_students = 0;
				while (j_students < noOfStudents)
				{
					fout <<endl <<students[j_students]->getUserID() << "," << students[j_students]->getName()
						<< "," << students[j_students]->getPassword();
					j_students++;
				}
			}
			
		}
		j++;
	}
	fout.close();
}
void writeRegisterationsFile()
{
	ofstream fout("Registerations.txt");
	int noOfDeparts=UniversitySystem::university->getNoOfDepartments();
	fout << noOfDeparts;
	
	int j_count = 0;
	Department**departments = UniversitySystem::university->getDepartments();
	while (j_count < noOfDeparts)
	{
		fout << endl;
		Department*department = departments[j_count];
		fout << department->getId() << ",";
		int noOfStudents = department->getCurrentStudents();
		Student**students = department->getStudents();
		fout << noOfStudents;
		int j = 0;
		while (j < noOfStudents)
		{
			int noOfRegists = students[j]->getCurrentRegisterations();
			fout << endl << students[j]->getUserID() << "," << noOfRegists;
			Registeration**registerations = students[j]->getRegisterations();
			int j_registerations = 0;
			while (j_registerations < noOfRegists)
			{
				fout << endl << registerations[j_registerations]->getCourse()->getId()
					<< "," << registerations[j_registerations]->getGrade() << ","
					<< registerations[j_registerations]->getGPA() << ","
					<< registerations[j_registerations]->getObtainedMarks() << ","
					<< registerations[j_registerations]->getAttendance();
				j_registerations++;
			}
			j++;
		}
		j_count++;
	}
	

}

void loadInitialData()
{
	ifstream fin("Write.txt");
	char UniversityName[1000];
	char departmentName[1000];
	int NoOfDepartments;
	int noOfCourses = 0;
	char courseCode[1000];
	char courseName[1000];
	int TAuserID=0;
	int TAuserPass;
	char TAname[1000];
	int NoOfTeachers = 0;
	int teacherUserID=0;
	int teacherUserPass = 0;
	char teacherName[1000];
	int TApass=0;
	int noOfITManager = 0;
	int ITManageruserID=0;
	char ITManagerName[1000];
	int ITManagerPass=0;
	int noOfStudents = 0;
	int studentUserID=0;
	char studentName[1000];
	int studentPass=0;
	//StartFILING....
	fin.getline(UniversityName, 1000);
	fin >> NoOfDepartments;
	University*university = new University(UniversityName, NoOfDepartments);
	int currentDepartments = 0;
	while (currentDepartments < NoOfDepartments)
	{
		fin.ignore();
		fin.getline(departmentName, 1000, '\n');
		fin >> noOfCourses;
		fin.ignore();
		Department* currentDepartment = new Department(departmentName, noOfCourses);
		int count = 0;
		while (count < noOfCourses)
		{
			fin.getline(courseCode, 1000, ',');
			fin.getline(courseName, 1000);
			Course* currentCourse = new Course(courseCode, courseName);
			currentDepartment->addCourse(*currentCourse);
			count++;
		}
		fin >> NoOfTeachers;
		int currentTeacherCount = 0;
		bool checkHOD = true;
		while (currentTeacherCount < NoOfTeachers)
		{
			fin >> teacherUserID;
			fin.ignore();
			fin.getline(teacherName, 1000, ',');
			fin >> teacherUserPass;
			if (checkHOD)
			{
				HOD* currentHOD = new HOD(teacherUserID, teacherUserPass, teacherName, currentDepartment);
				currentDepartment->setHeadOfDepartment(*currentHOD);
				checkHOD = false;
			}
			else
			{
				Teacher* currentTeacher = new Teacher(teacherUserID, teacherUserPass, teacherName, currentDepartment);
				
				currentDepartment->addTeacher(*currentTeacher);
			}
			currentTeacherCount++;
		}
		fin >> noOfITManager;
		int currentITManagerCount = 0;
		while (currentITManagerCount < noOfITManager)
		{
			fin >> ITManageruserID;
			fin.ignore();
			fin.getline(ITManagerName, 1000, ',');
			fin >> ITManagerPass;
			ITManager* currentITManager = new ITManager(ITManageruserID, ITManagerPass, ITManagerName, currentDepartment);
			currentDepartment->setIT_Manager(*currentITManager);
			currentITManagerCount++;
		}
		fin >> noOfStudents;
		int currentStudentsCount = 0;
		while (currentStudentsCount < noOfStudents)
		{
			fin >> studentUserID;
			fin.ignore();
			fin.getline(studentName, 1000, ',');
			fin >> studentPass;
			Student* currentStudent = new Student(studentUserID, studentPass, studentName, currentDepartment);
			currentDepartment->addStudent(*currentStudent);
			currentStudentsCount++;
		}
		university->addDepartment(*currentDepartment);
		currentDepartments++;
	}
	fin.close();

	UniversitySystem::university = university;
}

int checkGameEnd(int choice)
{
	return choice;
}

void deleteMemoryObjects()
{
	delete UniversitySystem::university;
}

Person* getPersonFromUserIdAndPassword(int departmentId, Role role)
{
	UserInputs::setConsoleColor(WHITE);
	Menus::PrintRoleLoginName(role);
	cout << endl;
	int userId = UserInputs::getUserIDFromUser(false);
	int password = UserInputs::getPasswordFromUser(false);
	Person* person = UniversitySystem::isUserIdAndPasswordValid(userId, password, departmentId, role);
	while (person == nullptr)
	{
		UserInputs::setConsoleColor(RED);
		cout << " You have entered bad user ID or password." << endl
			<< "Please enter again: " << endl;
		userId = UserInputs::getUserIDFromUser(false);
		password = UserInputs::getPasswordFromUser(false);
		person = UniversitySystem::isUserIdAndPasswordValid(userId, password, departmentId, role);
	}

	return person;
}

void clearScreen()
{
	system("cls");
}

void performTasksHOD(HOD* hod)
{
	UserInputs::setConsoleColor(WHITE);
	clearScreen();
	cout << "\t\tProfile UserID: " << UniversitySystem::loggerIdPerson->getUserID() << endl;
	int choice = -1;
	while (choice != 0)
	{
		cout << endl << endl;	
		Menus::PrintMenuHOD();
		choice = Menus::GetInput(0, 4);
		clearScreen();
		switch (choice)
		{
		case 1:
			
			FunctionsHOD::AssignCourseToTeacher(hod);
			break;
		case 2:
			FunctionsHOD::RegisterCourseForStudent(hod);
			break;
		case 3:
			FunctionsHOD::UnregisterCourseForStudent(hod);
			break;
		case 4:
			FunctionsHOD::ViewGradesOfCourse(hod);
			break;
		default:
			return;
		}
	}
}

void performTasksTeachers(Teacher* teacher)
{
	UserInputs::setConsoleColor(WHITE);
	clearScreen();
	cout << "\t\tProfile UserID: " << UniversitySystem::loggerIdPerson->getUserID() << endl;
	int choice = -1;
	while (choice != 0)
	{
		cout << endl << endl;
		Menus::PrintMenuTeacher();
		choice = Menus::GetInput(0, 5);
		clearScreen();
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
			break;
		}
	}
}

void performTasksITManager(ITManager* ITmanager)
{
	UserInputs::setConsoleColor(WHITE);
	clearScreen();
	cout << "\t\tProfile UserID: " << UniversitySystem::loggerIdPerson->getUserID() << endl;
	int choice = -1;
	while (choice != 0)
	{
		cout << endl << endl;
		Menus::PrintMenuITManager();
		choice = Menus::GetInput(0, 5);
		clearScreen();
		switch (choice)
		{
		case 1:
			FunctionsITManager::createAccountFaculty(ITmanager);
			break;
		case 2:
			FunctionsITManager::deleteAccountFaculty(ITmanager);
			break;
		case 3:
			FunctionsITManager::createAccountStudent(ITmanager);
			break;
		case 4:
			FunctionsITManager::deleteAccountStudent(ITmanager);
			break;
		case 5:
			FunctionsITManager::MaintainAccount(ITmanager);
			break;
		default:
			break;
		}
	}
}

void performTasksStudent(Student* student)
{
	UserInputs::setConsoleColor(WHITE);
	clearScreen();
	cout << "\t\tProfile UserID: " << UniversitySystem::loggerIdPerson->getUserID() << endl;
	int choice = -1;
	while (choice != 0)
	{
		cout << endl << endl;
		Menus::PrintMenuStudent();
		choice = Menus::GetInput(0, 6);
		clearScreen();
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
			break;
		default:
			break;
		}
	}
}
int main()
{
	UserInputs::setConsoleColor(WHITE);
	
	loadInitialData();
	LoadRegisterationsFromFile();
	LoadAssignedCoursesToTeachers();
	while (true)
	{
		UserInputs::setConsoleColor(WHITE);
		clearScreen();
		Menus::PrintWelcome();
		cout << "\n";
		UniversitySystem::university->printUniversity();
		cout << endl;
		cout << "0-Enter For Save And Exit " << endl<<endl;
		Department* department = UserInputs::getDepartmentFromUser();
		if (department == nullptr)
		{
			break;
		}
		clearScreen();
		while (true)
		{
			Menus::PrintLoginMenu();
			Role role = (Role)Menus::GetInput(0, 4);
			if ((int)role == 0)
			{
				break;
			}
			clearScreen();
			if (role != 0)
			{
				UniversitySystem::loggerIdPerson = getPersonFromUserIdAndPassword(department->getDepartmentId(), role);
			}
			clearScreen();
			switch (role)
			{
			case HEAD_OF_DEPARTMENT:
				performTasksHOD(dynamic_cast<HOD*>(UniversitySystem::loggerIdPerson));
				break;
			case TEACHER:
				performTasksTeachers(dynamic_cast<Teacher*>(UniversitySystem::loggerIdPerson));
				break;
			case IT_MANAGER:
				performTasksITManager(dynamic_cast<ITManager*>(UniversitySystem::loggerIdPerson));
				break;
			case STUDENT:
				performTasksStudent(dynamic_cast<Student*>(UniversitySystem::loggerIdPerson));
				break;
			default:
				UserInputs::setConsoleColor(GREEN);
				cout << "RECENT OPTION CHOOSE:" << endl;
				cout << "Exiting Back The Application..." << endl;
				break;
			}
		}
		
	}
	writeUniversityData();
	writeRegisterationsFile();
	deleteMemoryObjects();
}
