#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"

using namespace std;

bool symbolCheck (string source)
{
	ifstream infile ("symbols.txt");
	Stack<char> stack;
	string symbols;
	while (infile >> symbols)
	{
		for (int i = 0; i < symbols.size(); i++)
		{
			if (symbols.substr(i,1) == "}")
			{
				if(!stack.isEmpty() && stack.top() == '{')
					stack.pop();
				else
				{
					cout<<"no matching '}'"<<endl;
					return false;
				}
			}
			else if (symbols.substr(i,1) == "{")
				stack.push('{');

			else if (symbols.substr(i,1) == ")")
			{
				if(!stack.isEmpty() && stack.top() == '(')
					stack.pop();
				else
				{
					cout<<"no matching ')'"<<endl;
					return false;
				}
			}
			else if (symbols.substr(i,1) == "(")
				stack.push('(');
			else
			{
				cout<<"bad input"<<endl;
				return false;
			}
			
		}
	}
	return true;
}

int main()
{
/*
	Stack<int> stack;
	stack.push(5);
	stack.push(99);
	stack.push(-2);
	cout<<stack.top()<<std::endl;
	stack.pop();
	cout<<stack.topAndPop()<<endl;
	cout<<stack.top()<<endl;
*/
	cout<<symbolCheck("F")<<endl;
}
