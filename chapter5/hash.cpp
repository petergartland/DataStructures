#include <iostream>
#include <string>
//#include "chainhashing.h"
#include <list>
#include "linearhash.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{

	srand(time(NULL));
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

/*

	HashTable<string> table("no", 17);
	table.insert("peter");
	table.insert("pesdfter");
	table.insert("pefdster");
	table.insert("peer");
	table.insert("petr");
	table.insert("peteeer");
	table.insert("peter");
	table.find("r");
	cout<<table.find("peter")<<endl;
	table.remove("peter");
	cout<<table.find("peter")<<endl;
	table.insert("peter");
	cout<<table.find("peter")<<endl;
	cout<<table.collisions<<endl;	
*/
	int num;
	
	int average = 0;
	for (int j = 0; j < 100; j++)
	{
		HashTable<int> table(-1, 9973);
		for (int i = 0; i < 3000; i++)
		{
			num = rand() % 999999;
			table.insert(num);
		}
		average = average + table.collisions;
	}
	cout<<average/100<<endl;


	//HashTable<string> table("no", 101)
}
