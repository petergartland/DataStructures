#ifndef INTCELLCLASS_H
#define INTCELLCLASS_H

class IntCell
{
public:
	explicit IntCell(int value = 0);
	//IntCell( int value);
	int read() const;
	void write(int value);
	~IntCell();
	IntCell(const IntCell & rhs);
	const IntCell & operator= (const IntCell & rhs);
private:
	int storedValue;	
};

#endif
