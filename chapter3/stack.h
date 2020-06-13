#include <vector>
#include <iostream>
template<class Object>
class Stack
{
public:
	explicit Stack(int capacity = 100);
	
	bool isEmpty() const;
	bool isFull() const;
	const Object & top() const;
	
	void makeEmpty();
	void pop();
	void push(const Object & x );
	Object topAndPop();
	
private:
	std::vector<Object> theArray;
	int topOfStack;
};

template<class Object>
Stack<Object>::Stack(int capacity) : theArray(capacity)
{
	topOfStack = -1;
}

template<class Object>
bool Stack<Object>::isEmpty() const
{
	return topOfStack == -1;
}

template <class Object>
bool Stack<Object>::isFull() const
{
	return topOfStack + 1 == theArray.size();
}

template <class Object>
void Stack<Object>::makeEmpty()
{
	topOfStack = -1;
}

template <class Object>
void Stack<Object>::push(const Object & x)
{
	if (isFull())
		std::cout<<"full"<<std::endl;
	else
	{
		topOfStack++;
		theArray[topOfStack] = x;
	}
}

template <class Object>
const Object & Stack<Object>::top() const
{
	if (isEmpty())
		std::cout<<"empty"<<std::endl;
	else
		return theArray[topOfStack];
}

template <class Object>
void Stack<Object>::pop()
{
	if (isEmpty())
		std::cout<<"empty"<<std::endl;
	else
		topOfStack--;
}

template <class Object>
Object Stack<Object>::topAndPop()
{
	if(isEmpty())
		std::cout<<"empty"<<std::endl;
	else
		return theArray[topOfStack--];
}

