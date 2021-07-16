#include "Employee.h"
#include<stdexcept>
using namespace std;

Employee::Employee(int userID,int password,char*name,int age )
	:Person(userID,password)
{
	if (help::validationCharArray(name) == false)
		throw invalid_argument("invalid Name");
	help::memoryAllocateAndCopy(this->name, name);
	if (age <= 5)
		throw invalid_argument("invalid Age");
}

Employee::~Employee()
{
	if(name!=nullptr)
		delete []name;
}


Employee Employee::setAge(int age)
{
	this->age = age;
	return *this;
}

char * Employee::getName()const
{
	return name;
}

int Employee::getAge() const
{
	return age;
}

int Employee::getUserID() const
{
	return Person::getUserID();
}

bool Employee::setUserID(int userID)
{
	Person::setUserID(userID);
	return true;
}

int Employee::getPassword() const
{
	return Person::getPassword();
}

bool Employee::setPassword(int password)
{
	Person::setPassword(password);
	return true;
}
