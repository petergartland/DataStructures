#include <iostream>
#include <string>
#include "chainhashing.h"
#include <list>

using namespace std;

int main()
{

/*
	list<int> mylist;
	mylist.push_back(5);
	mylist.push_back(10);
	list<int>::iterator itr = mylist.begin();
	cout<<*itr<<endl;
	itr++;
	cout<<*itr<<endl;
	return 0;
*/

	HashTable<string> table("no", 101);
	table.insert("peter");
	table.insert("pesdfter");
	table.insert("pefdster");
	table.insert("peer");
	table.insert("petr");
	table.insert("peteeer");
	table.insert("peter");
	table.find("r");
	cout<<table.find("eter")<<endl;


}
