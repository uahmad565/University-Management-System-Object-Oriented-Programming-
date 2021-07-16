#pragma once
#include "Enums.h"

class help
{
public:
	static bool validationCharArray(char*name);	
	static void memoryAllocateAndCopy(char*& destination,char* source);
	static bool hasCapacity(int currentCount, int maxCount);
	static bool charArrayCompare(char * arr1, char * arr2);
	static char gradeToString(Grade grade);
};

