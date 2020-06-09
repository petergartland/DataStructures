#include <iostream>
#include <string>
#include <vector>

using namespace std;

void permute (const string & str, int low, int high)
{
	//cout<<str<<endl;
	//cout<<"3"<<endl;
	if(high - low == str.length())
	{
		cout<<str<< " ";
		return;
	}
	//cout<<5<<endl;
	string upper = str.substr(high+1,str.length()-high-1);	
	//cout<<6<<endl;
	
	for(int i = 0; i < high+1; i++)
	{
	//	cout<<7<<endl;
		string str1 = str.substr(0,i) + str[high] + str.substr(i,high-i) + upper;
		permute(str1, low, high+1);			
	}
}


void permute(const string & str)
{
	//cout<<"1"<<endl;
	permute (str, 0, 1);
	//cout<<"2"<<endl;
}


int main()
{
	string s = "hello";
	string g = s.substr(0,2) + "c";
	//cout<<g<<endl;
	permute("abc");
}
