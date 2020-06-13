#ifndef LINKEDLISTITR_H
#define LINKEDLISTITR_H

template <class Object>
class ListItr
{
public:
	ListItr() : current(NULL) {}
	
	bool isPastEnd() const
	{ return current == NULL; }
	
	void advance()
	{ if (!isPastEnd()); current = current->next; }
	
	const Object & retrieve() const
	{
		if (isPastEnd())
		{
			std::cout<<"error itr past end"<<std::endl;
		}
		return current->element;
	}
	
private:
	ListNode<Object> *current;
	
	ListItr (ListNode<Object> *theNode) : current(theNode) {}
	
	friend class List<Object>;
};


#endif
