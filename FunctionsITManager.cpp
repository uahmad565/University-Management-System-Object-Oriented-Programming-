#include"FunctionsITManager.h"
#include"ITManager.h"
#include"UserInputs.h"
#include"Department.h"
#include"Teacher.h"
#include"Student.h"
#include"Menus.h"
#include"UniversitySystem.h"

void FunctionsITManager::createAccountStudent(ITManager * IT)
{
	system("cls");
	cout << "\t\tLogged In Name: " << IT->getName() << endl;
	cout << "\t\tLogged In UserID: " << IT->getUserID() << endl;
	cout << "\n*********Command For Creating an Student Account" << endl;
	bool type = true;  //student
	Student*student = UserInputs::createAccountInformation<Student>(type, IT->getDepartment()); // false type is a faculty account
	IT->createAccountStudent(*student);
	cout << endl;
	system("cls");
	cout << endl;
	UserInputs::setConsoleColor(GREEN);
	cout << "New Student Has Been Added Named: " << student->getName();
	IT->getDepartment()->printStudents();
}

void FunctionsITManager::deleteAccountStudent(ITManager * IT)
{
	system("cls");
	cout << "\t\tLogged In Name: " << IT->getName() << endl;
	cout << "\t\tLogged In UserID: " << IT->getUserID() << endl;
	cout << "\n*********Command For Deleting an Student Account" << endl;
	Department*department=IT->getDepartment();
	department->printStudents();
	if (department->getCurrentStudents() == 0)
	{
		system("cls");
		UserInputs::setConsoleColor(YELLOW);
		cout << "RECENT INFORMATION:" << endl;
		cout << "No Students Were Available" << endl;
		return;
	}
	Student*student= UserInputs::getStudentFromUser(department);
	cout << endl;
	system("cls");
	cout << endl;
	UserInputs::setConsoleColor(GREEN);
	cout << "A Student Has Been Deleted Named: " << student->getName();
	IT->deleteAccountStudent(*student);
	department->printStudents();	
}

void FunctionsITManager::MaintainAccount(ITManager * IT)
{
	system("cls");
	cout << "\t\tLogged In Name: " << IT->getName() << endl;
	cout << "\t\tLogged In UserID: " << IT->getUserID() << endl;
	cout << "\n*********Command For Maintainance an Student Account" << endl;
	Menus::PrintSelectAccountTypeITManager();
	Person*person = nullptr;
	int typeAccount = -1;
	while (typeAccount <0 || typeAccount>2)
	{
		typeAccount=Menus::GetInput(0, 2);
		system("cls");
		cout << "\t\tLogged In Name: " << IT->getName() << endl;
		cout << "\t\tLogged In UserID: " << IT->getUserID() << endl;
		cout << "\n*********Command For Maintainance an Student Account" << endl;
		switch (typeAccount)
		{
		case 1:
			IT->getDepartment()->printStudents();
			cout << endl;
			person=UserInputs::getStudentFromUser(IT->getDepartment());
			break;
		case 2:
			IT->getDepartment()->printTeachers();
			cout << endl;
			person= UserInputs::getTeaherFromUser(IT->getDepartment());
			break;
		default:
			UserInputs::setConsoleColor(RED);
			cout << "Exiting the back application...\n";
			system("cls");
			break;
		}
		if (typeAccount == 0)
		{
			return;
		}
	}
	
	int password = 0;
	int userID = 0;
	int previousPassword = 0;
	int choice = -1;
	while (choice<0||choice>3)
	{
		UserInputs::setConsoleColor(WHITE);
		Menus::PrintCreateAccountTypeITManager();
		choice = Menus::GetInput(0,3);
		if (choice != 0)
		{
			cout << "\n\nEnter Previous Password For Security: ";
			cin >> previousPassword;

		}
		switch (choice)
		{
		case 1:
			if (previousPassword == person->getPassword())
			{
				cout << "Entered Match Password :) " << endl;
				password = UserInputs::getPasswordFromUser();
				userID = UserInputs::getUserIDFromUser();
				IT->setAccountPass(person, password);
				IT->setAccountUserID(person, userID);
				cout << "Given Task has been completed(userId,Passowrd)." << endl;
			}
			else {
				UserInputs::setConsoleColor(RED);
				cout << "Entered Wrong Password!" << endl
					<< "Please Try Again"<<endl;
			}
			break;
		case 2:
			if (previousPassword == person->getPassword())
			{
				cout << "Entered Match Password :) " << endl;
				userID = UserInputs::getUserIDFromUser();
				IT->setAccountUserID(person, userID);
				cout << "Given Task has been completed(UserID)." << endl;
			}
			else {
				UserInputs::setConsoleColor(RED);
				cout << "Entered Wrong Password!" << endl
					<< "Please Try Again" << endl;
			}
				break;
		case 3:
			 if (previousPassword == person->getPassword())
			 {
				 password = UserInputs::getPasswordFromUser();
				 IT->setAccountPass(person, password);
				 cout << "Given Task has been completed(Password)." << endl;
			 }
			else
			 {
				 UserInputs::setConsoleColor(RED);
				cout << "Entered Wrong Password!" << endl
				<< "Please Try Again" << endl;
			 }
			 break;
		default:
			cout << "Exiting back application" << endl;
			person = nullptr;
			break;
		}
	}
	
}


void FunctionsITManager::deleteAccountFaculty(ITManager * IT)
{
	system("cls");
	cout << "\t\tLogged In Name: " << IT->getName() << endl;
	cout << "\t\tLogged In UserID: " << IT->getUserID() << endl;
	cout << "\n*********Command For Deleting an Faculty Account" << endl;
	Department*department = IT->getDepartment();
	department->printTeachers();
	if (department->getCurrentTeachers() == 0)
	{
		system("cls");
		UserInputs::setConsoleColor(YELLOW);
		cout << "RECENT INFORMATION:" << endl;
		cout << "No Faculty Members Were Available" << endl;
		return;
	}
	Teacher*teacher= UserInputs::getTeaherFromUser(department);
	cout << endl;
	system("cls");
	cout << endl;
	UserInputs::setConsoleColor(GREEN);
	cout << "A Teacher Has Been Deleted Named: " << teacher->getName();
	IT->deleteAccountFaculty(*teacher);
	department->printTeachers();
}

void FunctionsITManager::createAccountFaculty(ITManager * IT)
{
	system("cls");
	cout << "\t\tLogged In Name: " << IT->getName() << endl;
	cout << "\t\tLogged In UserID: " << IT->getUserID() << endl;
	cout << "\n*********Command For Creating an Faculty Account" << endl;
	bool type=false;
	Teacher*teacher = UserInputs::createAccountInformation<Teacher>(type,IT->getDepartment()); // false type is a faculty account
	IT->createAccountFaculty(*teacher);
	cout << endl;
	system("cls");
	cout << endl;
	UserInputs::setConsoleColor(GREEN);
	cout << "New Teacher Has Been Added Named: "<<teacher->getName();
	IT->getDepartment()->printTeachers();
}


