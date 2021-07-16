#pragma once

class helpTemplate
{
public:
	template<typename T>
	static void grow2DArray( T**& array, int& size);
	template<typename T>
	static int checkPresence(const T& obj, const T**array2D, int size2D);
	template<typename T>
	static void removePointerFrom2DArray(T** array2D, int size2D, int index); 
	
};
template<typename T>
void helpTemplate::grow2DArray( T**& array, int& size) //size doubles
{
	T** temp = new T*[size * 2];
	for (int i = 0; i < size; i++)
	{
		temp[i] = array[i];
	}
	delete[]array;
	array = temp;
	size *= 2;
}
template<typename T>
int helpTemplate::checkPresence( const T& obj, const T**array2D, int size2D)
{
	bool presence = false;
	int i = 0;
	for (; i < size2D && !presence; i++)
	{
		if ((T&)obj == *(array2D[i]))
		{
			presence = true;
			break;
		}
	}
	if (presence)
	{
		return i;
	}	
	return -1;
}
template<typename T>
void helpTemplate::removePointerFrom2DArray(T** array2D, int size2D, int index)
{
	if (array2D[index] != nullptr)
	{
		delete[] array2D[index];
	}
	int i = index;
	for (; i < size2D-1; i++)
	{
		array2D[i] = array2D[i + 1];
	}
	array2D[i] = nullptr;
}