#include <iostream>
#include <string>
#include "avlnode.h"
#include "avl.h"

int i = 5;
using namespace std;

int main()
{
	AVLTree<double> tree;
	tree.insert(6);
	tree.insert(10);
	tree.insert(12);
	cout<<endl;
	tree.print();
	cout<<endl;
	tree.insert(2);
	tree.insert(7);
	tree.insert(8);
	cout<<endl;
	tree.print();
	cout<<endl;
	tree.insert(9);
	tree.insert(1);
	tree.insert(9.5);
	cout<<endl;
	//tree.print();
	cout<<endl;
	tree.insert(9.7);
	tree.remove(8);
	tree.insert(6.5);
	tree.remove(1);
	tree.insert(13);
	cout<<999<<endl;
	cout<<endl;
	tree.print();
	//cout<<tree.findMin()<<endl;
}
