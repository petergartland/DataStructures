#include <iostream>
#include <string>
#include <vector>
//#include "heap.h"
#include "leftistheap.h"

using namespace std;

int main()
{

	LeftistHeap<int> leftheap;
	leftheap.insert(5);
	leftheap.insert(15);
	leftheap.insert(25);
	leftheap.insert(-5);
	leftheap.insert(-15);
	leftheap.insert(35);
	leftheap.insert(55);
	leftheap.insert(575);
	leftheap.insert(15999);
	LeftistHeap<int> leftheap2;
	leftheap2.insert(-980925);
	leftheap2.insert(998);
	leftheap2.insert(7);
	leftheap2.insert(97);
	leftheap2.insert(2);
	leftheap2.insert(88);
	leftheap.merge(leftheap2);
	leftheap.print();
	leftheap.deleteMin();
	leftheap.print();
	LeftistHeap<int> leftheap3;
	leftheap3 = leftheap;
	cout<<endl;
	leftheap3.print();
	

/*
	vector<int> vec = {1003,12,103,135,-12,2389,123,987,101,13222,-122,233};
	BinaryHeap<int> heap(vec);
/*	
	heap.insert(1003);
	heap.insert(12);
	heap.insert(103);
	heap.insert(135);
	heap.insert(-12);
	heap.insert(2389);
	heap.insert(123);
	heap.insert(987);
	heap.insert(101);
	heap.insert(13222);
	heap.insert(-122);
	heap.insert(2383232);
	heap.deleteMin();
	heap.deleteMin();
	heap.insert(111);
	heap.insert(-8);
	heap.deleteMin();
	
	for (int i = 1; i < heap.array.size(); i++)
		cout<<heap.array[i]<<endl;
	return 0;
	
*/
}
