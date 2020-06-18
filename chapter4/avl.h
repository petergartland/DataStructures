#include <algorithm>

template <class Comparable>
class AVLTree
{
public: 
	void insert( const Comparable & t);
	const Comparable findMax() const;
	const Comparable findMin() const;
	const Comparable find(const Comparable & x) const;
	void remove(const Comparable & x);
	
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
	
	const Comparable elementAt(const AVLNode<Comparable>* t) const;
	int height (AVLNode<Comparable>* t) const;
	
	const AVLNode<Comparable>* findMax(const AVLNode<Comparable>* t) const;
	const AVLNode<Comparable>* findMin(const AVLNode<Comparable>* t) const;
	
	void remove(const Comparable & x, AVLNode<Comparable>* & t) const;
	//const AVLNode<Comparable>* findMinRemove(cosnt AVLNode<Comparable>* t) const;
	int height(const AVLNode<Comparable>* t);
};

template <class Comparable>
const Comparable AVLTree<Comparable>::elementAt(const AVLNode<Comparable>* t) const
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
		std::cout<<elementAt(t)<< " has a height of " << t->height<<std::endl;
	}
}


template <class Comparable>
void AVLTree<Comparable>::print() const
{
	print(root);
}

template <class Comparable>
const AVLNode<Comparable>* AVLTree<Comparable>::findMax(const AVLNode<Comparable>* t) const
{
	if (t->right == NULL)
		return t;
	return findMax(t->right);
}

template <class Comparable>
const Comparable AVLTree<Comparable>::findMax() const
{
	return elementAt(findMax(root));
}


template <class Comparable>
const AVLNode<Comparable>* AVLTree<Comparable>::findMin(const AVLNode<Comparable>* t) const
{
	if (t->left == NULL)
		return t;
	return findMin(t->left);
}

/*
template <class Comparable>
const AVLNode<Comparable>* AVLTree<Comparable>::findMinRemove(const AVLNode<Comparable>* t) const
{
	if (t->left == NULL)
	{
		return t;
	}
	
	return findMin(t->left);
}
*/

template <class Comparable>
const Comparable AVLTree<Comparable>::findMin() const
{
	return elementAt(findMin(root));
}


template <class Comparable>
void AVLTree<Comparable>::remove(const Comparable& x, AVLNode<Comparable>* & t) const
{
	std::cout<<"here1"<<std::endl;
	if (x < t-> element)
	{
		std::cout<<"here2"<<std::endl;
		remove(x,t->left);
		if (height(t->right)-height(t->left) > 1)
		{
			std::cout<<"here3"<<std::endl;
			//height(t->right->right);
			std::cout<<"element " << t->right->element<<std::endl;
			if (height(t->right->left) > height(t->right->right))
			{
				std::cout<<"here13"<<std::endl;
				doubleRotateWithRightChild(t);
			}
			else
			{
				std::cout<<"here15"<<std::endl;
				rotateWithRightChild(t);
			}
			std::cout<<"here5"<<std::endl;
		}
	}
	else if (x > t->element)
	{
		std::cout<<"here7"<<std::endl;
		remove(x,t->right);
		if (height(t->left)-height(t->right) > 1)
		{
			std::cout<<"here8"<<std::endl;
			if (height(t->left->right) > height(t->left->left))
				doubleRotateWithLeftChild(t);
			else
				rotateWithLeftChild(t);
		}
		std::cout<<"here9"<<std::endl;
		
	}
	else if (t == NULL)
		return;
	else if (t->right == NULL)
	{
		AVLNode<Comparable>* temp = t;
		t = t->left;
		delete temp;
		return;
	}
	else if(t->left == NULL)
	{
		AVLNode<Comparable>* temp = t;
		t = t->right;
		delete temp;
		return;
	}
	else
	{
		t->element = (elementAt(findMin(t->right)));
		remove(t->element, t->right);
	}
	std::cout<<"here10"<<std::endl;
	t->height = std::max(height(t->left), height(t->right)) + 1;
	
}


template <class Comparable>
int AVLTree<Comparable>::height(const AVLNode<Comparable>* t)
{
	if (t == NULL)
		return -1;
	return t->height;
}

template <class Comparable>
void AVLTree<Comparable>::remove(const Comparable & x)
{
	remove(x, root);
}
