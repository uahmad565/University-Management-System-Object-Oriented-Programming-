#include "help.h"
#include<iostream>

bool help::validationCharArray(char*name)
{
	if (name == nullptr)
		return false;
	int length = strlen(name);
	if (length == 0)
		return false;
	return true;
	
}

void help::memoryAllocateAndCopy(char*& destination, char * source)
{
	int length = strlen(source)+1;
	destination = new char[length];
	strcpy_s(destination, length, source);
}

bool help::hasCapacity(int currentCount, int maxCount)
{
	return currentCount < maxCount;
}

bool help::charArrayCompare(char * arr1,char * arr2)
{
	int size1 = strlen(arr1);
	int size2 = strlen(arr2);
	if (size1 != size2)
	{
		return false;
	}
	for (int i = 0; arr1[i] != '\0'; i++)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

char help::gradeToString(Grade grade)
{
	switch (grade)
	{
	case A:
		return 'A';
	case B:
		return 'B';
	case C:
		return 'C';
	case D:
		return 'D';
	case F:
		return 'F';
	case W:
		return 'W';
	default:
		return '?';
	}
}
