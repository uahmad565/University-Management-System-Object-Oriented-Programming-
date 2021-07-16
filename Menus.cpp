#include "Menus.h"
#include "Enums.h"
#include "UserInputs.h"

void Menus::PrintMenuHOD()
{
	UserInputs::setConsoleColor(WHITE);
	cout << "       HEAD OF DEPARTMENT (HOD)" << endl
		<< "  Choose an option:" << endl
		<< " 1 - Assign a courses To a Teacher" << endl
		<< " 2 - Register a course for a student" << endl
		<< " 3 - Unregister a course for a student" << endl
		<< " 4 - View grades of a specific course" << endl
		<< " 0 - Exit" << endl;
}

void Menus::PrintMenuITManager()
{
	UserInputs::setConsoleColor(WHITE);
	cout << "      IT Manager" << endl
		<< " Choose an option:" << endl
		<< " 1 - Create an account for Faculty Member" << endl
		<< " 2 - Delete an account of Faculty Member" << endl
		<< " 3 - Create account of students" << endl
		<< " 4- Delete accounts of students" << endl
		<< " 5- Maintain accounts(e.g.change username, password, etc.)"<<endl
		<< " 0 - Exit" << endl;
}
void Menus::PrintMenuTeacher()
{
	UserInputs::setConsoleColor(WHITE);
	cout << "      Teacher" << endl
		<< " Choose an option:" << endl
		<< " 1 - Manage attendance of students" << endl
		<< " 2 - View attendance of a course" << endl
		<< " 3 - Manage evaluations of students (e.g. enter marks, manage weightage)" << endl
		<< " 4 - View evaluation report of a specific course displaying all evaluations of all the students of that course" << endl
		<< " 5 - Assign grades to students" << endl
		<< " 0 - Exit" << endl;
}
void Menus::PrintMenuStudent()
{
	UserInputs::setConsoleColor(WHITE);
	cout << "      Student" << endl
		<< " Choose an option:" << endl
		<< " 1 - Register courses according to the specified workload" << endl
		<< " 2 - Unregister a course" << endl
		<< " 3 - Withdraw a course" << endl
		<< " 4 - View mark sheet of a specific course" << endl
		<< " 5 - View attendance of a specific course" << endl
		<< " 6 - Change password" << endl
		<< " 0 - Exit" << endl;
}

void Menus::PrintLoginMenu()
{
	UserInputs::setConsoleColor(WHITE);
	cout << "      Select your role" << endl
		<< " 1 - Head of Department (HOD)" << endl
		<< " 2 - Teacher" << endl
		<< " 3 - IT Manager" << endl
		<< " 4 - Student" << endl
		<< " 0 - Exit" << endl;
}

void Menus::PrintWelcome()
{
	UserInputs::setConsoleColor(WHITE);
	cout << "\t\t Welcome to University Management System." << endl;
}

void Menus::PrintRoleLoginName(Role role)
{
	switch (role)
	{
	case HEAD_OF_DEPARTMENT:
		cout << "Login HOD Menu:" << endl;
		break;
	case TEACHER:
		cout << "Login Teacher Menu:" << endl;
		break;
	case IT_MANAGER:
		cout << "Login IT Manager Menu:" << endl;
		break;
	case STUDENT:
		cout << "Login Student Menu:" << endl;
		break;
	default:
		cout << "User has choosen wrong Role:" << endl;
		break;
	}
}

void Menus::PrintSelectAccountTypeITManager()
{
	UserInputs::setConsoleColor(WHITE);
	cout << "\tChoose an Account Type"<<endl
		<< "1- Change Student Account" << endl
		<< "2- Change Faculty Account" << endl
		<< "0- Exit" << endl;
}


void Menus::PrintCreateAccountTypeITManager()
{
	UserInputs::setConsoleColor(WHITE);
	cout<<"\tChoose an Option"<<endl
	 << "1-Change userID and Password"
		<< "\n2-Change userID"
		<< "\n3-Change Password"
		<< "\n0-No Change" << endl;
}

int Menus::GetInput(int min, int max)
{
	UserInputs::setConsoleColor(WHITE);
	cout << " Enter a choice: ";
	int choice = 0;
	do
	{
		cin >> choice;
		if (choice < min || choice > max)
		{
			UserInputs::setConsoleColor(RED);
			cout << " Invalid option entered. Please enter between " << min << " and " << max << ": ";
			cin >> choice;
		}

	} while (choice < min || choice > max);

	return choice;
}
