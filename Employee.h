#pragma once
#include"Person.h"
#include"help.h"


class Employee:virtual public Person
{
	char*name;
	int age;
public:
	Employee(int userID, int password,char*name,int age=30);
	virtual ~Employee();
	Employee setAge(int age);
	char*getName()const;
	int getAge()const;
	int getUserID()const;
	bool setUserID(int userID);
	int getPassword()const;
	bool setPassword(int password);
};

