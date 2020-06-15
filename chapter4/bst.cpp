#include <iostream>
#include <string>
#include "bsn.h"
#include "bst.h"


using namespace std;

int main()
{
	BinarySearchTree<int> tree;
	tree.insert(5);
	tree.insert(55);
	tree.insert(1);
	tree.insert(52);
	tree.insert(23);
	tree.insert(98);
	tree.insert(51);
	tree.insert(100);
	tree.insert(-19);
	tree.insert(8);
	cout<<tree.findMin()<<endl;
	tree.remove(-19);
	cout<<tree.findMin()<<endl;
	tree.insert(-100);
	cout<<tree.findMin()<<endl;
	tree.remove(51);
	cout<<tree.find(23)<<endl;
	cout<<tree.findMax()<<endl;
	
}
