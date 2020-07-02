#ifndef HEAP_H
#define HEAP_H

#include <algorithm>

template <class Comparable>
class BinaryHeap
{
public:
	explicit BinaryHeap( int size = 100);
	explicit BinaryHeap (const std::vector<Comparable> & list, int size = 100);
	
	bool isEmpty() const;
	bool isFull() const;
	const Comparable & findMin() const;
	
	void insert( const Comparable & x);
	void deleteMin();
	void deleteMin(const Comparable & minItem);
	void makeEmpty();
	

	int currentSize;
	std::vector<Comparable> array;
private:	
	void buildHeap();
	void percolateDown( int hole );
};

template <class Comparable>
BinaryHeap<Comparable>::BinaryHeap(int size) : array(size), currentSize(0)
{
	
}


template <class Comparable>
void BinaryHeap<Comparable>::insert( const Comparable& x)
{
	if(isFull())
	{
		std::cout<<"overflow"<<std::endl;
		return;
	}
	currentSize++;
	int hole = currentSize;
	for (; hole > 1 && x < array[hole/2]; hole /= 2)
	{
		array[hole] = array[hole/2];
	}
	array[hole] = x;
}

template <class Comparable>
bool BinaryHeap<Comparable>::isFull() const
{
	return currentSize == array.size();
}

template <class Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
	if (isEmpty())
	{
		std::cout<<"Underflow"<<std::endl;
		return;
	}
	//std::cout<<"deleting : " << array[1] << std::endl;
	array[1] = array[currentSize--];
	percolateDown(1);
}	

template <class Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
	int child;
	Comparable tmp = array[hole];
	
	for(; hole*2 <= currentSize; hole = child)
	{ 
		child = hole*2;
		if (child != currentSize && array[child + 1] < array[child])
			child++;
		if(array[child] < tmp)
			array[hole] = array[child];
		else
			break;
	}
	array[hole] = tmp;
}

template <class Comparable>
bool BinaryHeap<Comparable>::isEmpty() const
{
	return currentSize == 0;
}

template <class Comparable>
const Comparable & BinaryHeap<Comparable>::findMin() const
{
	return array[1];
}

template <class Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
	for (int i = currentSize/2; i > 0; i--)
		percolateDown(i);
}

template <class Comparable>
BinaryHeap<Comparable>::BinaryHeap(const std::vector<Comparable> & list, int size)
{
	currentSize = list.size()-1;
	array = list;
	buildHeap();
	insert(list[0]);
	
}
#endif
