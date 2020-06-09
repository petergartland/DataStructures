#ifndef EMPLOYEEHELP_H
#define EMPLOYEEHELP_H

#include <iostream>
#include <string>



class Employee
{
public:
	void setValue (const std::string & n, double s);
	void print (std::ostream & out) const;
	bool operator<(const Employee & rhs) const
	{return salary < rhs.salary;}
private:
	std::string name;
	double salary;
};

std::ostream & operator<<(std::ostream & out, const Employee & rhs);


#endif
