#include "FunctionsStudent.h"
#include"Student.h"
#include"Department.h"
#include"Course.h"
#include"UserInputs.h"

void FunctionsStudent::registerCourse(Student* student)
{
	system("cls");
	cout << "\t\tProfile Name: " << student->getName() << endl;
	cout << "\t\tProfile UserID: " << student->getUserID() << endl;
	cout << "\n*********Command For Register a Course" << endl;
	if (student->getCurrentRegisterations() == 5)
	{
		UserInputs::setConsoleColor(RED);
		system("cls");
		cout << "RECENT CHANGES:";
		cout << "\n\nThis " << student->getName() << " can not register further courses" << endl;
		UserInputs::setConsoleColor(WHITE);
		cout << " Exiting back Applications" << endl;
		return;
	}
	Department*department=student->getDepartment();
	department->printCourses();
	if (department->getCurrentCourses() == 0)
	{
		return;
	}
	Course* course = UserInputs::getCourseFromUser(department);
	while (!(student->getCourseById(course->getId()) == nullptr))
	{
		UserInputs::setConsoleColor(YELLOW);
		cout << " \nThis " << course->getName() << " has Already Registered" << endl;
		 course = UserInputs::getCourseFromUser(department);
	}
	UserInputs::setConsoleColor(WHITE);
	student->registerCourse(*course);
	system("cls");
	cout << endl << "RECENT CHANGES:" << endl;
	UserInputs::setConsoleColor(GREEN);
	cout << "\nThis " << course->getName() << " has been Registered To "
		<< student->getName();
	student->printCourses();
}

void FunctionsStudent::unregisterCourse(Student* student)
{
	system("cls");
	cout << "\t\tProfile Name: " << student->getName()<<endl;
	cout << "\t\tProfile UserID: " << student->getUserID() << endl;
	cout << "\n*********Command For Unregister a Course" << endl;
	student->printCourses();
	if (student->getCurrentCourseCount() == 0)
	{
		return;
	}
	Course* course = UserInputs::getStudentCourseFromUser(student);
	student->unregisterCourse(*course);
	system("cls");
	cout << endl << "RECENT CHANGES:" << endl;
	UserInputs::setConsoleColor(GREEN);
	cout << "\nThis " << course->getName() << " has been Unregistered To "
		<< student->getName();
	student->printCourses();
}

void FunctionsStudent::withDrawCourse(Student* student)
{
	system("cls");
	cout << "\t\tProfile Name: " << student->getName() << endl;
	cout << "\t\tProfile UserID: " << student->getUserID() << endl;
	cout << "\n*********Command For WithDraw a Course" << endl;
	student->printCoursesWithGrades();
	if (student->getCurrentCourseCount() == 0)
	{
		return;
	}
	Course* course = UserInputs::getStudentCourseFromUser(student);
	student->withDrawCourse(*course);
	system("cls");
	cout << endl << "RECENT CHANGES:" << endl;
	UserInputs::setConsoleColor(GREEN);
	cout << "\nThis " << course->getName() << " has been Withdrawn " << endl;
	student->printCoursesWithGrades();
}

void FunctionsStudent::changePassword(Student* student)
{
	int oldPassword = 0;
	system("cls");
	cout << "\t\tProfile Name: " << student->getName() << endl;
	cout << "\t\tProfile UserID: " << student->getUserID() << endl;
	cout << "\n*********Command For Change Password" << endl<<endl;
	cout << "Enter Previous Password For Security: ";
	cin >> oldPassword;
	if (student->getPassword()!= oldPassword)
	{
		system("cls");
		cout << endl << "RECENT CHANGES:" << endl;
		UserInputs::setConsoleColor(RED);
		cout << "Entered Invalid Password"<<endl;
		cout << "Please Try Again" << endl;
		return;
	}
	UserInputs::setConsoleColor(WHITE);
	int pass=UserInputs::getPasswordFromUser(true); //true showing new password
	student->changePassword(pass);
	system("cls");
	cout << endl << "RECENT CHANGES:" << endl;
	UserInputs::setConsoleColor(GREEN);
	cout << "\nPassword has been Changed.."<<endl;
	return;
}

void FunctionsStudent::ViewMarkSheetCourse(Student * student)
{
	system("cls");
	cout << "\t\tProfile Name: " << student->getName() << endl;
	cout << "\t\tProfile UserID: " << student->getUserID() << endl;
	cout << "\n*********Command For Viewing an Mark Sheet of Course" << endl;
	student->printCourses();
	if (student->getCurrentCourseCount() == 0)
	{
		system("cls");
		cout << endl << "RECENT CHANGES:" << endl;
		UserInputs::setConsoleColor(GREEN);
		cout << "No Assigned Courses To this Student." << endl
			<< "Please Assign Some Courses to this Student" << endl;
		return;
	}
	Course* course = UserInputs::getStudentCourseFromUser(student);
	system("cls");
	cout << endl << "RECENT VIEW:" << endl;
	student->ViewMarkSheetCourse(*course);
}

void FunctionsStudent::viewAttendanceCourse(Student * student)
{
	system("cls");
	cout << "\t\tProfile Name: " << student->getName() << endl;
	cout << "\t\tProfile UserID: " << student->getUserID() << endl;
	cout << "\n*********Command For Viewing Attandence of a Course" << endl;
	student->printCourses();
	if (student->getCurrentCourseCount() == 0)
	{
		system("cls");
		cout << endl << "RECENT CHANGES:" << endl;
		UserInputs::setConsoleColor(GREEN);
		cout << "No Assigned Courses To this Student." << endl
			<< "Please Assign Some Courses to this Student" << endl;
		return;
	}
	Course* course = UserInputs::getStudentCourseFromUser(student);
	system("cls");
	cout << endl << "RECENT VIEW:" << endl;
	student->viewAttendanceCourse(*course);
}
