#pragma once
class Person
{
private:
	int userID;
	int password;
public:
	Person(int userID, int password);

	virtual ~Person();
	int getUserID() const;
	int setUserID(int id);
	bool setPassword(int password);
	int getPassword()const;
};