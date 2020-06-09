#include <iostream>
#include <string>
#include <vector>
#include "helpTemplate.h"

using namespace std;

template <class Comparable>
const Comparable & findMax (const vector<Comparable> & vec)
{
	int maxIndex = 0;
	for(int i=1; i<vec.size(); i++)
	{
		if (vec[maxIndex] < vec[i])
			maxIndex = i;
	}
	return vec[maxIndex];
}


int main()
{
	vector<int> test = {1,7,88,-101,2,55};
	int resp1 = findMax(test);
	resp1 = 10;
	cout<<resp1<<endl;
	vector<string> test2  {"hello", "world", "my", "alphabet", "soup"};
	string resp = findMax(test2);
	cout<<resp<<endl;
	
	MemoryCell<int> intCell(5);
	cout<<intCell.read()<<endl;
} 
