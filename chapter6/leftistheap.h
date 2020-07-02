#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H

#include <algorithm>
#include <iostream>

template <class Comparable>
class LeftistHeap;

template <class Comparable>
class LeftistNode
{
	Comparable element;
	LeftistNode* left;
	LeftistNode* right;
	int npl;
	
	LeftistNode (const Comparable & theElement, LeftistNode * lt = NULL, LeftistNode *rt = NULL, int np = 0) : element(theElement), left(lt), right(rt), npl(np) {}
	friend class LeftistHeap<Comparable>; 
};


template <class Comparable>
class LeftistHeap
{
public:
	LeftistHeap() : root(NULL) {}
	LeftistHeap(const LeftistHeap & rhs);
	~LeftistHeap();
	
	void print();
	
	bool isEmpty();
	bool isFull();
	const Comparable & findMin() const;
	
	void insert(const Comparable & x);
	void deleteMin();
	void deleteMin(Comparable & minItem);
	void makeEmpty();
	void merge(LeftistHeap & rhs);
	
	const LeftistHeap & operator=(const LeftistHeap & rhs);

private:
	void print(LeftistNode<Comparable> *t) const;
	
	LeftistNode<Comparable> *root;
	
	LeftistNode<Comparable> * merge(LeftistNode<Comparable> * h1, LeftistNode<Comparable> * h2) const;
	
	LeftistNode<Comparable> * merge1(LeftistNode<Comparable> * h1, LeftistNode<Comparable> * h2) const;
	
	void swapChildren(LeftistNode<Comparable> * t) const;
	void reclaimMemory(LeftistNode<Comparable> *t) const;
	LeftistNode<Comparable> * clone(LeftistNode<Comparable> *t) const;
};

template <class Comparable>
void LeftistHeap<Comparable>::merge(LeftistHeap & rhs)
{
	if (this == &rhs)
		return;
	
	root = merge(root, rhs.root);
	rhs.root = NULL;
}

template <class Comparable>
LeftistNode<Comparable>* LeftistHeap<Comparable>::merge(LeftistNode<Comparable>* h1, LeftistNode<Comparable>* h2) const
{
	if (h1 == NULL)
		return h2;
	else if (h2 == NULL)
		return h1;
	else if (h1->element < h2->element)
		return merge1(h1, h2);
	else
		return merge1(h2,h1);
}
 
template <class Comparable>
LeftistNode<Comparable>* LeftistHeap<Comparable>::merge1(LeftistNode<Comparable>* h1, LeftistNode<Comparable>* h2) const
{
	if(h1->left == NULL)
		h1->left = h2;
	else
	{
		h1->right = merge(h1->right, h2);
		if (h1->left->npl < h1->right->npl)
			swapChildren(h1);
		h1->npl = h1->right->npl + 1;
	}
	return h1;
}

template <class Comparable>
void LeftistHeap<Comparable>::insert(const Comparable & x)
{
	root = merge(new LeftistNode<Comparable>(x), root);	
}
template <class Comparable>
void LeftistHeap<Comparable>::print()
{
	print(root);
}

template <class Comparable>
void LeftistHeap<Comparable>::print(LeftistNode<Comparable> *t) const
{
	if (t == NULL)
	{
		std::cout<<"nothing"<<std::endl;
		return;
	}
	std::cout<<t->element<<std::endl;
	std::cout<<"left child of "<<t->element<<" : ";
	print (t->left);
	std::cout<<"right child of "<<t->element<<" : ";
	print(t->right);
}

template <class Comparable>
void LeftistHeap<Comparable>::swapChildren(LeftistNode<Comparable> *t) const
{
	LeftistNode<Comparable>* temp = t->left;
	t->left = t->right;
	t->right = temp;
}

template <class Comparable>
void LeftistHeap<Comparable>::deleteMin()
{
	LeftistNode<Comparable> * oldroot = root;
	root = merge(root->left, root->right);
	delete oldroot;
}


template <class Comparable>
void LeftistHeap<Comparable>::makeEmpty()
{
	reclaimMemory(root);
	root = NULL;
}

template <class Comparable>
void LeftistHeap<Comparable>::reclaimMemory(LeftistNode<Comparable>* t) const
{
	if (t == NULL)
		return;
	reclaimMemory(t->left);
	reclaimMemory(t->right);
	delete t;
}

template <class Comparable>
LeftistHeap<Comparable>::~LeftistHeap()
{
	makeEmpty();
}

template <class Comparable>
const LeftistHeap<Comparable> & LeftistHeap<Comparable>::operator=(const LeftistHeap<Comparable> & rhs)
{
	if (this == &rhs)
		return *this;
	root = new LeftistNode<Comparable>(*rhs.root);
	root->left = clone(rhs.root->left);
	root->right = clone(rhs.root->right);
}

template <class Comparable>
LeftistNode<Comparable> * LeftistHeap<Comparable>::clone(LeftistNode<Comparable> *t) const
{
	if (t == NULL)
		return NULL;
	LeftistNode<Comparable> * newNode = new LeftistNode<Comparable>(*t);
	newNode->left = clone(t->left);
	newNode->right = clone(t->right);
	return newNode;
}

#endif
