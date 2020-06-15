template <class Comparable>
class BinarySearchTree;

template <class Comparable>
class BinaryNode
{
	Comparable element;
	BinaryNode* left;
	BinaryNode* right;
	
	BinaryNode( const Comparable& theElement, BinaryNode* lt, BinaryNode* rt) : element(theElement), left(lt), right(rt) {}
	
friend class BinarySearchTree<Comparable>;
	
};
