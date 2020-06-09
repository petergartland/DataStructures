#include "intCellHead.h"

IntCellPoint::IntCellPoint(int value)
{
	storedValue = new int(value);
}

IntCellPoint::IntCellPoint(const IntCellPoint & rhs)
{
	storedValue = new int(*rhs.storedValue);
}

IntCellPoint::~IntCellPoint()
{
	delete storedValue;
}

int IntCellPoint::read() const
{
	return *storedValue;
}

const IntCellPoint & IntCellPoint::operator=(const IntCellPoint & rhs)
{
	if (this != &rhs)
	{
		delete storedValue;
		storedValue = new int(*rhs.storedValue);
	}
	return *this;
}

void IntCellPoint::write(int value)
{
	//delete storedValue;
	*storedValue = value;
}
