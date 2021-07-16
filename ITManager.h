#pragma once
#include"Employee.h"
class Person;
class Department;
class Student;
class Teacher;
class ITManager: public Employee
{
private:
	 Department* department;
public:
	ITManager(int userID, int password, char*name, Department* department);
	virtual ~ITManager();
	bool operator==(const ITManager& obj)const;
	void createAccountStudent(const Student& student);
	bool deleteAccountStudent(const Student& student);
	bool deleteAccountFaculty(const Teacher& teacher);
	bool createAccountFaculty(const Teacher& teacher);
	bool setAccountPass(Person*person, int password);
	bool setAccountUserID(Person*person, int userId);
	int getAccountPass(Person*person);
	void printITManager()const;
	Department* getDepartment() const;
};

