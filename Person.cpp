#include "Person.h"
#include"help.h"
#include<stdexcept>
using namespace std;


Person::Person(int userID, int password)
{
	this->userID = userID;
	this->password = password;
}

Person::~Person()
{
}

int Person::getUserID() const
{
	return userID;
}

int Person::setUserID(int id)
{
	this->userID = id;
	return 0;
}

bool Person::setPassword(int password)
{
	this->password = password;
	return true;
}

int Person::getPassword() const
{
	return password;
}




