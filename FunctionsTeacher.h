#pragma once
#include "Enums.h"

class Teacher;
class FunctionsTeacher
{
public:
	static void ManageAttendanceCourse(Teacher*teacher); 
	static void viewAttendanceCourse(Teacher*teacher);
	static void ManageEvaluationStudent(Teacher*teacher);
	static void AssignGradesToStudents(Teacher*teacher);
	static void viewEvaluationCourse(Teacher*teacher);
};

