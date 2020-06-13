#include <iostream>
#include <string>
#include <vector>
#include "linkedlistNode.h"
#include "linkedlistItr.h"
#include "linkedlistList.h"
#include "polynomial.h"

using namespace std;

int main()
{
/*
	List<int> test;
	printList(test);
	test.insert(5,test.zeroth());
	printList(test);
	test.insert(7,test.first());
	printList(test);
	cout<<endl;
	test.insert(19, test.find(7));
	test.insert(88, test.find(7));
	printList(test);
	//test.remove(88);
	cout<<endl;
	//printList(test);
	test.makeEmpty();
	printList(test);
	test.insert(9, test.zeroth());
	printList(test);
	List<int> test2;
	
	test.insert(90, test.first());
	test2 = test;
	printList(test);
	printList(test2);
	*/
	
	
	/*
	Polynomial poly;
	poly.insertTerm(5,11);
	poly.insertTerm(9,109);
	poly.insertTerm(88,3);
	poly.insertTerm(8,12);
	poly.insertTerm(8,11);
	poly.printTerms();
	std::cout<<std::endl;
	
	Polynomial poly2;
	poly2.insertTerm(15,1);
	poly2.insertTerm(3,10);
	poly2.insertTerm(-80,3);
	poly2.insertTerm(2,17);
	poly2.insertTerm(8,11);
	poly2.printTerms();
	std::cout<<std::endl;
	
	Polynomial poly3;
	poly3 = poly + poly2;
	poly3.printTerms();
	std::cout<<std::endl;
	Polynomial poly5;
	poly5 = poly*poly2;
	poly5.printTerms();
	*/
	
	List<int> list;
	list.insert(5, list.zeroth());
	list.insert(9, list.zeroth());
	list.insert(1, list.zeroth());
	list.insert(33, list.zeroth());
	list.insert(22, list.zeroth());
	list.insert(11, list.zeroth());
	printList(list);
	cout<<endl;
	/*
	list.swap(5);
	printList(list);
	*/
	cout<<endl;
	List<int> list2;
	list2.insert(21, list2.zeroth());
	list2.insert(91, list2.zeroth());
	list2.insert(12, list2.zeroth());
	list2.insert(331, list2.zeroth());
	list2.insert(351, list2.zeroth());
	printList(list2);
	cout<<endl;
	list.cutNPaste(list.find(22), list.find(1), list2, list2.find(12));
	printList(list);
	cout<<endl;
	printList(list2);	
}



