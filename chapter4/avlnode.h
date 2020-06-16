template <class Comparable>
class AVLTree;

template <class Comparable>
class AVLNode
{
	Comparable element;
	AVLNode* left;
	AVLNode* right;
	int height;
	
	AVLNode(const Comparable & theElement, AVLNode* lt, AVLNode* rt, int h = 0) : element(theElement), left(lt), right(rt), height(h) {}
	
	friend class AVLTree<Comparable>;
};
