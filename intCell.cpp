#include <iostream>
#include <string>
#include <vector>
#include "intCellClass.h"
#include "intCellHead.h"

using namespace std;

const int & findmax(const vector<int> & a)
{
	int maxIndex = 0;
	
	for(int i = 1; i < a.size(); i++)
	{
		if (a[i] > a[maxIndex])
			maxIndex = i;
	}
	
	return a[maxIndex];
}

/*
const int & findmaxwrong(const vector<int> & a)
{
	int max = a[0];
	
	for(int i = 1; i < a.size(); i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	
	return max;
}
*/


int main()
{
/*
	IntCell cell(7);
	IntCell cell2(5);
	cell = cell2;
	cout<<cell.read()<<endl;
	
	vector<int> a = {1,10,22,7,0,-2,};
	a.push_back(3);
	//cout<<findmaxwrong(a)<<endl;
*/
	IntCellPoint cell(5);
	IntCellPoint cell2 = cell;
	cell2.write(7);
	cell = cell2;
	cout<<cell.read()<<endl;
		
}
