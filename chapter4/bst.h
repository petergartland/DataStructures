template<class Comparable>
class BinarySearchTree
{
public:
	explicit BinarySearchTree(const Comparable & notFound);
	BinarySearchTree() : root (NULL), ITEM_NOT_FOUND(0) {}
	BinarySearchTree(const BinarySearchTree & rhs );
	~BinarySearchTree();
	
	const Comparable & findMax() const;
	const Comparable & findMin() const;
	const Comparable & find (const Comparable & x) const;
	
	bool isEmpty() const;
	void printTree() const;
	
	void makeEmpty();
	void insert(const Comparable & x);
	void remove(const Comparable & x);
	
	const BinarySearchTree & operator=(const BinarySearchTree & rhs);
	
private:
	BinaryNode<Comparable>* root;
	const Comparable ITEM_NOT_FOUND;
	
	const Comparable & elementAt( BinaryNode<Comparable>* t) const;
	
	void insert( const Comparable & x, BinaryNode<Comparable>* & t) const;
	void remove (const Comparable & x, BinaryNode<Comparable>* & t) const;
	BinaryNode<Comparable>* findMax(BinaryNode<Comparable>* t) const;
	BinaryNode<Comparable>* findMin(BinaryNode<Comparable>* t) const;
	BinaryNode<Comparable>* find( const Comparable & x, BinaryNode<Comparable>* t) const;
	void makeEmpty( BinaryNode<Comparable>* & t) const;
	void printTree( BinaryNode<Comparable>* t) const;
	BinaryNode<Comparable>* clone( BinaryNode<Comparable>* t) const;
};


template<class Comparable>
const Comparable & BinarySearchTree<Comparable>::elementAt( BinaryNode<Comparable> *t) const
{
	return t == NULL ? ITEM_NOT_FOUND : t->element;
}



template<class Comparable>
const Comparable & BinarySearchTree<Comparable>::find( const Comparable & x) const
{
	return elementAt(find (x, root));
}



template <class Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::find(const Comparable & x, BinaryNode<Comparable> *t) const
{
	if (t == NULL)
		return NULL;
	else if (x<t->element)
		return find(x, t->left);
	else if (x>t->element)
		return find(x,t->right);
	else
		return t;
} 



template <class Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::findMin(BinaryNode<Comparable> *t) const
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	return findMin(t->left);
}

template <class Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::findMax(BinaryNode<Comparable> *t) const
{
	if (t == NULL)
		return NULL;
	else if (t->right == NULL)
		return t;
	return findMax(t->right);
}



template <class Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode<Comparable> * & t) const
{
	if (t == NULL)
		t = new BinaryNode<Comparable> (x, NULL, NULL);
	else if (x < t->element)
		insert(x, t->left);
	else if (x > t->element)
		insert(x, t->right);
}


template <class Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x)
{
	insert(x, root);
}


template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::findMax() const
{
	elementAt(findMax(root));
}


template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::findMin() const
{
	elementAt(findMin(root));
}


template <class Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x, BinaryNode<Comparable>* & t) const
{
	if (t == NULL)
		return;
	else if (x < t->element)
		remove(x, t->left);
	else if (x > t->element)
		remove(x, t->right);
	else if (t->right == NULL && t->left == NULL)
	{
		BinaryNode<Comparable>* temp = t;
		t = NULL;
		delete temp;
	}	
	else if (t->right == NULL)
	{
		BinaryNode<Comparable>* temp = t;
		t = t->left;
		delete temp;
	}
	else
	{
		t->element = findMin(t->right)->element;
		remove(x,t->right);
	}
}

template <class Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x)
{
	remove(x,root);
}


template <class Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
	makeEmpty();
}



template <class Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode<Comparable>* & t) const
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}


template <class Comparable>
void BinarySearchTree<Comparable>::makeEmpty() 
{
	makeEmpty(root);
}


template <class Comparable>
const BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=(const BinarySearchTree & rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

template <class Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::clone(BinaryNode<Comparable>* t) const
{
	if (t != NULL)
	{
		BinaryNode<Comparable>* newnode = new BinaryNode<Comparable>(t->element, clone(t->left), clone(t->right));
		return newnode;
		
	}
	return NULL;
}
