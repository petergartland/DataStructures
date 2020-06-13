#include <iostream>
#include <vector>

template <class Object>
class Queue
{
public:
	explicit Queue (int size = 100);
	
	bool isEmpty() const;
	bool isFull() const;
	const Object & getFront() const;
	
	void makeEmpty();
	Object dequeue();
	void enqueue (const Object & x);

private:
	std::vector<Object> theArray;
	int front;
	int back;
	int currentSize;
	
	void increment(int & x);
};


template <class Object>
void Queue<Object>::makeEmpty()
{
	currentSize = 0;
	front = 0;
	back = -1;
};

template <class Object>
Queue<Object>::Queue(int size) : theArray(size)
{
	makeEmpty();
}


template <class Object>
bool Queue<Object>::isEmpty() const
{
	return currentSize == 0;
}

template <class Object>
bool Queue<Object>::isFull() const
{
	return currentSize == theArray.size();
}

template <class Object>
void Queue<Object>::enqueue(const Object & x)
{

	if (isFull())
	{
		std::cout<<"full"<<std::endl;
		return;
	}
	else
	{
		back++;
		back = back % theArray.size();
		theArray[back] = x;
		currentSize++;
	}

}

template <class Object>
const Object & Queue<Object>::getFront() const
{
	return theArray[front];
}

template <class Object>
Object Queue<Object>::dequeue()
{
	Object ret = theArray[front]; 
	if (front == theArray.size())
		front = 0;
	else
		front++;
	return ret;
}


