#pragma once
class IdGenerator
{
private:
	int next = 0;
public:
	int getNextId();
};