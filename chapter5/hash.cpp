#include <iostream>
#include <string>
//#include "chainhashing.h"
#include <list>
//#include "linearhash.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <math.h>


using namespace std;


int hashFunct(const std::string & key, int tableSize)
{
	int ret = 0;
	for (int i = 0; i < key.length(); i++)
	{
		ret = ret*37 + key[i];
		ret = ret % tableSize; 
	}
	ret = ret % tableSize;
	if (ret < 0)
		ret = ret + tableSize;
	return ret;
}


int stringMatch(string word, string sentence, int size)
{
	int key = hashFunct(word, size);
	int current = hashFunct(sentence.substr(0,word.length()),size);
	int i = word.length();
	while (i < sentence.length()+1)
	{
		if (key == current)
		{
			if (word == sentence.substr(i-word.length(), word.length()))
			{
				return i-word.length()+1;
			}
		}
		current = current - sentence[i-word.length()]*pow(37,word.length()-1);
		current = (current % size)+size;
		current = current*37 + sentence[i];
		current = current % size;
		i++;
	}
	return -1;
}

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
		string test = "hello";
		string sentence = "dsjhfhellojdhfsdf";
		cout<<stringMatch(test,sentence,1000)<<endl;
		
	/*
	HashTable<string> table("no", 110000);
	
	//fstream myfile("/usr/share/dict/words");
	ifstream myfile("/home/peter/DataStructures/chapter5/words");
	if(!myfile.is_open())
		cout<<"error"<<endl;
	string line;
	while (myfile)
	{
		getline (myfile, line);
		table.insert(line);
	}
	
	string check;
	while (cin >> check)
	{
		if (table.find(check) != "no")
			cout<<"word"<<endl;

		
	}
		
	
/*
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
	//cout<<table.collisions<<endl;	
	
*/


/*
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
*/
}
