#include <string>
#include <iostream>
#include <vector>
#include "employeeHelp.h"

using namespace std;

template <class Comparable>
const Comparable & findMax (const vector<Comparable> & vec)
{
	int maxIndex = 0;
	for(int i=1; i<vec.size(); i++)
	{
		if (vec[maxIndex]<vec[i])
			maxIndex = i;
	}
	return vec[maxIndex];
}


int main()
{
	Employee peter;
	peter.setValue("peter", 100000);
	cout<<peter<<endl;
	Employee chris;
	chris.setValue("chris", 9999);
	Employee bill;
	bill.setValue("bill", 99999999999);
	vector<Employee> people;
	people.push_back(peter);
	people.push_back(bill);
	people.push_back(chris);
	
	cout<<findMax(people)<<endl;
}
