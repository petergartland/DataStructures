template <class Comparable>
class AVLTree
{
public: 
	void insert( const Comparable & t);
	const AVLNode<Comparable> & findMax() const;
	const AVLNode<Comparable> & findMin() const;
	const AVLNode<Comparable> & find(const Comparable & x) const;
	
private:
	AVLNode<Comparable>* root;
	
	void insert(const Comparable & x, const AVLNode<Comparable>* & t) const;
	const AVLNode<Comparable> & find (const Comparable & x, AVLNode<Comparable>* & t);
	void rotateWithRightChild (AVLNode<Comparable>* & t);
	void rotateWithLeftChild (AVLNode<Comparable>* & t);
	
	Comparable elementAt(const AVLNode<Comparable> & t);
	
};


