//double hashing actually
#ifndef LINEARHASH_H
#define LINEARHASH_H
#include <string>
#include <vector>

template <class HashedObj>
class HashTable
{
public:
	explicit HashTable( const HashedObj & notFound, int size = 101);
	HashTable(const HashTable & rhs) : ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND), array(rhs.array) {}
	
	const HashedObj & find(const HashedObj & x) const;
	
	void makeEmpty();
	void insert(const HashedObj & x);
	void remove(const HashedObj & x);
	
	const HashTable & operator=(const HashTable & rhs);
	
	enum EntryType { ACTIVE, EMPTY, DELETED };
	
	int collisions;
private:
	struct HashEntry
	{
		HashedObj element;
		EntryType info;
		
		HashEntry(const HashedObj & e = HashedObj(), EntryType i = EMPTY) : element(e), info(i) {}
	};
	
	std::vector<HashEntry> array;
	int currentSize;
	const HashedObj ITEM_NOT_FOUND;
	
	bool isActive (int currentPos) const;
	int findPos(const HashedObj & x) const;
	void rehash();
};

int hash (const std::string & key, int tableSize);
int hash (const int key, int tableSize);


int hash(const std::string & key, int tableSize)
{
	//std::cout<<3<<std::endl;
	int ret = 0;
	for (int i = 0; i < key.length(); i++)
	{
	//	std::cout<<5<<std::endl;
		ret = ret*37 + key[i];
		ret = ret % tableSize; 
	}
	//std::cout<<tableSize<<std::endl;
	ret = ret % tableSize;
	//std::cout<<7<<std::endl;
	if (ret < 0)
		ret = ret + tableSize;
	return ret;
}

int hash (const int key, int tableSize)
{
	int ret = 0;
	int key2 = key;
	while (key2 > 0)
	{
		ret = (37*ret + key2%10)%tableSize;
		key2 = key2/10;
	}
	return ret;
}


template <class HashedObj>
HashTable<HashedObj>::HashTable(const HashedObj & notFound, int size) : ITEM_NOT_FOUND(notFound), array(size)
{
	makeEmpty();
	collisions = 0;
}

template <class HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
	currentSize = 0;
	for (int i = 0; i < array.size(); i++)
	{
		array[i].info = EMPTY;
	}
}

template <class HashedObj>
const HashedObj & HashTable<HashedObj>::find(const HashedObj & x) const
{
	int index = findPos(x);
	return isActive(index) ? array[index].element : ITEM_NOT_FOUND;
	
}

template <class HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj & x) const
{
	int index = hash(x, array.size());
	int i = 0;
	while(array[(index+i) % array.size()].info != EMPTY && array[(index+i) % array.size()].element != x)
	{
		i++;
	}
	return index+i % array.size();
}

template <class HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
	return array[currentPos].info == ACTIVE;
}

template <class HashedObj>
void HashTable<HashedObj>::insert(const HashedObj & x)
{

	int index1 = hash(x, array.size());
	int i = 0;
	
	while(array[(index1+i) % array.size()].info != EMPTY && array[(index1+i) % array.size()].element != x)
	{
		i++;
		collisions++;
	}
	int index = findPos(x);
	if (!isActive(index))
		array[index] = HashEntry(x,ACTIVE);
	currentSize++;
	if (currentSize >= array.size()/2)
	{
		//rehash...
	}

}

template <class HashedObj>
void HashTable<HashedObj>::remove(const HashedObj & x)
{
	int index = findPos(x);
	if(isActive(index))
		array[index].info = DELETED;
}



#endif
