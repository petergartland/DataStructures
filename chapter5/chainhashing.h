#ifndef CHAINHASHING_H
#define CHAINHASHING_H
#include <list>
#include <vector>
#include <string>

template <class HashedObj>
class HashTable
{
public:
	explicit HashTable( const HashedObj & notFound, int size = 101);
	HashTable(const HashTable & rhs) : ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND), theList(rhs.theList) {}
	
	const HashedObj & find( const HashedObj & x) const;
	void insert(const HashedObj & x);
	void remove( const HashedObj & x);
	
	const HashTable & operator=(const HashTable & rhs);
private:
	
	std::vector<std::list<HashedObj> > theList;
	const HashedObj ITEM_NOT_FOUND;
};

int hash (const std::string & key, int tableSize);
int hash (const int key, int tableSize);

template <class HashedObj>
HashTable<HashedObj>::HashTable(const HashedObj & notFound, int size) : ITEM_NOT_FOUND(notFound)
{
	theList = std::vector<std::list<HashedObj> > (size);
	//std::cout<<theList.size()<<std::endl;
}

template <class HashedObj>
const HashedObj & HashTable<HashedObj>::find(const HashedObj & x) const
{
	int index = hash(x, theList.size());
	std::list<HashedObj> checkList = theList[index];
	typename std::list<HashedObj>::iterator itr = checkList.begin();
	while (itr != checkList.end() && *itr != x)
	{
		itr++;
	}
	if (itr == checkList.end())
		return ITEM_NOT_FOUND;
	return *itr;
}

template <class HashedObj>
void HashTable<HashedObj>::insert(const HashedObj & x)
{
	//std::cout<<1<<std::endl;
	//std::cout<<theList.size()<<std::endl;
	int index = hash(x, theList.size());
	//std::cout<<2<<std::endl;
	std::list<HashedObj> checkList = theList[index];
	typename std::list<HashedObj>::iterator itr = checkList.begin();
	while (itr != checkList.end() && *itr != x)
	{
		itr++;
	}
	if (itr == checkList.end())
	{
		theList[index].push_back(x);
	}
}

int hash(const std::string & key, int tableSize)
{
	//std::cout<<3<<std::endl;
	int ret = 0;
	for (int i = 0; i < key.length(); i++)
	{
	//	std::cout<<5<<std::endl;
		ret = ret*37 + key[i]; 
	}
	//std::cout<<tableSize<<std::endl;
	ret = ret % tableSize;
	//std::cout<<7<<std::endl;
	if (ret < 0)
		ret = ret + tableSize;
	return ret;
}

/*
class test
{
public:
	int x;
	void change (const int & z)  {x=z;} 
};
*/


#endif
