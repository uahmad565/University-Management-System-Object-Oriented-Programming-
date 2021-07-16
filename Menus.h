#pragma once
#include <iostream>
#include"Enums.h"
using namespace std;

class Menus
{
public:
	static void PrintMenuHOD();
	static void PrintMenuITManager();
	static void PrintMenuTeacher();
	static void PrintMenuStudent();
	static void PrintLoginMenu();
	static void PrintWelcome();
	static void PrintRoleLoginName(Role role);
	static void PrintSelectAccountTypeITManager();
	static void PrintCreateAccountTypeITManager();
	static int GetInput(int min, int max);
};

