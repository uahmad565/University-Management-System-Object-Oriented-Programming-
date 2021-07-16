#pragma once
class Department;
class University
{
private:
	char* name;
	const Department** departments; //aggregate
	int departmentCapacity;
	int currentDepartmentsCount;
public:
	University(char* name, int departmentCount = 3);
	~University();
	University & addDepartment(const Department & obj);
	University setName(char* name);
	char* getName() const;
	Department* getDepartmentById(int id) const;
	Department**getDepartments()const;
	int getNoOfDepartments()const;
	void printUniversity()const;
	void printDepartments()const;
};

