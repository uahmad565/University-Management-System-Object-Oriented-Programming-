#include "IdGenerator.h"

int IdGenerator::getNextId()
{
	return ++next;
}
