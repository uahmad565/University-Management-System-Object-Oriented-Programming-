#pragma once

class ITManager;
class FunctionsITManager
{
public:
	static void createAccountFaculty(ITManager* IT);
	static void deleteAccountFaculty(ITManager* IT);
	static void createAccountStudent(ITManager* IT);
	static void deleteAccountStudent(ITManager* IT);
	static void MaintainAccount(ITManager*IT);
};

