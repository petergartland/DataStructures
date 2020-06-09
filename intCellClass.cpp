#include "intCellClass.h"


IntCell::IntCell(int value) : storedValue(value)
{
}

IntCell::~IntCell()
{
}

IntCell::IntCell(const IntCell & rhs) : storedValue(rhs.storedValue)
{

}

const IntCell & IntCell::operator=(const IntCell & rhs)
{
	if (this != &rhs)
		storedValue = rhs.storedValue;
	return *this;
}

/*
IntCell::IntCell(int value)
{
	storedValue = value;
}
*/

int IntCell::read() const
{
	return storedValue;
}

void IntCell::write(int value)
{
	storedValue = value;
}
