#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

template <class Object>
class List;

template <class Object>
class ListItr;

template <class Object>
class ListNode
{
	ListNode( const Object & theElement = Object(), ListNode * n = NULL) : element(theElement), next(n) {}
	
	Object element;
	ListNode* next;
	
	friend class List<Object>;
	friend class ListItr<Object>;
};

#endif
