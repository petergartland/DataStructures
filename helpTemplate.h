#include <iostream>

template <class Object>
class MemoryCell
{
public:
	explicit MemoryCell(const Object & value = Object()) : storedValue(value) { }
	const Object & read() const
	{return storedValue;}
	void write(const Object & value)
	{ storedValue = value;}
private:
	Object storedValue;
};
