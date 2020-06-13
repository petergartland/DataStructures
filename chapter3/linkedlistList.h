#ifndef LINKEDLISTLIST_H
#define LINKEDLISTLIST_H

#include <iostream>
//template<class Object>
//class ListItr;


template <class Object>
class List
{
public:
	List();
	List(const List & rhs);
	~List();
	
	bool isEmpty() const;
	void makeEmpty();
	ListItr<Object> zeroth() const;
	ListItr<Object> first() const;
	void insert( const Object & x, const ListItr<Object> & p);
	ListItr<Object> find( const Object & x) const;
	ListItr<Object> findPrevious( const Object & x) const;
	void remove(const Object & x);
	void swap (const Object & x);
	List intersect(const List & rhs) const;
	void cutNPaste(ListItr<Object> start, ListItr<Object> end, List<Object> & rhs, ListItr<Object> paste);
	
	
	const List & operator=( const List & rhs);
	
private:
	ListNode<Object> *header;
};


template<class Object>
List<Object>::List()
{
	header = new ListNode<Object>;
}

template<class Object>
bool List<Object>::isEmpty() const
{
	return header->next == NULL;
}

template<class Object>
ListItr<Object> List<Object>::zeroth() const
{
	return ListItr<Object>(header);
}

template<class Object>
ListItr<Object> List<Object>::first() const
{
	return ListItr<Object>(header->next);
}

template <class Object>
void printList(const List<Object> & list)
{
	if(list.isEmpty())
		std::cout<<"list is empty"<<std::endl;
	else
	{
		ListItr<Object> itr = list.first();
		while( !itr.isPastEnd())
		{
			std::cout<<itr.retrieve()<<std::endl;
			itr.advance();
		}
	}
}


template <class Object>
ListItr<Object> List<Object>::find(const Object & x) const
{
	ListNode<Object>* itr= header->next;
	while (itr!=NULL && itr->element != x)
	{
		itr = itr->next;
	}
	return ListItr<Object>(itr);
}


template<class Object>
ListItr<Object> List<Object>::findPrevious(const Object & x) const
{
	ListNode<Object>* p = header;
	while (p->next != NULL && p->next->element != x)
	{
		p = p->next;
	}
	return ListItr<Object>(p);
}


template <class Object>
void List<Object>::remove( const Object & x)
{
	ListItr<Object> p = findPrevious(x);
	if (p.current->next != NULL)
	{
		ListNode<Object> *oldnode = p.current->next;
		p.current->next = p.current->next->next;
		delete oldnode;
	}
}


template <class Object>
void List<Object>::insert(const Object & x, const ListItr<Object> & itr)
{
	if (itr.current != NULL)
	{
		itr.current->next = new ListNode<Object>(x, itr.current->next);
	}
}

template <class Object>
void List<Object>::makeEmpty()
{
	while(!isEmpty())
	{
		remove(first().retrieve());
	}
}

template<class Object>
List<Object>::~List()
{
	makeEmpty();
	delete header;
}	


template<class Object>
const List<Object> & List<Object>::operator=(const List & rhs)
{
	if (this == &rhs)
		return *this;

	else
	{
		makeEmpty();
		ListItr<Object> itr = rhs.first();
		ListItr<Object> thisItr = zeroth();
		while (!itr.isPastEnd())
		{
			insert(itr.retrieve(), thisItr);
			itr.advance();
			thisItr.advance();
		}	
	} 
	return *this;
}

template <class Object>
void List<Object>::swap(const Object & x)
{
	ListItr<Object> itr = findPrevious(x);
	ListItr<Object> itr2 = itr.current->next;
	if (itr2.current->next == NULL)
	{
		std::cout<<"cannot swap last element!"<<std::endl;
		return;
	}
	itr.current->next = itr2.current->next;
	itr2.current->next = itr2.current->next->next;
	itr.current->next->next = itr2.current;
}

template<class Object>
List<Object> List<Object>::intersect(const List & rhs) const
{
	List<Object> ret;
	ListItr<Object> itr = rhs.first();
	while (!itr.isPastEnd())
	{
		ListItr<Object> itr2 = find(itr.retrieve());
		if (!itr2.isPastEnd())
			ret.insert(itr2.retrieve(),ret.zeroth());
		itr.advance();
	}
	return ret;
} 

template <class Object>
void cutAndPaste(List<Object> & cut, ListItr<Object> start, ListItr<Object> end, List<Object> & paste, ListItr<Object> insert)
{
	Object past = start.retrieve();
	end.advance();
	while (start.retrieve() != end.retrieve())
	{
		paste.insert(start.retrieve(), insert);
		insert.advance();
		start.advance();
		cut.remove(past);
		past = start.retrieve();
	} 
}

template <class Object>
void List<Object>::cutNPaste(ListItr<Object> start, ListItr<Object> end, List<Object> & rhs, ListItr<Object> paste)
{
	ListNode<Object>* temp = start.current->next;
	start.current->next = end.current->next;
	end.current->next = paste.current->next;
	paste.current->next = temp;
	
}

#endif
