#include "employeeHelp.h"

using namespace std;

void Employee::setValue(const string & n, double s)
{
	name = n;
	salary = s;
}

void Employee::print( ostream & out) const
{
	out << name << " (" << salary << ")";
}

/*
bool Employee::operator<(const Employee & rhs)
{
	return salary < rhs.salary;
}
*/

ostream & operator<<(ostream & out, const Employee & rhs)
{
	rhs.print(out);
	return out;
}
