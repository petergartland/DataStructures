#include <algorithm>

template <class Comparable>
class AVLTree
{
public: 
	void insert( const Comparable & t);
	const Comparable & findMax() const;
	const Comparable & findMin() const;
	const Comparable find(const Comparable & x) const;
	
	void print() const;
	AVLTree() : root(NULL) {}
	
private:
	AVLNode<Comparable>* root;
	
	void print(AVLNode<Comparable>* t) const;
	
	void insert(const Comparable & x, AVLNode<Comparable>* & t) const;
	AVLNode<Comparable>* find (const Comparable & x, AVLNode<Comparable>* t) const;
	void rotateWithRightChild (AVLNode<Comparable>* & t) const;
	void rotateWithLeftChild (AVLNode<Comparable>* & t) const;
	void doubleRotateWithRightChild(AVLNode<Comparable>* & t) const;
	void doubleRotateWithLeftChild(AVLNode<Comparable>* & t) const;
	
	Comparable elementAt(AVLNode<Comparable>* t) const;
	int height (AVLNode<Comparable>* t) const;
	
};

template <class Comparable>
Comparable AVLTree<Comparable>::elementAt(AVLNode<Comparable>* t) const
{
	if (t == NULL)
		return -1;
	return t->element;
}

template <class Comparable>
AVLNode<Comparable>* AVLTree<Comparable>::find(const Comparable & x, AVLNode<Comparable>* t) const
{
	if (t == NULL)
	{
		return NULL;
	}
	else if (x < t->element)
	{
		return find(x,t->left);
	}
	else if (x > t->element)
	{
		return find(x,t->right);
	}
	return t;
}

template <class Comparable>
const Comparable AVLTree<Comparable>::find(const Comparable & x) const
{
	return elementAt(find(x, root));
}


template <class Comparable>
int AVLTree<Comparable>::height(AVLNode<Comparable>* t) const
{
	if (t == NULL)
		return -1;
	return t->height;
}

template <class Comparable>
void AVLTree<Comparable>::insert(const Comparable & x, AVLNode<Comparable>* & t) const
{
	
	if (t == NULL)
	{
		t = new AVLNode<Comparable>(x, NULL, NULL, 0);
	}
	else if (x < t->element)
	{
		insert(x, t->left);
		if (height(t->left) - height(t->right) > 1)
		{
			if (x < t->left->element)
				rotateWithLeftChild(t);
			else
				doubleRotateWithLeftChild(t);
		}
	}
	else if (x > t->element)
	{
		insert(x, t->right);
		if (height(t->right) - height(t->left) > 1)
		{
			if (x > t->right->element)
				rotateWithRightChild(t);
			else
				doubleRotateWithRightChild(t);
		}
	}
	t->height = std::max(height(t->left),height(t->right))+1;
}


template <class Comparable>
void AVLTree<Comparable>::insert(const Comparable & x)
{
	insert(x, root);
}


template <class Comparable>
void AVLTree<Comparable>::rotateWithRightChild(AVLNode<Comparable>* & t) const
{
	
	std::cout<<1<<std::endl;
	AVLNode<Comparable>* rightChild = t->right;
	t->right = rightChild->left;
	rightChild->left = t;
	t->height = std::max(height(t->left),height(t->right))+1;
	rightChild->height = std::max(height(rightChild->left),height(rightChild->right))+1;
	t = rightChild;
} 


template <class Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(AVLNode<Comparable>* & t) const
{
	std::cout<<2<<std::endl;
	AVLNode<Comparable>* leftChild = t->left;
	t->left = leftChild->right;
	leftChild->right = t;
	t->height = std::max(height(t->left),height(t->right))+1;
	leftChild->height = std::max(height(leftChild->left),height(leftChild->right))+1;	
	t = leftChild;
}


template <class Comparable>
void AVLTree<Comparable>::doubleRotateWithLeftChild(AVLNode<Comparable>* & t) const
{
	std::cout<<3<<std::endl;
	rotateWithRightChild(t->left);
	rotateWithLeftChild(t);
}


template <class Comparable>
void AVLTree<Comparable>::doubleRotateWithRightChild(AVLNode<Comparable>* & t) const
{
	std::cout<<4<<std::endl;
	rotateWithLeftChild(t->right);
	rotateWithRightChild(t);
}

template <class Comparable>
void AVLTree<Comparable>::print(AVLNode<Comparable>* t) const
{
	if (t!=NULL)
	{
		print(t->left);
		print(t->right);
		std::cout<<elementAt(t)<<std::endl;
	}
}


template <class Comparable>
void AVLTree<Comparable>::print() const
{
	print(root);
}

