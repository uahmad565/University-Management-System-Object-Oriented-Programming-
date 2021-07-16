#pragma once

class HOD;

class FunctionsHOD
{
public:
	static void AssignCourseToTeacher(HOD* hod);
	static void RegisterCourseForStudent(HOD* hod);
	static void UnregisterCourseForStudent(HOD* hod);
	static void ViewGradesOfCourse(HOD* hod);
};

