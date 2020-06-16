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
	BinarySearchTree<int> tree2;
	tree2=tree;
	cout<<tree2.findMin()<<endl;
	tree2.remove(-19);
	cout<<tree2.findMin()<<endl;
	tree2.insert(-100);
	cout<<tree2.findMin()<<endl;
	tree2.remove(51);
	cout<<tree2.find(23)<<endl;
	cout<<tree2.findMax()<<endl;

	
}
