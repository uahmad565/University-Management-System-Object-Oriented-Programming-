#pragma once

class Student;
class FunctionsStudent
{
public:
	static void registerCourse(Student*student);
	static void unregisterCourse(Student*student);
	static void withDrawCourse(Student*student);
	static void changePassword(Student*student);
	static void ViewMarkSheetCourse(Student*student);
	static void viewAttendanceCourse(Student*student);
	
};

