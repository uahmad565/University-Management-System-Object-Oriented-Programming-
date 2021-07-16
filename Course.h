#pragma once

class TA;
class Teacher;
class Registeration;
class IdGenerator;

class Course
{
private:
	char* code;
	char* name;
	const TA * assistant;
	const Teacher**teachers;
	const Registeration ** registerations;
	int currentRegistrations;
	int maxRegisterations;
	int id;
	static IdGenerator idGenerator;
	int currentTeachersCount;
	int teachersCapacity;
public:
	~Course();
	Course(char*code, char* name);
	Course setCode(char* code);
	char* getCode() const;
	Course setName(char* name);
	char* getName() const;
	Registeration**getRegisterations()const;
	int getCurrentRegisterations()const;
	Course setAssistant(const TA* assistants);
	TA* getAssistant() const;
	bool addRegistration(const Registeration& registration);
	bool addRegistration(const Registeration* registeration);
	Registeration* getRegistrationById(int registrationId) const;
	bool removeRegistrationbyID( int id);
	bool operator==(const Course& obj);
	void viewGrades()const;
	void viewMarkSheet() const;
	void viewAttendanceCourse()const;
	int getId() const;
	bool removeRegistrationbyId(int id);
	void addTeacher(const Teacher& teacher);
	void printCourse()const;
	void printCourseFullInformation()const;
	void printRegisterations()const;
	Registeration*getRegisterationByCourseID(int id) const;
};

